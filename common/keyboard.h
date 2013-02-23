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

#ifndef KEYBOARD_H
#define KEYBOARD_H

/**
 * Keyboard usage, as per chapter 10 of "Universal Serial Bus HID Usage Tables".
 */

enum {
    KEY_RESERVED = 0x0,
    KEY_ERROR_ROLLOVER,
    KEY_POST_FAIL,
    KEY_ERROR_UNDEFINED,
    KEY_A,
    KEY_B,
    KEY_C,
    KEY_D,
    KEY_E,
    KEY_F,
    KEY_G,
    KEY_H,
    KEY_I,
    KEY_J,
    KEY_K,
    KEY_L,
    KEY_M,
    KEY_N,
    KEY_O,
    KEY_P,
    KEY_Q,
    KEY_R,
    KEY_S,
    KEY_T,
    KEY_U,
    KEY_V,
    KEY_W,
    KEY_X,
    KEY_Y,
    KEY_Z,
    KEY_1,  /* 1 and ! */
    KEY_2,  /* 2 and @ */
    KEY_3,  /* 3 and # */
    KEY_4,  /* 4 and $ */
    KEY_5,  /* 5 and % */
    KEY_6,  /* 6 and ^ */
    KEY_7,  /* 7 and & */
    KEY_8,  /* 8 and * */
    KEY_9,  /* 9 and ( */
    KEY_0,  /* 0 and ) */
    KEY_ENTER,
    KEY_ESCAPE,
    KEY_BACKSPACE,
    KEY_TAB,
    KEY_SPACE,
    KEY_MINUS,  /* - and _ */
    KEY_EQUALS, /* = and + */
    KEY_LEFT_BRACE,  /* [ and { */
    KEY_RIGHT_BRACE, /* ] and } */
    KEY_BACKSLASH,  /* \ and | */
    KEY_NUMBER,
    KEY_SEMICOLON,  /* and : */
    KEY_QUOTE,  /* ' and " */
    KEY_BACKQUOTE,  /* ` and ~ */
    KEY_COMMA,  /* , and < */
    KEY_PERIOD,  /* . and > */
    KEY_SLASH,  /* / and ? */
    KEY_CAPS_LOCK,
    KEY_F1,
    KEY_F2,
    KEY_F3,
    KEY_F4,
    KEY_F5,
    KEY_F6,
    KEY_F7,
    KEY_F8,
    KEY_F9,
    KEY_F10,
    KEY_F11,
    KEY_F12,
    KEY_PRINT_SCREEN,
    KEY_SCROLL_LOCK,
    KEY_PAUSE,
    KEY_INSERT,
    KEY_HOME,
    KEY_PAGE_UP,
    KEY_DELETE,
    KEY_END,
    KEY_PAGE_DOWN,
    KEY_RIGHT,
    KEY_LEFT,
    KEY_DOWN,
    KEY_UP,
    KEY_NUM_LOCK,
    KEYPAD_SLASH,
    KEYPAD_STAR,
    KEYPAD_MINUS,
    KEYPAD_PLUS,
    KEYPAD_ENTER,
    KEYPAD_1,  /* 1 and keypad End */
    KEYPAD_2,  /* 2 and keypad down arrow */
    KEYPAD_3,  /* 3 and keypad PgDn */
    KEYPAD_4,  /* 4 and keypad left arrow */
    KEYPAD_5,
    KEYPAD_6,  /* 6 and keypad right arrow */
    KEYPAD_7,  /* 7 and keypad Home */
    KEYPAD_8,  /* 8 and keypad up arrow */
    KEYPAD_9,  /* 9 and keypad PgUp */
    KEYPAD_0,  /* 0 and keypad Ins */
    KEYPAD_PERIOD,  /* . and keypad Del */
    KEYPAD_BACKSLASH,
    KEY_APPLICATION,
    KEY_POWER,
    KEYPAD_EQUALS,
    KEY_F13,
    KEY_F14,
    KEY_F15,
    KEY_F16,
    KEY_F17,
    KEY_F18,
    KEY_F19,
    KEY_F20,
    KEY_F21,
    KEY_F22,
    KEY_F23,
    KEY_F24,
    KEY_EXECUTE,
    KEY_HELP,
    KEY_MENU,
    KEY_SELECT,
    KEY_STOP,
    KEY_AGAIN,
    KEY_UNDO,
    KEY_CUT,
    KEY_COPY,
    KEY_PASTE,
    KEY_FIND,
    KEY_MUTE,
    KEY_VOLUME_UP,
    KEY_VOLUME_DOWN,
    KEY_LOCKING_CAPS_LOCK,
    KEY_LOCKING_NUM_LOCK,
    KEY_LOCKING_SCROLL_LOCK,
    KEYPAD_COMMA,
    KEYPAD_EQUAL_SIGN,
    KEY_INTERNATIONAL_1,
    KEY_INTERNATIONAL_2,
    KEY_INTERNATIONAL_3,
    KEY_INTERNATIONAL_4,
    KEY_INTERNATIONAL_5,
    KEY_INTERNATIONAL_6,
    KEY_INTERNATIONAL_7,
    KEY_INTERNATIONAL_8,
    KEY_INTERNATIONAL_9,
    KEY_LANG_1,
    KEY_LANG_2,
    KEY_LANG_3,
    KEY_LANG_4,
    KEY_LANG_5,
    KEY_LANG_6,
    KEY_LANG_7,
    KEY_LANG_8,
    KEY_LANG_9,
    KEY_ALT_ERASE,
    KEY_SYS_REQ,
    KEY_CANCEL,
    KEY_CLEAR,
    KEY_PRIOR,
    KEY_RETURN,
    KEY_SEPARATOR,
    KEY_OUT,
    KEY_OPER,
    KEY_CLEAR_AGAIN,
    KEY_CR_SEL_PROPS,
    KEY_EX_SEL,

