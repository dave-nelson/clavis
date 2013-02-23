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

#include <avr/io.h>
#include <avr/pgmspace.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "usb_keyboard.h"
#include "matrix.h"
#include "led.h"
#include "project.h"
#include "boot_keyboard.h"

#define CPU_PRESCALE(n)	(CLKPR = 0x80, CLKPR = (n))

int main(void)
{
    CPU_PRESCALE(0);

    Matrix_ports_init ();
    usb_init ();
    while ( !usb_configured() ) {
        _delay_ms (10);
    }
    _delay_ms(1000);
    // boot_keyboard_press (KEY_A, 0); 
    while (1) { 
        Matrix_scan ();
        Led_set ();
        _delay_us (POLL_DELAY_USEC);
    }
}
