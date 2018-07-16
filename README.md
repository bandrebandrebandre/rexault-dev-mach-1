# Bespoke Digital Pet Development Kit Mach 1

<pre>


                                         (                                   (                
   (                           )         )\ )                   )       (    )\ )          )  
 ( )\    (                  ( /(    (   (()/(  (   (  (  (   ( /(    )  )\  (()/(   (   ( /(  
 )((_)  ))\ (   `  )    (   )\())  ))\   /(_)) )\  )\))( )\  )\())( /( ((_)  /(_)) ))\  )\()) 
((_)_  /((_))\  /(/(    )\ ((_)\  /((_) (_))_ ((_)((_))\((_)(_))/ )(_)) _   (_))  /((_)(_))/  
 | _ )(_)) ((_)((_)_\  ((_)| |(_)(_))    |   \ (_) (()(_)(_)| |_ ((_)_ | |  | _ \(_))  | |_   
 | _ \/ -_)(_-<| '_ \)/ _ \| / / / -_)   | |) || |/ _` | | ||  _|/ _` || |  |  _// -_) |  _|  
 |___/\___|/__/| .__/ \___/|_\_\ \___|   |___/ |_|\__, | |_| \__|\__,_||_|  |_|  \___|  \__|  
               |_|                                |___/                                       
 (                                                                     )            
 )\ )                    (                                     )    ( /(         )  
(()/(     (    )      (  )\                )      (         ( /(    )\()) (   ( /(  
 /(_))   ))\  /((    ))\((_) (   `  )     (      ))\  (     )\()) |((_)\  )\  )\()) 
(_))_   /((_)(_))\  /((_)_   )\  /(/(     )\  ' /((_) )\ ) (_))/  |_ ((_)((_)(_))/  
 |   \ (_))  _)((_)(_)) | | ((_)((_)_\  _((_)) (_))  _(_/( | |_   | |/ /  (_)| |_   
 | |) |/ -_) \ V / / -_)| |/ _ \| '_ \)| '  \()/ -_)| ' \))|  _|    ' <   | ||  _|  
 |___/ \___|  \_/  \___||_|\___/| .__/ |_|_|_| \___||_||_|  \__|   _|\_\  |_| \__|  
                                |_|                                                 
   *                          )                
 (  `                  )   ( /(                
 )\))(      )       ( /(   )\())           (   
((_)()\  ( /(   (   )\()) ((_)\    (      ))\  
(_()((_) )(_))  )\ ((_)\    ((_)   )\ )  /((_) 
|  \/  |((_)_  ((_)| |(_)  / _ \  _(_/( (_))   
| |\/| |/ _` |/ _| | ' \  | (_) || ' \))/ -_)  
|_|  |_|\__,_|\__| |_||_|  \___/ |_||_| \___|  
                                               
</pre>                                                                                                                                                                                       


Psst, hey kid. Welcome to the mach 1 development kit. This here repository contains software that accompanies a unit with a 
200 x 200 pixel ePaper display. If you try to use this software with a different dev unit, things may not go according to plan.

The display for this unit is 1 inch x 1 inch. We like to keep things nice and simple around here. See?

Who am I you ask? Don't worry about that just yet. This place is complicated, and you're new here. Best take it one step at
a time. There's a lot going on beneath the surface. See? Think of my as your friendly uncle Cleef.

## Install this here chickerieboo

If you want to install this here chickerieboo, you'll have to install git and the Arduino IDE 
(https://www.arduino.cc/en/guide/macOSX)

Once that's done, clone away.

    $ cd ~
    $ git clone https://github.com/bandrebandrebandre/rexault-dev-mach-1.git

## Run the demo on the arduino

Get your hardware unit and connect it to your computer with the USB cable. Then open the rexault-dev-mach-1.ino file in the 
Arduino IDE.

Click Tools --> Port --> ArduinoMKRZero in the Arduino IDE.

Click the Upload button to load the demo onto your arduino. Try pressing the buttons on the unit to play around a little bit.
F-U-N.

## Making images for the mach 1

You can use the Rexault Luxury Converter (https://github.com/bandrebandrebandre/rexault-luxury-converter) to turn image files 
into a format that is readable by the display.

For now the way to go is probably to create 200 x 200 pngs on piskelapp.com, then to convert them luxuriously by using the 
hexify option (so named because it converts the image to an array of hex values). Then you drag the .cpp and .h files into 
this directory, import the .h file into your .ino file, and then reference the images as is done in the demo.

You can also draw shapes using the somewhat terrible 'paint' functions. There are examples of this, as well as using the font
files in the demo.

In general, it isn't a bad idea to run workflow ideas by your project coordinator before going too far down a given path.

## Don't get too comfortable with the mach 1

There is a strong likelihood that the display will change in the next iteration, and it will probably have greyscale as well
as a different pixel density. Don't spend any work optimizing your images or polishing in any way, as that work will
probably be wasted. 

Also don't worry if your games have time based problems such as animations loading too slow, or inconsistent gaps, etc.
The next version may use a differently clocked processor, and the display may have different refresh times. There will
also probably be an official Rexault Luxury System Task Manager that will make sure all your little system actions execute 
when they're supposed to.

The final version of the unit will have 1 MB program memory on the microcontroller and an additional 10MB (or more)
on a secondary flash chip. The mkrzero arduino only has 256KB in total.

Think of the mach 1 as the way to get started playing around with frame buffers, IoT, and ePaper. You probably shouldn't create
a full game on one of these, unless you are a real skalliwag of a game dev.

## Flaming ASCII Art

And yes, I know the ASCII art is on fire. It's supposed to be that way. We do things a certain way around here. *hair singes
slightly*