    KEYPAD_00 = 0xb0,
    KEYPAD_000,
    KEY_THOUSANDS,
    KEY_DECIMAL,
    KEY_CURRENCY_UNIT,
    KEY_CURRENCY_SUB_UNIT,
    KEYPAD_LEFT_BRACKET,
    KEYPAD_RIGHT_BRACKET,
    KEYPAD_LEFT_BRACE,
    KEYPAD_RIGHT_BRACE,
    KEYPAD_TAB,
    KEYPAD_BACKSPACE,
    KEYPAD_A,
    KEYPAD_B,
    KEYPAD_C,
    KEYPAD_D,
    KEYPAD_E,
    KEYPAD_F,
    KEYPAD_XOR,
    KEYPAD_CAP,
    KEYPAD_PERCENT,
    KEYPAD_LESS_THAN,
    KEYPAD_GREATER_THAN,
    KEYPAD_AMPERSAND,
    KEYPAD_DOUBLE_AMPERSAND,
    KEYPAD_BAR,
    KEYPAD_DOUBLE_BAR,
    KEYPAD_COLON,
    KEYPAD_HASH,
    KEYPAD_SPACE,
    KEYPAD_AT,
    KEYPAD_BANG,
    KEYPAD_MEMORY_STORE,
    KEYPAD_MEMORY_RECALL,
    KEYPAD_MEMORY_CLEAR,
    KEYPAD_MEMORY_ADD,
    KEYPAD_MEMORY_SUBTRACT,
    KEYPAD_MEMORY_MULTIPLY,
    KEYPAD_MEMORY_DIVIDE,
    KEYPAD_PLUS_MINUS,
    KEYPAD_CLEAR,
    KEYPAD_CLEAR_ENTRY,
    KEYPAD_BINARY,
    KEYPAD_OCTAL,
    KEYPAD_DECIMAL,
    KEYPAD_HEXADECIMAL,

    KEY_LEFT_CONTROL = 0xe0,
    KEY_CONTROL = KEY_LEFT_CONTROL,
    KEY_LEFT_SHIFT,
    KEY_SHIFT = KEY_LEFT_SHIFT,
    KEY_LEFT_ALT,
    KEY_ALT = KEY_LEFT_ALT,
    KEY_LEFT_GUI,
    KEY_GUI = KEY_LEFT_GUI,
    KEY_RIGHT_CONTROL,
    KEY_RIGHT_SHIFT,
    KEY_RIGHT_ALT,
    KEY_RIGHT_GUI,
};

#endif
