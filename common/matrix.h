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

#ifndef MATRIX_H
#define MATRIX_H

#define PROJ_HEADER "project.h"

#include <avr/io.h>
#include <stdbool.h>
#include "usb.h"
#include "project.h"

/**
 * Convenience macro to get the index of a key given its column and row.
 */
#define KEY_NUM(col,row)    \
    (row * NUM_COLS + col)

/* Configuration for port I/O */

typedef struct {
    volatile uint8_t * direction;
    uint8_t   direction_flags;
    volatile uint8_t * config;
    uint8_t   config_flags;
} Port;

extern Port ports[NUM_PORTS];

typedef struct {
    volatile uint8_t * port;
    uint8_t pin;
} Pin;

extern Pin columns[NUM_COLS];
extern Pin rows[NUM_ROWS];

/* Key */

typedef struct {
    uint8_t code;  /* USB HID spec key code, for regular characters */
    uint8_t modifier;  /* USB modifier flag for shift, ctrl etc. */
    uint8_t samples;
    uint8_t state;  /* All unmasked bits 1: on, else off */
} Key;

/**
 * Keyboard matrix definition.
 *
 * This needs to be defined for every project, depending on the layout of the 
 * hardware.
 */
extern Key matrix[NUM_COLS * NUM_ROWS];

/**
 * Current key selection.
 *
 * On each scan of the matrix, this array is updated with the currently 
 * selected (i.e. closed) keys.
 */
extern bool selection[NUM_COLS * NUM_ROWS];

/**
 * Callback: hack the matrix and/or current key selection.
 *
 * Matrix_hack is called whenever the keys are changed, before they are 
 * de-ghosted and sent to the host.  Can be used to implement custom 
 * modifications to the matrix keys and/or the current selection.  Point 
 * Matrix_hack to some function, or set it to 0 to disable hacks.
 *
 * If enabled, a return value of true means proceed: send the keys.  False 
 * means block: don't send keys to the host (this can be useful if the hack 
 * involves sending other arbitrary key combinations to the host directly).
 */
extern bool (* Matrix_hack) (void);

/* Mask, for ignoring high bits in a sample bit array.  (Samples are stored in 
 * the low bits.) */
extern uint8_t samples_mask;

/**
 * Initialise all I/O ports for the keyboard matrix.
 *
 * Using the flags in the "ports" variable, configure all the I/O ports that are to be used for the keyboard matrix.
 */
void Matrix_ports_init (void);

/**
 * Scan the key matrix, updating the state of any keys as appropriate.
 */
void Matrix_scan (void);

#endif
