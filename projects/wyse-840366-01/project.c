/*
 * Copyright 2013 David Robert Nelson.
 *
 * This file is part of Clavis.
 *
 * Clavis is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Clavis is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Clavis.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "project.h"
#include "../../common/matrix.h"
#include "../../common/led.h"

/**
 * Based on the settings in project.h, initialise all the statics declared by matrix.h.
 */

Port ports[NUM_PORTS] = {
    /* Inputs, pullup resistors */
    { &DDRD, 0x00, &PORTD, ~(1 << PIND6) }, /* Not D6: internal LED */
    { &DDRF, 0x00, &PORTF, 0xff },
    /* Output, high */
    { &DDRB, 0xff, &PORTB, 0xff },
    /* LEDs */
    { &DDRC, 0xff, &PORTC, 0x00 },
    { &DDRE, 0xff, &PORTE, 0x00 },
};

Pin columns[NUM_COLS] = {
    /* TI CF60137N pins 1-8 */
    { &PORTB, PINB0 },
    { &PORTB, PINB1 },
    { &PORTB, PINB2 },
    { &PORTB, PINB3 },
    { &PORTB, PINB4 },
    { &PORTB, PINB5 },
    { &PORTB, PINB6 },
    { &PORTB, PINB7 },
};

Pin rows[NUM_ROWS] = {
    /* 9-16 */
    { &PIND, PIND0 },
    { &PIND, PIND1 },
    { &PIND, PIND2 },
    { &PIND, PIND3 },
    { &PIND, PIND4 },
    { &PIND, PIND5 },
    { &PIND, PIND7 },
    { &PINF, PINF0 },
    /* 17 is ground */

    /* 24-28 */
    { &PINF, PINF1 },
    { &PINF, PINF4 },
    { &PINF, PINF5 },
    { &PINF, PINF6 },
    { &PINF, PINF7 },
};

Key matrix[NUM_ROWS * NUM_COLS] = {
    /* Row 0 (pin 9 on the TI CF60137N) */
    { KEYPAD_0, }, 
    { KEYPAD_4, }, 
    { KEY_NUM_LOCK, },  /* "PF1" */
    { 0x00, },  /* "<>" */ 
    { KEY_8, }, 
    { KEY_TAB, }, 
    { KEY_ENTER, }, 
    { KEY_F1, }, 

    /* 1 (pin 10) */
    { KEYPAD_PERIOD, }, 
    { KEYPAD_5, }, 
    { KEYPAD_SLASH, },  /* "PF2" */ 
    { KEY_Z, }, 
    { KEY_9, }, 
    { KEY_R, }, 
    { KEY_QUOTE, }, 
    { KEY_F2, }, 

    /* 2 (pin 11) */
    { KEY_UP, }, 
    { KEYPAD_6, }, 
    { KEYPAD_ASTERIX, },  /* "PF3" */
    { KEY_C, }, 
    { KEY_0, }, 
    { KEY_W, }, 
    { KEY_BACKSLASH, }, 
    { KEY_F3, }, 

    /* 3 (pin 12) */
    { KEY_DOWN, }, 
    { KEYPAD_1, }, 
    { KEYPAD_MINUS, },  /* "PF4" */
    { KEY_X, }, 
    { KEY_MINUS, }, 
    { KEY_E, }, 
    { KEY_SEMICOLON, }, 
    { KEY_F4, }, 

    /* 4 (pin 13) */
    { KEY_LEFT, }, 
    { KEYPAD_2, }, 
    { KEYPAD_7, }, 
    { KEY_V, }, 
    { KEY_EQUAL, }, 
    { KEY_Q, }, 
    { KEY_SPACE, }, 
    { KEY_F5, }, 

    /* 5 (pin 14) */
    { KEY_SCROLL_LOCK, }, 
    { KEY_PRINTSCREEN, }, 
    { 0x00, }, /* "F17" */ 
    { KEY_ESC, },  /* Wyse "Do" */
    { 0x00, KEY_RIGHT_GUI },  /* Wyse "Help" */
    { 0x00, },  /* "F14" */ 
    { 0x00, },  /* "F13" */
    { 0x00, KEY_ALT},  /* Wyse "Compose Character" */

    /* 6 (pin 15) */
    { KEY_RIGHT, }, 
    { KEY_RIGHT_BRACE, }, 
    { KEY_LEFT_BRACE, }, 
    { KEY_BACKSPACE, }, 
    { KEY_P, }, 
    { KEY_INSERT, }, 
    { 0x00, KEY_CTRL }, 
    { KEY_F7, }, 

    /* 7 (pin 16) */
    { KEY_L, }, 
    { KEY_K, }, 
    { KEY_J, }, 
    { 0x00, KEY_SHIFT, }, 
    { KEY_H, },
    { KEY_G, },
    { KEY_PAUSE, },
    { KEY_F6, }, 

    /* 8 (pin 24) */
    { KEY_HOME, }, 
    { KEYPAD_3, }, 
    { KEYPAD_9, }, 
    { KEY_M, }, 
    { KEY_3, }, 
    { KEY_O, }, 
    { KEY_D, }, 
    { KEY_F12, }, 

    /* 9 (pin 25) */
    { KEYPAD_ENTER, }, 
    { KEY_PAGE_DOWN, }, 
    { KEYPAD_8, }, 
    { KEY_B, }, 
    { KEY_2, }, 
    { KEY_I, }, 
    { KEY_F, }, 
    { KEY_F11, }, 

    /* 10 (pin 26) */
    { KEYPAD_PLUS, },  /* Numberpad "," */
    { KEYPAD_PLUS, }, 
    { KEY_PAGE_UP, }, 
    { KEY_N, }, 
    { KEY_1, }, 
    { KEY_U, }, 
    { KEY_S, }, 
    { KEY_F10, }, 

    /* 11 (pin 27) */
    { KEY_SLASH, }, 
    { KEY_PERIOD, }, 
    { KEY_COMMA, }, 
    { KEY_END, }, 
    { KEY_TILDE, }, 
    { KEY_Y, }, 
    { KEY_A, }, 
    { KEY_F9, }, 

    /* 12 (pin 28) */
    { KEY_7, }, 
    { KEY_6, }, 
    { KEY_5, }, 
    { KEY_4, }, 
    { KEY_DELETE, }, 
    { KEY_T, }, 
    { KEY_CAPS_LOCK, }, 
    { KEY_F8, }, 

};


uint8_t samples_mask = 0x0f;


Led leds[NUM_LEDS] = {
    { 0x01, &PORTC, DDC6 },  /* Num Lock */
    { 0x02, &PORTC, DDC7 },  /* Caps Lock */
    { 0x04, &PORTE, DDE6 },  /* Scroll lock */
};

/**
 * Trivial hack: simply return true (i.e. just send the keys).
 */
bool
Wyse_hack (void)
{
    return true;
}
bool (* Matrix_hack) (void) = Wyse_hack;

