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

#include "led.h"
#include "usb.h"
#include "boot_keyboard.h"

void
Led_set (void)
{
    static uint8_t last_keyboard_leds = 0x0;
    uint8_t keyboard_leds;
    uint8_t i_led;
    Led led;
    uint8_t set_on = 0;
    
    keyboard_leds = boot_keyboard_get_leds ();
    if ( last_keyboard_leds != keyboard_leds ) {
        for ( i_led = 0; i_led < NUM_LEDS; i_led++ ) {
            led = leds[i_led];
            set_on = (keyboard_leds & led.flag) ? 1 : 0;
            set_on ^= LED_REVERSE;
            if ( set_on ) {
                *(led.port) |= (1 << led.pin);
            }
            else {
                *(led.port) &= ~(1 << led.pin);
            }
        }
        last_keyboard_leds = keyboard_leds;
    }
}
