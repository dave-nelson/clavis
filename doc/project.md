Project
=======

With Clavis, there is a separation between the project-specific code -- for a 
particular model of keyboard -- and the common code that is used across all 
projects.


New project
-----------

You will want to start a new project if you want to write support for a 
keyboard.  The easiest way to get started is to use an existing project.

 1. Copy one of the existing project directories (such as "keypad"), giving it 
    a new name.
 1. Add the name of your project's directory to the top-level Makefile.
 1. Edit the files in the project directory.

The project files are described below, including how they can be edited.


Project parameters
------------------

The project header file "project.h" sets some basic parameters that apply for 
the project.  These include:

 * The number of ports (NUM_PORTS).  This is the total number of ports (i.e. 
  registers, *not pins*) on the Teensy that will be used for the project.  
  This is used during the initial configuration of the device, to set the 
  ports for input and output, for the matrix and (optionally) any indicator 
  LEDs.

 * The number of columns (NUM_COLS) and rows (NUM_ROWS) in the keyboard matrix.
 
 * The number of LEDs (NUM_LEDS) to be supported for indicators (Num Lock, Caps 
  Lock etc.)
 
 * The column pin delay, in microseconds (PIN_DELAY_USEC).  During the matrix 
  scan, each column is activated in turn.  After turning on the column, it is 
  necessary to wait a short amount of time before reading the rows, otherwise 
  none of the rows will show as active.  This delay needs to be long enough 
  for the circuit to respond to the column becoming active, and needs to take 
  into account the response time of any diodes on the circuit.
 
 * The delay between polls of the matrix (POLL_DELAY_USEC).  After performing a 
  scan of the matrix (and possibly sending any changed keys to the host) the 
  main method will delay before looping again.  Having a short but adequate 
  delay between polls gives the keys time to debounce.

 * Whether ghosts should be blocked or not (DE_GHOST).  If true, the matrix 
  will be checked for possible ghosting whenever the keys have changed.  If 
  the combination of keys indicates that ghosting is occurring, the 
  transmission of keys to the host will be blocked.  De-ghosting/blocking 
  should be enabled for 2KRO (two-key rollover) keyboards: where there are no 
  diodes between the columns and rows to prevent the back-flow of current.


Project configuration
---------------------

Having first set the parameters for the project in the "project.h" file (as 
above) it is necessary to provide more detailed configuration for the project: 
the ports and key matrix etc.  This is done in the "project.c" file.  The 
configuration variables that need to be set are as follows:

 * *ports:* The ports in use on the microcontroller, as defined by NUM_PORTS 
  (above), will need to be configured.  This is done on a per-pin basis using 
  a bit mask.  The *direction* (DDRx) needs to be set for each pin, for input 
  (1) or output (0).  The *parameters* (PORTx) need to be set for each pin 
  depending on whether it is an input or an output.  If input, pullup 
  resistors should be enabled (1).  The signal output pins, given that they 
  are to be connected to pulled down input pins, should be configured high (1) 
  if in use.  The LED output pins should be set low (0).

 * *columns:* All the column ports and pins (which were previously configured 
  as output/high (1/1) as above) will need to be listed in order.

 * *rows:* Similarly to the columns, all the row ports and pins will need to be 
  listed in order.

 * *matrix:* This is the key part of the implementation.  The matrix consists 
  of a flattened array (one dimensional, size of (rows x columns)) containing 
  specifications for each key.  Keys are listed in order, first across rows 
  then down columns.  The "Key" struct (defined in common/matrix.h) contains a 
  number of fields, but here the first two are of interest.  The first field 
  should be the standard USB HID code for the key, or 0 if it is a modifier.  
  The second field is the standard USB HID modifier code for the key; this can 
  be omitted if the key is not a modifier.

 * *samples_mask:*  This relates to debouncing.  It is a mask that determines 
  the number of successive key samples that constitute a stable key state.  
  For example, if you would like the matrix scanner to take four samples of 
  each key before calling it stable, set this value to binary 00001111 = 0x0f 
  (four significant bits means four samples).  Naturally this allows for up to 
  8 samples to be taken of each key before it deemed to be stable: all 
  significant bits either on or off.

 * *Matrix_hack:* A C function pointer you can provide, to modify the matrix or 
  the current selection of keys before it is sent to the host.  Typically this 
  function will modify the variables "matrix" or "selection", as declared in 
  the header common/matrix.h.  The function must return either true or false, 
  indicating whether the selected keys will be sent to the host.

Build configuration
-------------------

If you are starting a keyboard project by copying some existing project, you 
may not need to change anything in the Makefile.  You might only want to make 
changes under these circumstances:

 * Change the value for "MCU" if you are using a different type of Teensy to 
  the original project.

 * Change the value of "SRC" if you add any additional source files for your 
  project.

To make your project build from the top-level directory, edit its Makefile and 
add the directory of your project to "SUBDIRS". 
