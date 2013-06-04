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
#include "boot_keyboard.h"
#include "nkro_keyboard.h"
#include <util/delay.h>

bool selection[NUM_COLS * NUM_ROWS] = { 0, };

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

static uint8_t active_keyboard = KEYBOARD_INTERFACE;

void
Matrix_set_active_keyboard (uint8_t keyboard_num)
{
    active_keyboard = keyboard_num;
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
            if ( selection[ KEY_NUM(i_col, i_row) ] ) {
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
                if ( selection[ KEY_NUM(i_col, i_row) ] && 
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

    boot_keyboard_clear ();
    nkro_keyboard_clear ();

    for ( i_col = 0; i_col < NUM_COLS; i_col++ ) {
        for ( i_row = 0; i_row < NUM_ROWS; i_row++ ) {
            if ( selection[ KEY_NUM(i_col, i_row) ] ) {
                key = &(matrix[ KEY_NUM(i_col, i_row) ]);
                if ( key->code ) {
                    boot_keyboard_set_key (key->code);
                    nkro_keyboard_set_key (key->code);
                }
                /* else ignore unused key */
            }
        }
    }
    switch ( active_keyboard ) {
        case NKRO_KEYBOARD_INTERFACE:
            nkro_keyboard_send ();
            break;
        default:
            boot_keyboard_send ();
    }
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
            key = &(matrix[ KEY_NUM(i_col, i_row) ]);
            key_down = (*(rows[i_row].port) & (1 << rows[i_row].pin)) ? 0 : 1;
            key->samples = (((key->samples << 1) | key_down) & SAMPLES_MASK);
            if ( key->samples != key->state ) {
                if ( key->samples == 0x00 || key->samples == SAMPLES_MASK ) {
                    /* Key is in a stable state (debounced) */
                    key->state = key->samples;
                    selection[ KEY_NUM(i_col, i_row) ] = (key->state == SAMPLES_MASK);
                    matrix_is_changed = true;
                }
            }
        }
        *(columns[i_col].port) |= (1 << columns[i_col].pin);
    }
    if ( matrix_is_changed ) {
        if ( !(Matrix_hack) || (*Matrix_hack) () ) {
#if DE_GHOST
            if ( ! Matrix_block () ) {
                Matrix_send ();
            }
#else
            Matrix_send ();
#endif
        }
    }
}
