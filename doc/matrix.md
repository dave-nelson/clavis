Matrix analysis
===============

In order to implement a controller for a keyboard, it is necessary to analyse 
the keyboard's matrix.


Matrices -- an overview
-----------------------

It would be possible to implement a keyboard by connecting each pin of 
every key to pins on the microcontroller.  This would of course require a 
controller with a large number of pins.  Matrices are a way to implement an 
electronic device with many switches, using a minimal number of pins.  The pins 
are divided up into columns and rows, which allows the controller to support a 
number of switches equal to (rows x columns).

The controller detects which keys are active by polling the matrix.  Each 
column (output) is powered in turn, and each row (input) is read.  If a signal 
is read on the row, it means the switch for that row and the currently-powered 
column is closed.

After polling the matrix and determining if the state of any keys has changed, 
the controller can send the current state of the keys to the host.

Analysing a matrix
------------------

Analysing a matrix involves making a record of the two controller pins to which 
each key is connected.  One of those pins will be a column pin and the other a 
row (although at first it may not be obvious which is which -- more on that 
below).  This can be done easily with a multimeter that features continuity 
checking.

There are two approaches you can use.

 1. Direct to pin.  If the switch pins are exposed, you can touch each 
    with one multimeter probe and swipe the other probe across all the 
    controller pins.
 2. Indirectly, from key.  If the switch pins are not exposed (e.g. a 
    membrane keyboard) you may have to find the two pins for each key by 
    pressing down/closing the key, then using your multimeter to see which two 
    controller pins form a closed circuit.  This is slightly more cumbersome, 
    because you have to hold each key down while fiddling with your multimeter.

Tabulate the results of each key test in a two-dimensional grid.  A spreadsheet 
is ideal for the task.


Columns and rows
----------------

After analysing the matrix, a clear pattern should have emerged.  Each set of 
entries should fall into two groups by size.  For example, you might find that 
for some of the pins there are 8 keys, while for others there are 13.  This 
indicates your division into rows and columns.

If the matrix is square (all sets of keys the same size, e.g. 12 x 12) then 
dividing into rows and columns is a bit less obvious -- which sets are rows, 
and which are columns?  It is helpful to remember that the sets must be 
exclusive: each key can be associated with exactly one row and one column.  So 
you can divide the sets of keys into two groups such that they are mutually 
exclusive.

After performing the analysis, which are the *rows* and which are the 
*columns*?  You may be able to tell this from the wiring of the PCB.  What we 
call the "columns" are the outputs, so if the PCB has diodes these must allow 
current to flow *from* the controller column pins *to* the controller row pins.  
If the keyboard lacks diodes, then the choice of columns versus rows is 
arbitrary.

