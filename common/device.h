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

#ifndef DEVICE_H
#define DEVICE_H

#include <stdint.h>
#include "interface.h"

struct descriptor_list_struct {
	uint16_t	wValue;
	uint16_t	wIndex;
	const uint8_t	*addr;
	uint8_t		length;
};

/**************************************************************************
 *
 *  Endpoint Buffer Configuration
 *
 **************************************************************************/
/**
 * Interfaces
 */
enum {
    KEYBOARD_INTERFACE = 0,
    NUM_INTERFACES,
    INVALID_INTERFACE = NUM_INTERFACES,
};
extern interface_t * interfaces[NUM_INTERFACES];

/**
 * Endpoints
 */
enum {
    CONTROL_ENDPOINT,  /* provided by the controller */
    KEYBOARD_ENDPOINT, /* for KEYBOARD_INTERFACE */
    NUM_ENDPOINTS,
    INVALID_ENDPOINT = NUM_ENDPOINTS,
};

#define KEYBOARD_SIZE		8
#define KEYBOARD_BUFFER		EP_DOUBLE_BUFFER


#define ENDPOINT0_SIZE		32
#define ENDPOINT_CONFIG_SIZE 6
extern const uint8_t endpoint_config_table[ENDPOINT_CONFIG_SIZE];

/**
 * This table defines which descriptor data is sent for each specific
 * request from the host (in wValue and wIndex).
 */
#define NUM_DESC_LIST 7
extern struct descriptor_list_struct descriptor_list[NUM_DESC_LIST];

#endif
