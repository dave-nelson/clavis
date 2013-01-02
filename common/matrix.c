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

#include "matrix.h"
#include <util/delay.h>


void
Matrix_ports_init (void)
{
    Port port;
    int i;

    for ( i = 0; i < NUM_PORTS; i++ ) {
        port = ports[i];
        *(port.direction) = port.direction_flags;
        *(port.config) = port.config_flags;
    }
}

void
Matrix_send (void)
{
    Key * key;
    uint8_t i_col, i_row;
    uint8_t key_count = 0;
    // usb_keyboard_press(KEY_C, 0);

    keyboard_modifier_keys = 0;

    for ( i_col = 0; i_col < NUM_COLS; i_col++ ) {

        for ( i_row = 0; i_row < NUM_ROWS; i_row++ ) {
            key = &(matrix[i_col][i_row]);
            if ( key->state == samples_mask ) {
                if ( key->modifier ) {
                    keyboard_modifier_keys |= key->modifier;
                }
                else {
                    if ( key_count < 6 ) {
                        keyboard_keys[key_count] = key->name;
                        // usb_keyboard_press(key->name, 0);
                        key_count++;
                    }
                }
            }
        }
    }
    for ( ; key_count < 6; key_count++ ) {
        keyboard_keys[key_count] = 0;
    }
    // usb_keyboard_press(KEY_SPACE, 0);

    usb_keyboard_send ();
}

void
Matrix_scan ()
{
    Key * key;
    uint8_t key_down;
    uint8_t i_row, i_col;
    bool matrix_is_changed = false;

    for ( i_col = 0; i_col < NUM_COLS; i_col++ ) {
        *(columns[i_col].port) &= ~(1 << columns[i_col].pin);
        _delay_us (500);

        for ( i_row = 0; i_row < NUM_ROWS; i_row++ ) {
            key = &(matrix[i_col][i_row]);
            // key_down = (*(key->port) & (1 << key->pin)) ? 0 : 1;
            key_down = (*(rows[i_row].port) & (1 << rows[i_row].pin)) ? 0 : 1;
            key->samples = (((key->samples << 1) | key_down) & samples_mask);
            /*
            if ( key_down ) {
                    samples = key->samples;
        	    usb_keyboard_press(key->name, 0);
                    // usb_keyboard_press(hex[samples >> 4], 0);
                    usb_keyboard_press(hex[samples & 0x0f], 0);
            }
            */
            if ( key->samples != key->state ) {
                if ( key->samples == 0x00 || key->samples == samples_mask ) {
                    /* Key is in a stable state (debounced) */
                    key->state = key->samples;
                    matrix_is_changed = true;
        	    
                    /* Debug */
/*
                    usb_keyboard_press(key->name, 0);
                    if ( key->state == samples_mask ) {
        		usb_keyboard_press(KEYPAD_PLUS, 0);
                    }
                    else {
        		usb_keyboard_press(KEYPAD_MINUS, 0);
                    }
*/
                }
            }
        }
        *(columns[i_col].port) |= (1 << columns[i_col].pin);
        // _delay_ms (10);
    }
    if ( matrix_is_changed ) {
        Matrix_send ();
    }
}
