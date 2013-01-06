clavis
======

*Customisable keyboard firmware for Teensy USB*


Clavis is a system for writing customisable firmware for legacy keyboards that 
is intended to be as easy to use as possible.

The Clavis project is organised such that the files you need to provide are 
placed in a *project* directory.  Each project is an implementation of firmware 
for a legacy (or controllerless) keyboard.  You set the parameters and define 
the matrix for the keyboard you want to convert to USB.  The Clavis common 
files contain the code to implement the USB keyboard part of the project -- you 
don't necessarily need to edit those.

This separation between your project's files and the common code makes it clear 
what information needs to be customised for your legacy keyboards.

Using Clavis involves the following steps:

 1. Analyse the matrix of the keyboard in question.
 1. Decide how to layout the columns/outputs and rows/inputs on the pins of a 
    Teensy microcontroller, and optionally decide which pins should be used for 
    indicator LEDs (Num Lock/Caps Lock/Scroll Lock).
 1. Create a Clavis project with these settings for the keyboard.
 1. Prepare the keyboard hardware by disabling/removing the controller chip and 
    wiring the Teensy in its place, with the inputs and outputs wired as 
    decided above.
 1. Build the firmware and flash it onto the keyboard's Teensy.

Getting started
---------------

You will need an [avr-gcc](http://www.nongnu.org/avr-libc/) build environment, 
C programming ability, some understanding of AVR programming with the Teensy, a 
basic knowledge of electronic circuits, various tools and parts, and of course 
a legacy keyboard to be converted.

It is highly recommended that you go through the Getting Started, How-To Tips 
and Reference on [PJRC's Teensy web 
site](http://www.pjrc.com/teensy/index.html).  You should also consider 
experimenting with a breadboard before committing your final project to solder.

Have a look at the projects that are already provided by Clavis.  (The *keypad* 
project might be a good place to start because it is small and simple.)


License
-------

All original material in this project is Copyright 2013 David Robert Nelson, 
all rights reserved.  You may distribute the original code under the terms of 
the GNU General Public License (GPL), version 3 or greater at your option.

Material from third parties is distributed here under the authors' original 
terms and conditions.  In those cases, the terms are clearly shown at the top 
of the source files.

