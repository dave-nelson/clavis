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

#ifndef INTERFACE_H
#define INTERFACE_H

#include <stdint.h>

/**
 * The data structure that defines interfaces, including an endpoint with data 
 * to be sent and received.
 *
 * When communication with the host is initiated, "endpoint" indicates the 
 * endpoint number to be used, "size_in_data" and "size_out_data" indicate how 
 * much data is to be written in to or read out from (resp.) the host.  This 
 * information is provided by the implementer of an interface, and is typically 
 * used by the USB implementation (usb.[ch]).
 */
typedef struct interface_ {
    uint8_t endpoint;
    uint8_t protocol;

    uint8_t size_in_data;
    uint8_t * in_data;

    uint8_t size_out_data;
    uint8_t * out_data;
} interface_t;


#endif
