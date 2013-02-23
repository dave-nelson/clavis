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

#ifndef BOOT_KEYBOARD_H
#define BOOT_KEYBOARD_H

#include "interface.h"

extern interface_t boot_keyboard;

int8_t boot_keyboard_press(uint8_t key, uint8_t modifier);

void boot_keyboard_clear (void);

void boot_keyboard_set_key (uint8_t key);

int8_t boot_keyboard_send(void);

uint8_t boot_keyboard_get_leds (void);

#endif
