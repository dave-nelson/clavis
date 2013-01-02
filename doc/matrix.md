Matrix analysis
===============

In order to implement a controller for a keyboard, it is necessary to analyse the keyboard's matrix.


Matrices -- an overview
-----------------------

It would be possible to implement a keyboard by connecting each terminal of every key to pins on the microcontroller.  This would of course require a controller with a large number of pins.  Matrices are a way to implement an electronic device with many switches, using a minimal number of pins.  The pins are divided up into columns and rows, which allows the controller to support a number of switches equal to (rows x columns).

The controller detects which keys are active by polling the matrix.  Each column (output) is powered in turn, and each row (input) is read.  If a signal is read on the row, it means the switch for that row and the currently-powered column is closed.

After polling the matrix and determining if the state of any keys has changed, the controller can send the current state of the keys to the host.

Analysing a matrix
------------------

Analysing a matrix involves making a record of the two controller pins to which each key is connected.  One of those pins will be a column pin and the other a row (although at first it may not be obvious which is which -- more on that below).  This can be done easily with a multimeter that features continuity checking.

There are two approaches you can use.

 1. Direct to pin.  If the switch terminals are exposed, you can touch each with one multimeter probe and swipe the other probe across allthe controller pins.
 2. Indirectly, from key.  If the switch terminals are not exposed (e.g. a membrane keyboard) you may have to find the two pins for each key by pressing down/closing the key, then using your multimeter to see which two pins form a closed circuit.  This is slightly more cumbersome, because you have to hold each key down while fiddling with your multimeter.

Tabulate the results of each key test in a two-dimensional grid.  A spreadsheet is ideal for the task.



