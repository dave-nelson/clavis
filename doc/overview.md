Overview
========

Clavis is a system for writing customisable firmware for legacy keyboards that 
is intended to be as easy to use as possible.

Using Clavis involves the following steps:

 1. Analyse the matrix of the keyboard in question.
 1. Decide how to layout the columns/outputs and rows/inputs on the pins of a 
   Teensy microcontroller, and optionally decide which pins should be used for 
   indicator LEDs (Num Lock/Caps Lock/Scroll Lock).
 1. Create a Clavis project with these settings for the keyboard.
 1. Prepare the keyboard hardware by disabling/removing the controller chip and 
   wiring the Teensy in its place, with the inputs and outputs wired as decided 
   above.
 1. Build the firmware and flash it onto the keyboard's Teensy.

Getting started
---------------

You will need an [avr-gcc](http://www.nongnu.org/avr-libc/) build environment, 
some understanding of AVR programming with the Teensy, a basic knowledge of 
electronic circuits, various tools and parts, and of course a legacy keyboard 
to be converted.

It is highly recommended that you go through the Getting Started, How-To Tips 
and Reference on [PJRC's Teensy web 
site](http://www.pjrc.com/teensy/index.html).  You should also consider 
experimenting with a breadboard before committing your final project to solder.
