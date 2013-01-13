#include "project.h"
#include "../../common/matrix.h"

/**
 * Based on the settings in project.h, initialise all the statics declared by matrix.h.
 */

Port ports[NUM_PORTS] = {
    /* Inputs, pullup resistors */
    { &DDRB, 0x00, &PORTB, 0xff },
    /* Output, high */
    { &DDRF, 0xff, &PORTF, 0xff },
};

Pin columns[NUM_COLS] = {
    { &PORTF, DDF0 },
    { &PORTF, DDF1 },
    { &PORTF, DDF4 },
};

Pin rows[NUM_ROWS] = {
        { &PINB, PINB0 }, 
        { &PINB, PINB1 }, 
        { &PINB, PINB2 }, 
        { &PINB, PINB3 },
};

/**
 * The matrix is laid out as a one-dimensional array of keys, going across the 
 * rows and down the columns.
 */
Key matrix[NUM_COLS * NUM_ROWS] = {

    { KEYPAD_1, }, { KEYPAD_2, }, { KEYPAD_3, },
    { KEYPAD_4, }, { KEYPAD_5, }, { KEYPAD_6, }, 
    { KEYPAD_7, }, { KEYPAD_8, }, { KEYPAD_9, }, 
    { KEYPAD_ASTERIX, }, { KEYPAD_0, },{ KEYPAD_PERIOD, },

};

/**
 * No matrix hacks required for this project.
 */
bool (* Matrix_hack) (void) = 0;

