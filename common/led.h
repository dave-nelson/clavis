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

#ifndef LED_H
#define LED_H

#include <stdint.h>
#include "project.h"

/**
 * Device Class Definition for Human Interface Devices (HID) Version 1.11, p.60
 */
#define IND_NUM_LOCK    (0x01)
#define IND_CAPS_LOCK   (0x02)
#define IND_SCROLL_LOCK (0x04)
#define IND_COMPOSE     (0x08)
#define IND_KANA        (0x10)

typedef struct {
    uint8_t flag;
    volatile uint8_t * port;
    uint8_t pin;
} Led;

extern Led leds[NUM_LEDS];

/**
 * Set the state of all LEDs to on/off, depending on the keyboard LED state 
 * conveyed by USB.
 */
void Led_set (void);

#endif
