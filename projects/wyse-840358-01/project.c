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
#include "../../common/keyboard.h"

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
    { KEYPAD_7, },
    { KEY_PERIOD, },
    { KEY_K, },
    { KEY_U, },
    { KEY_5, },
    { KEY_BACKSLASH, },
    { KEY_F10, },
    { KEY_ESCAPE, },

    /* 1 (pin 10) */
    { KEYPAD_PLUS, },
    { KEY_EQUALS, },
    { KEY_ENTER, },
    { KEY_Y, },
    { KEY_LEFT_ALT, },
    { KEY_2, },
    { KEY_BACKQUOTE, },
    { KEY_1, },

    /* 2 (pin 11) */
    { KEYPAD_ENTER, },
    { KEY_COMMA, },
    { KEY_F12, },
    { KEY_O, },
    { KEY_NUM_LOCK, },
    { KEY_CAPS_LOCK, },
    { KEY_LEFT_CONTROL, },
    { 0x00 },

    /* 3 (pin 12) */
    { KEYPAD_PERIOD },
    { KEY_F11 },
    { KEY_SLASH },
    { KEY_I },
    { KEY_SEMICOLON },
    { KEY_RIGHT_SHIFT },
    { 0x00 },
    { KEY_LEFT_SHIFT },

    /* 4 (pin 13) */
    { KEYPAD_0 },
    { KEYPAD_9 },
    { KEYPAD_MINUS },
    { KEYPAD_STAR },
    { KEY_QUOTE },
    { KEY_GUI },
    { KEY_RIGHT_CONTROL },
    { KEY_SPACE },

    /* 5 (pin 14) */
    { KEYPAD_SLASH },
    { KEY_Z },
    { KEY_L },
    { KEY_MINUS },
    { KEY_RIGHT_ALT },
    { KEY_RIGHT_BRACE },
    { KEY_SCROLL_LOCK },
    { KEY_LEFT_BRACE },

    /* 6 (pin 15) */
    { KEYPAD_2 },
    { KEY_M },
    { KEY_H },
    { KEY_P },
    { KEY_4 },
    { KEY_HOME },
    { KEY_F6 },
    { KEY_RIGHT },

    /* 7 (pin 16) */
    { KEYPAD_1 },
    { KEY_B },
    { KEY_J },
    { KEY_T },
    { KEY_3 },
    { KEY_INSERT },
    { KEY_F7 },
    { KEY_BACKSPACE },

    /* 8 (pin 24) */
    { KEYPAD_8 },
    { KEY_F9 },
    { KEY_A },
    { KEY_F8 },
    { KEY_9 },
    { KEY_F1 },
    { KEY_PAUSE },
    { KEY_TAB },

    /* 9 (pin 25) */
    { KEYPAD_6 },
    { KEY_C },
    { KEY_S },
    { KEY_Q },
    { KEY_8 },
    { KEY_PAGE_DOWN },
    { KEY_F2 },
    { KEY_PRINT_SCREEN },

    /* 10 (pin 26) */
    { KEYPAD_5 },
    { KEY_X },
    { KEY_F },
    { KEY_E },
    { KEY_7 },
    { KEY_END },
    { KEY_F3 },
    { KEY_LEFT },

    /* 11 (pin 27) */
    { KEYPAD_4 },
    { KEY_V },
    { KEY_D },
    { KEY_W },
    { KEY_6 },
    { KEY_DELETE },
    { KEY_F4 },
    { KEY_DOWN },

    /* 12 (pin 28) */
    { KEYPAD_3 },
    { KEY_N },
    { KEY_G },
    { KEY_R },
    { KEY_0 },
    { KEY_PAGE_UP },
    { KEY_F5 },
    { KEY_UP },

};

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

