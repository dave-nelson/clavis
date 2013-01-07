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

bool selected_keys[NUM_COLS][NUM_ROWS];

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

bool
Matrix_block (void)
{
    bool do_block = false;
    uint8_t i_col, i_row;
    uint8_t col_counter[NUM_COLS] = { 0, };
    uint8_t row_counter[NUM_ROWS] = { 0, };
    uint8_t total_count = 0;

    for ( i_col = 0; i_col < NUM_COLS; i_col++ ) {
        for ( i_row = 0; i_row < NUM_ROWS; i_row++ ) {
            if ( selected_keys[i_col][i_row] ) {
                col_counter[i_col] += 1;
                row_counter[i_row] += 1;
                total_count += 1;
            }
        }
    }
    if ( total_count > 2 ) {
        /* Could be ghosts? */
        for ( i_col = 0; i_col < NUM_COLS && !do_block; i_col++ ) {
            for ( i_row = 0; i_row < NUM_ROWS && !do_block; i_row++ ) {
                if ( selected_keys[i_col][i_row] && 
                        col_counter[i_col] > 1 && 
                        row_counter[i_row] > 1 ) {
                    do_block = true;
                    break;
                }
            }
        }
    }
    return do_block;
}

void
Matrix_send (void)
{
    Key * key;
    uint8_t i_col, i_row;
    uint8_t key_count = 0;

    keyboard_modifier_keys = 0;

    for ( i_col = 0; i_col < NUM_COLS; i_col++ ) {
        for ( i_row = 0; i_row < NUM_ROWS; i_row++ ) {
            if ( selected_keys[i_col][i_row] ) {
                key = &(matrix[i_col][i_row]);
                if ( key->modifier ) {
                    keyboard_modifier_keys |= key->modifier;
                }
                else {
                    if ( key_count < 6 ) {
                        keyboard_keys[key_count] = key->name;
                        key_count++;
                    }
                }
            }
        }
    }
    for ( ; key_count < 6; key_count++ ) {
        keyboard_keys[key_count] = 0;
    }
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
        _delay_us (PIN_DELAY_USEC);

        for ( i_row = 0; i_row < NUM_ROWS; i_row++ ) {
            key = &(matrix[i_col][i_row]);
            key_down = (*(rows[i_row].port) & (1 << rows[i_row].pin)) ? 0 : 1;
            key->samples = (((key->samples << 1) | key_down) & samples_mask);
            if ( key->samples != key->state ) {
                if ( key->samples == 0x00 || key->samples == samples_mask ) {
                    /* Key is in a stable state (debounced) */
                    key->state = key->samples;
                    selected_keys[i_col][i_row] = (key->state == samples_mask);
                    matrix_is_changed = true;
                }
            }
        }
        *(columns[i_col].port) |= (1 << columns[i_col].pin);
    }
    if ( matrix_is_changed ) {
#if DE_GHOST
        if ( ! Matrix_block () ) {
            Matrix_send ();
        }
#else
        Matrix_send ();
#endif
    }
}
