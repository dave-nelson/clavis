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

#include "nkro_keyboard.h"
#include "device.h"
#include "keyboard.h"
#include "usb.h"

#define SIZE_IN_DATA 29
static uint8_t in_data[SIZE_IN_DATA];
#define SIZE_OUT_DATA 1
static uint8_t out_data[SIZE_OUT_DATA];

interface_t nkro_keyboard = {
    NKRO_KEYBOARD_ENDPOINT,
    0,

    SIZE_IN_DATA,
    in_data,

    SIZE_OUT_DATA,
    out_data,
};

int8_t
nkro_keyboard_press (uint8_t key, uint8_t modifier)
{
    int8_t r;

    nkro_keyboard_clear ();

    if ( modifier ) {
        int i;
        for ( i = 0; i < 8; i++ ) {
            if ( modifier & (1 << i) ) {
                nkro_keyboard_set_key (KEY_LEFT_CONTROL + i);
            }
        }
        r = nkro_keyboard_send ();
        if ( r ) 
            return r;
    }

    nkro_keyboard_set_key (key);

    r = nkro_keyboard_send ();
    if ( r ) 
        return r;

    nkro_keyboard_clear ();
    return nkro_keyboard_send ();
}

void
nkro_keyboard_clear (void)
{
    uint8_t i;
    for ( i = 0; i < SIZE_IN_DATA; i++ ) {
        in_data[i] = 0;
    }
}

void
nkro_keyboard_set_key (uint8_t key)
{
    if ( (key / 8) < SIZE_IN_DATA ) {
        in_data[key / 8] |= (1 << key % 8);
    }
}

int8_t
nkro_keyboard_send (void)
{
    return interface_send (&nkro_keyboard);
}

uint8_t
nkro_keyboard_get_leds (void)
{
    return out_data[0];
}
