  /**
 *  @filename   :   epd1in54-demo.ino
 *  @brief      :   1.54inch e-paper display demo
 *  @author     :   Yehui from Waveshare
 *
 *  Copyright (C) Waveshare     September 5 2017
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documnetation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to  whom the Software is
 * furished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS OR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include <SPI.h>
#include "epd1in54.h"
#include "epdpaint.h"
#include "imagedata.h"

#include "sparkleA.h"
#include "sparkleB.h"
#include "sparkleC.h"
#include "sparkleD.h"
#include "felix.h"


#define COLORED     0
#define UNCOLORED   1

/**
  * Due to RAM not enough in Arduino UNO, a frame buffer is not allowed.
  * In this case, a smaller image buffer is allocated and you have to 
  * update a partial display several times.
  * 1 byte = 8 pixels, therefore you have to set 8*N pixels at a time.
  */
unsigned char image[1024];
Paint paint(image, 0, 0);    // width should be the multiple of 8 
Epd epd;
unsigned long time_start_ms;
unsigned long time_now_s;
int pitch;

int sparkle_x = 0;  // (0, 0) is the top left corner. Starting point of sparkle.
int sparkle_y = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  if (epd.Init(lut_full_update) != 0) {
      Serial.print("e-Paper init failed");
      return;
  }
  

  /** 
   *  there are 2 memory areas embedded in the e-paper display
   *  and once the display is refreshed, the memory area will be auto-toggled,
   *  i.e. the next action of SetFrameMemory will set the other memory area
   *  therefore you have to clear the frame memory twice.
   */
  epd.ClearFrameMemory(0xFF);   // bit set = white, bit reset = black
  epd.DisplayFrame();
  epd.ClearFrameMemory(0xFF);   // bit set = white, bit reset = black
  epd.DisplayFrame();

  paint.SetRotate(ROTATE_0);
  paint.SetWidth(200);
  paint.SetHeight(24);

  /* For simplicity, the arguments are explicit numerical coordinates */
  paint.Clear(COLORED);
  paint.DrawStringAt(30, 4, "Hello-~-~-~-", &Font16, UNCOLORED);
  epd.SetFrameMemory(paint.GetImage(), 0, 10, paint.GetWidth(), paint.GetHeight());
  
  paint.Clear(UNCOLORED);
  paint.DrawStringAt(30, 4, "Cruel World!", &Font16, COLORED);
  epd.SetFrameMemory(paint.GetImage(), 0, 30, paint.GetWidth(), paint.GetHeight());

  paint.SetWidth(64);
  paint.SetHeight(64);
  
  paint.Clear(UNCOLORED);
  paint.DrawRectangle(0, 0, 40, 50, COLORED);
  paint.DrawLine(0, 0, 40, 50, COLORED);
  paint.DrawLine(40, 0, 0, 50, COLORED);
  epd.SetFrameMemory(paint.GetImage(), 16, 60, paint.GetWidth(), paint.GetHeight());

  paint.Clear(UNCOLORED);
  paint.DrawCircle(32, 32, 30, COLORED);
  epd.SetFrameMemory(paint.GetImage(), 120, 60, paint.GetWidth(), paint.GetHeight());

  paint.Clear(UNCOLORED);
  paint.DrawFilledRectangle(0, 0, 40, 50, COLORED);
  epd.SetFrameMemory(paint.GetImage(), 16, 130, paint.GetWidth(), paint.GetHeight());

  paint.Clear(UNCOLORED);
  paint.DrawFilledCircle(32, 32, 30, COLORED);
  epd.SetFrameMemory(paint.GetImage(), 120, 130, paint.GetWidth(), paint.GetHeight());
  epd.DisplayFrame();

  delay(3000);

  if (epd.Init(lut_partial_update) != 0) {
      Serial.print("e-Paper init failed");
      return;
  }

  /** 
   *  there are 2 memory areas embedded in the e-paper display
   *  and once the display is refreshed, the memory area will be auto-toggled,
   *  i.e. the next action of SetFrameMemory will set the other memory area
   *  therefore you have to set the frame memory and refresh the display twice.
   */
  epd.SetFrameMemory(felix);
  epd.DisplayFrame();
  epd.SetFrameMemory(felix);
  epd.DisplayFrame();
  
  pinMode(A1, INPUT_PULLUP);          // initialize buttons
  pinMode(A4, INPUT_PULLUP);
  pinMode(A5, INPUT_PULLUP);
  pinMode(A6, INPUT_PULLUP);
  pitch = 1;

  
}

void pollButtons() {

  if (!digitalRead(A1)) { 
    Serial.println("Right Button Pressed."); // View these in Tools --> serial monitor
    if (sparkle_x < 199) {    //make sure we don't pass the right border of the display
        sparkle_x += 8;      // if it gets pressed, move the coordinate to the right.
    }
  }

  if (!digitalRead(A4)) { 
    Serial.println("Bottom Button Pressed."); 
    if (sparkle_y < 199) {
        sparkle_y += 8;
    } 
  }

  if (!digitalRead(A5)) {
    Serial.println("Left Button Pressed."); 
    if (sparkle_x > 0) {
      sparkle_x -= 8;
    }
  }

  if (!digitalRead(A6)) { 
    Serial.println("Top Button Pressed."); 
    if (sparkle_y > 0) {
      sparkle_y -= 8; 
    }
  }
}


void loop() {
  // put your main code here, to run repeatedly:

  pollButtons();

  epd.SetFrameMemory(
    sparkleA,     // first frame of an animation sequence of 4
    sparkle_x,    // continuously updated x coordinate (from buttons)
    sparkle_y,    // continuously updated y coordinate (from buttons)
    8,            // width of sprite is 7, but we round up to nearest multiple of 8
    8);           // height of sprite is 7, but we round up to nearest multiple of 8

  epd.DisplayFrame(); // send frame array to display

  pollButtons();

  epd.SetFrameMemory(
    sparkleB,     // second frame
    sparkle_x,    
    sparkle_y,    
    8,            
    8);
               
  epd.DisplayFrame();

  pollButtons();

  epd.SetFrameMemory(
    sparkleC,     // third frame
    sparkle_x,    
    sparkle_y,    
    8,            
    8);           
  epd.DisplayFrame();

  pollButtons();

  epd.SetFrameMemory(
    sparkleD,     // forth frame
    sparkle_x,    
    sparkle_y,   
    8,            
    8);           
    
  epd.DisplayFrame();




 

   
/*  pitch++;
  analogWrite(A3, pitch);
  Serial.print(pitch);
  if (pitch == 255){
    pitch = 0; 
  }*/
}

