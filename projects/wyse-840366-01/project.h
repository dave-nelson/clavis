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

#ifndef PROJECT_H
#define PROJECT_H

/**
 * Project-specific parameters.
 *
 * The settings in this file relate to the project as a whole, and relate to a 
 * specific model of keyboard and controller chip.
 *
 * Before providing these settings, it is necessary to analyse the keyboard's 
 * matrix and to decide how that matrix will be wired into the controller.
 *
 * After setting these basic parameters the next step is to provide the details 
 * in "project.c".  Note that "project.c", "matrix.h" and "matrix.c" rely on 
 * the dimensions set here.
 */

/**
 * Number of ports on the controller to be configured.  Some of the ports on 
 * the controller will need to be configured for input and output, for scanning 
 * the matrix or for operating the indicator LEDs.  This figure is the total 
 * number of ports that need configuration.
 */
#define NUM_PORTS  5

/**
 * Model-specific matrix specifications.  After analysing the matrix of the 
 * target keyboard, enter the number of columns and rows here.
 */
#define NUM_COLS   8
#define NUM_ROWS  13

/**
 * The number of LEDs to be supported (typically 3: Num Lock, Caps Lock and Scroll Lock).
 *
 * Set to 0 if not required.
 */
#define NUM_LEDS 3

/**
 * Delay (in microseconds) between applying power to a column output pin and 
 * starting to poll the row input pins.
 *
 * Note that this figure will be sensitive to the speed of any protective 
 * diodes in front of the output pins.
 */
#define PIN_DELAY_USEC 50

/**
 * Delay (in microseconds) after performing one full scan of the matrix.
 */
#define POLL_DELAY_USEC 1500

/**
 * Should de-ghosting be invoked (for 2kro keyboards)?
 */
#define DE_GHOST 1

#endif
