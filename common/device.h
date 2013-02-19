#ifndef DEVICE_H
#define DEVICE_H

#include <stdint.h>

struct usb_string_descriptor_struct {
	uint8_t bLength;
	uint8_t bDescriptorType;
	int16_t wString[];
};

struct descriptor_list_struct {
	uint16_t	wValue;
	uint16_t	wIndex;
	const uint8_t	*addr;
	uint8_t		length;
};

// You can change these to give your code its own name.
#define STR_MANUFACTURER	L"MfgName"
#define STR_PRODUCT		L"Keyboard"


// Mac OS-X and Linux automatically load the correct drivers.  On
// Windows, even though the driver is supplied by Microsoft, an
// INF file is needed to load the driver.  These numbers need to
// match the INF file.
#define VENDOR_ID		0x16C0
#define PRODUCT_ID		0x047C

/**************************************************************************
 *
 *  Endpoint Buffer Configuration
 *
 **************************************************************************/

#define ENDPOINT0_SIZE		32

#define KEYBOARD_INTERFACE	0
#define KEYBOARD_ENDPOINT	1
#define KEYBOARD_SIZE		8
#define KEYBOARD_BUFFER		EP_DOUBLE_BUFFER


#define ENDPOINT_CONFIG_SIZE 6
extern const uint8_t endpoint_config_table[ENDPOINT_CONFIG_SIZE];

/**
 * This table defines which descriptor data is sent for each specific
 * request from the host (in wValue and wIndex).
 */
#define NUM_DESC_LIST 7
extern struct descriptor_list_struct descriptor_list[NUM_DESC_LIST];

#endif
