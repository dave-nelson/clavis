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

#include "boot_keyboard.h"
#include "device.h"
#include "keyboard.h"
#include "usb_keyboard.h"

#define SIZE_IN_DATA 8
static uint8_t in_data[SIZE_IN_DATA];
#define SIZE_OUT_DATA 1
static uint8_t out_data[SIZE_OUT_DATA];

/**
 * Number of currently-set keys.
 */
static uint8_t key_count = 0;

interface_t boot_keyboard = {
    KEYBOARD_ENDPOINT,
    0,

    SIZE_IN_DATA,
    in_data,

    SIZE_OUT_DATA,
    out_data,
};

// perform a single keystroke
int8_t boot_keyboard_press(uint8_t key, uint8_t modifier)
{
	int8_t r;

	in_data[0] = modifier;
	in_data[2] = key;
	r = boot_keyboard_send();
	if (r) return r;
	in_data[0] = 0;
	in_data[2] = 0;
	return boot_keyboard_send();
}

void
boot_keyboard_clear (void)
{
    uint8_t i;
    for ( i = 0; i < SIZE_IN_DATA; i++ ) {
        in_data[i] = 0;
    }
    key_count = 0;
}

void
boot_keyboard_set_key (uint8_t key)
{
    uint8_t i;

    if ( key < KEY_CONTROL ) {
        /* Regular character (limit 6) */
        if ( key_count > 5 ) {
            /* Overflow: send KEY_ERROR_ROLLOVER, as per HID spec. */
            for ( i = 2; i < SIZE_IN_DATA; i++ ) {
                in_data[i] = KEY_ERROR_ROLLOVER; 
            }
        }
        else {
            in_data[key_count + 2] = key;
            key_count++;
        }
    }
    else {
        /* Set the corresponding bit in in_data[0] (i.e. modifiers) */
        in_data[0] |= (1 << (key - KEY_CONTROL));
    }
}

// send the contents of keyboard_keys and keyboard_modifier_keys
int8_t 
boot_keyboard_send(void)
{
    return interface_send (&boot_keyboard);
}

uint8_t
boot_keyboard_get_leds (void)
{
    return out_data[0];
}
