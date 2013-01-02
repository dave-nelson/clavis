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
    { &DDRD, 0x00, &PORTD, 0xff },
    { &DDRF, 0x00, &PORTF, 0xff },
    /* Output, high */
    { &DDRB, 0xFF, &PORTB, 0xff },
    /* LEDs */
    { &DDRC, 0xFF, &PORTC, 0x00 },
    { &DDRE, 0xFF, &PORTE, 0x00 },
};

Pin columns[NUM_COLS] = {
    /* TI CF60137N pins 1-8 */
    { &PORTB, DDB0 },
    { &PORTB, DDB1 },
    { &PORTB, DDB2 },
    { &PORTB, DDB3 },
    { &PORTB, DDB4 },
    { &PORTB, DDB5 },
    { &PORTB, DDB6 },
    { &PORTB, DDB7 },
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
    /* 24-28 */
    { &PINF, PINF1 },
    { &PINF, PINF4 },
    { &PINF, PINF5 },
    { &PINF, PINF6 },
    { &PINF, PINF7 },
};


Key matrix[NUM_COLS][NUM_ROWS] = {
    /* 1 */
    {
        { KEYPAD_0, }, 
        { KEYPAD_PERIOD, }, 
        { KEY_UP, }, 
        { KEY_DOWN, }, 
        { KEY_LEFT, }, 
        { KEY_SCROLL_LOCK, }, 
        { KEY_RIGHT, }, 
        { KEY_L, }, 

        { KEY_HOME, }, 
        { KEYPAD_ENTER, }, 
        { KEYPAD_PLUS, },  /* Numberpad "," */
        { KEY_SLASH, }, 
        { KEY_7, }, 
    },
    /* 2 */
    {
        { KEYPAD_4, }, 
        { KEYPAD_5, }, 
        { KEYPAD_6, }, 
        { KEYPAD_1, }, 
        { KEYPAD_2, }, 
        { KEY_PRINTSCREEN, }, 
        { KEY_RIGHT_BRACE, }, 
        { KEY_K, }, 

        { KEYPAD_3, }, 
        { KEY_PAGE_DOWN, }, 
        { KEYPAD_PLUS, }, 
        { KEY_PERIOD, }, 
        { KEY_6, }, 
    },
    /* 3 */
    {
        { KEY_NUM_LOCK, }, 
        { KEYPAD_SLASH, },  /* "PF2" */ 
        { KEYPAD_ASTERIX, },  /* "PF3" */
        { KEYPAD_MINUS, },  /* "PF4" */
        { KEYPAD_7, }, 
        { 0x00, }, /* "F17" */ 
        { KEY_LEFT_BRACE, }, 
        { KEY_J, }, 

        { KEYPAD_9, }, 
        { KEYPAD_8, }, 
        { KEY_PAGE_UP, }, 
        { KEY_COMMA, }, 
        { KEY_5, }, 
    },
    /* 4 */
    {
        { 0x00, },  /* "<>" */ 
        { KEY_Z, }, 
        { KEY_C, }, 
        { KEY_X, }, 
        { KEY_V, }, 
        { KEY_ESC, },  /* Wyse "Do" */
        { KEY_BACKSPACE, }, 
        { 0x00, KEY_SHIFT, }, 

        { KEY_M, }, 
        { KEY_B, }, 
        { KEY_N, }, 
        { KEY_END, }, 
        { KEY_4, }, 
    },
    /* 5 */
    {
        { KEY_8, }, 
        { KEY_9, }, 
        { KEY_0, }, 
        { KEY_MINUS, }, 
        { KEY_EQUAL, }, 
        { 0x00, KEY_RIGHT_GUI },  /* Wyse "Help" */
        { KEY_P, }, 
        { KEY_H, },

        { KEY_3, }, 
        { KEY_2, }, 
        { KEY_1, }, 
        { KEY_TILDE, }, 
        { KEY_DELETE, }, 
    },
    /* 6 */
    {
        { KEY_TAB, }, 
        { KEY_R, }, 
        { KEY_W, }, 
        { KEY_E, }, 
        { KEY_Q, }, 
        { 0x00, },  /* "F14" */ 
        { KEY_INSERT, }, 
        { KEY_G, },

        { KEY_O, }, 
        { KEY_I, }, 
        { KEY_U, }, 
        { KEY_Y, }, 
        { KEY_T, }, 
    },
    /* 7 */
    {
        { KEY_ENTER, }, 
        { KEY_QUOTE, }, 
        { KEY_BACKSLASH, }, 
        { KEY_SEMICOLON, }, 
        { KEY_SPACE, }, 
        { 0x00, },  /* "F13" */
        { 0x00, KEY_CTRL }, 
        { KEY_PAUSE, },

        { KEY_D, }, 
        { KEY_F, }, 
        { KEY_S, }, 
        { KEY_A, }, 
        { KEY_CAPS_LOCK, }, 
    },
    /* 8 */
    {
        { KEY_F1, }, 
        { KEY_F2, }, 
        { KEY_F3, }, 
        { KEY_F4, }, 
        { KEY_F5, }, 
        { 0x00, KEY_ALT},  /* Wyse "Compose Character" */
        { KEY_F7, }, 
        { KEY_F6, }, 

        { KEY_F12, }, 
        { KEY_F11, }, 
        { KEY_F10, }, 
        { KEY_F9, }, 
        { KEY_F8, }, 
    },

};

uint8_t samples_mask = 0x0f;


Led leds[NUM_LEDS] = {
    { 0x01, &PORTC, DDC6 },
    { 0x02, &PORTC, DDC7 },
    { 0x04, &PORTE, DDE6 },
};
