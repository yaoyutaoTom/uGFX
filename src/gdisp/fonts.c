/*
 * This file is subject to the terms of the GFX License, v1.0. If a copy of
 * the license was not distributed with this file, you can obtain one at:
 *
 *              http://chibios-gfx.com/license.html
 */

/**
 * @file    src/gdisp/fonts.c
 * @brief   GDISP Font Handling.
 *
 * @addtogroup GDISP
 * @{
 */

#include "ch.h"
#include "hal.h"
#include "gfx.h"

#if GFX_USE_GDISP && GDISP_NEED_TEXT

#include "gdisp/fonts.h"

/* fontSmall - for side buttons */
#if GDISP_INCLUDE_FONT_SMALL
    /* Forward Declarations of internal arrays */
    static const uint8_t        fontSmall_Widths[];
    static const uint16_t       fontSmall_Offsets[];
    static const fontcolumn_t   fontSmall_Data[];

    static const struct font fontSmall = {
									"Small",
									11, 0, 14, 2, 2, 12, ' ', '~', 1, 1,
									fontSmall_Widths,
									fontSmall_Offsets,
									fontSmall_Data};
    static const struct font fontSmallDouble = {
									"Small Double",
									11, 0, 14, 2, 2, 12, ' ', '~', 2, 2,
									fontSmall_Widths,
									fontSmall_Offsets,
									fontSmall_Data};
    static const struct font fontSmallNarrow = {
									"Small Narrow",
									11, 0, 14, 2, 2, 12, ' ', '~', 1, 2,
									fontSmall_Widths,
									fontSmall_Offsets,
									fontSmall_Data};

	static const uint8_t fontSmall_Widths[] = {
		2, 3, 6, 8, 7, 9, 7, 3, 4, 4, 5, 7, 4, 4, 3, 6,
		7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 3, 4, 6, 7, 6, 7,
		12, 8, 7, 8, 8, 7, 7, 8, 8, 3, 5, 8, 7, 9, 8, 8,
		8, 8, 8, 7, 7, 8, 8, 12, 8, 8, 8, 4, 6, 4, 7, 7,
		4, 7, 7, 7, 7, 7, 4, 7, 7, 3, 3, 7, 3, 9, 7, 7,
		7, 7, 4, 6, 4, 7, 7, 9, 6, 6, 6, 5, 3, 5, 8, 0
	};
	static const uint16_t fontSmall_Offsets[] = {
		0, 2, 5, 11, 19, 26, 35, 42,
		45, 49, 53, 58, 65, 69, 73, 76,
		82, 89, 96, 103, 110, 117, 124, 131,
		138, 145, 152, 155, 159, 165, 172, 178,
		185, 197, 205, 212, 220, 228, 235, 242,
		250, 258, 261, 266, 274, 281, 290, 298,
		306, 314, 322, 330, 337, 344, 352, 360,
		372, 380, 388, 396, 400, 406, 410, 417,
		424, 428, 435, 442, 449, 456, 463, 467,
		474, 481, 484, 487, 494, 497, 506, 513,
		520, 527, 534, 538, 544, 548, 555, 562,
		571, 577, 583, 589, 594, 597, 602, 0
	};
	static const fontcolumn_t fontSmall_Data[] = {
		/*   */	0x0000, 0x0000,
		/* ! */	0x0000, 0x017F, 0x017F,
		/* " */	0x0000, 0x0007, 0x0007, 0x0000, 0x0007, 0x0007,
		/* # */	0x0000, 0x0044, 0x01FF, 0x01FF, 0x0044, 0x01FF, 0x01FF, 0x0044,
		/* $ */	0x0000, 0x008C, 0x019E, 0x03FF, 0x03FF, 0x01E6, 0x00C4,
		/* % */	0x0000, 0x0082, 0x00C7, 0x0065, 0x00B7, 0x01DA, 0x014C, 0x01C6, 0x0082,
		/* & */	0x0000, 0x00E6, 0x01FF, 0x013F, 0x01E6, 0x01E0, 0x0120,
		/* ' */	0x0000, 0x0007, 0x0007,
		/* ( */	0x0000, 0x03FE, 0x07FF, 0x0401,
		/* ) */	0x0000, 0x0401, 0x07FF, 0x03FE,
		/* * */	0x0000, 0x000A, 0x000E, 0x000E, 0x000A,
		/* + */	0x0000, 0x0020, 0x0020, 0x00F8, 0x00F8, 0x0020, 0x0020,
		/* , */	0x0000, 0x0200, 0x0300, 0x0100,
		/* - */	0x0000, 0x0020, 0x0020, 0x0020,
		/* . */	0x0000, 0x0100, 0x0100,
		/* / */	0x0000, 0x0180, 0x01E0, 0x0078, 0x001F, 0x0007,
		/* 0 */	0x0000, 0x00FE, 0x01FF, 0x0101, 0x0101, 0x01FF, 0x00FE,
		/* 1 */	0x0000, 0x0002, 0x0002, 0x01FF, 0x01FF, 0x0000, 0x0000,
		/* 2 */	0x0000, 0x0182, 0x01C3, 0x0161, 0x0131, 0x011F, 0x010E,
		/* 3 */	0x0000, 0x0082, 0x0183, 0x0111, 0x0111, 0x01FF, 0x00EE,
		/* 4 */	0x0000, 0x0060, 0x0078, 0x005E, 0x01FF, 0x01FF, 0x0040,
		/* 5 */	0x0000, 0x009F, 0x019F, 0x0109, 0x0109, 0x01F9, 0x00F1,
		/* 6 */	0x0000, 0x00FE, 0x01FF, 0x0111, 0x0111, 0x01F3, 0x00E2,
		/* 7 */	0x0000, 0x0001, 0x01C1, 0x01F1, 0x003D, 0x000F, 0x0003,
		/* 8 */	0x0000, 0x00EE, 0x01FF, 0x0111, 0x0111, 0x01FF, 0x00EE,
		/* 9 */	0x0000, 0x008E, 0x019F, 0x0111, 0x0111, 0x01FF, 0x00FE,
		/* : */	0x0000, 0x0108, 0x0108,
		/* ; */	0x0000, 0x0200, 0x0308, 0x0108,
		/* < */	0x0000, 0x0020, 0x0070, 0x00D8, 0x018C, 0x0104,
		/* = */	0x0000, 0x0050, 0x0050, 0x0050, 0x0050, 0x0050, 0x0050,
		/* > */	0x0000, 0x0104, 0x018C, 0x00D8, 0x0070, 0x0020,
		/* ? */	0x0000, 0x0002, 0x0003, 0x0161, 0x0171, 0x001F, 0x000E,
		/* @ */	0x0000, 0x0078, 0x01FE, 0x0186, 0x0333, 0x0279, 0x0249, 0x0279, 0x027B, 0x0246, 0x007E, 0x0078,
		/* A */	0x0180, 0x01F0, 0x007C, 0x004F, 0x004F, 0x007C, 0x01F0, 0x0180,
		/* B */	0x0000, 0x01FF, 0x01FF, 0x0111, 0x0111, 0x01FF, 0x00EE,
		/* C */	0x0000, 0x00FE, 0x01FF, 0x0101, 0x0101, 0x0101, 0x0183, 0x0082,
		/* D */	0x0000, 0x01FF, 0x01FF, 0x0101, 0x0101, 0x0183, 0x00FE, 0x007C,
		/* E */	0x0000, 0x01FF, 0x01FF, 0x0111, 0x0111, 0x0111, 0x0101,
		/* F */	0x0000, 0x01FF, 0x01FF, 0x0011, 0x0011, 0x0011, 0x0001,
		/* G */	0x0000, 0x00FE, 0x01FF, 0x0101, 0x0111, 0x0191, 0x01F3, 0x01F2,
		/* H */	0x0000, 0x01FF, 0x01FF, 0x0010, 0x0010, 0x0010, 0x01FF, 0x01FF,
		/* I */	0x0000, 0x01FF, 0x01FF,
		/* J */	0x00C0, 0x01C0, 0x0100, 0x01FF, 0x00FF,
		/* K */	0x0000, 0x01FF, 0x01FF, 0x003C, 0x0066, 0x00C3, 0x0181, 0x0100,
		/* L */	0x0000, 0x01FF, 0x01FF, 0x0100, 0x0100, 0x0100, 0x0100,
		/* M */	0x0000, 0x01FF, 0x01FF, 0x003C, 0x00F0, 0x00F0, 0x003C, 0x01FF, 0x01FF,
		/* N */	0x0000, 0x01FF, 0x01FF, 0x001E, 0x0038, 0x00E0, 0x01FF, 0x01FF,
		/* O */	0x0000, 0x00FE, 0x01FF, 0x0101, 0x0101, 0x0101, 0x01FF, 0x00FE,
		/* P */	0x0000, 0x01FF, 0x01FF, 0x0011, 0x0011, 0x0011, 0x001F, 0x000E,
		/* Q */	0x0000, 0x00FE, 0x01FF, 0x0101, 0x0141, 0x01C1, 0x03FF, 0x02FE,
		/* R */	0x0000, 0x01FF, 0x01FF, 0x0011, 0x0011, 0x0011, 0x01FF, 0x01EE,
		/* S */	0x0000, 0x008E, 0x019F, 0x0111, 0x0111, 0x01F3, 0x00E2,
		/* T */	0x0000, 0x0001, 0x0001, 0x01FF, 0x01FF, 0x0001, 0x0001,
		/* U */	0x0000, 0x00FF, 0x01FF, 0x0100, 0x0100, 0x0100, 0x01FF, 0x00FF,
		/* V */	0x0003, 0x001F, 0x007C, 0x01E0, 0x01E0, 0x007C, 0x001F, 0x0003,
		/* W */	0x0003, 0x001F, 0x007C, 0x01E0, 0x01E0, 0x007C, 0x007C, 0x01E0, 0x01E0, 0x007C, 0x001F, 0x0003,
		/* X */	0x0183, 0x01C7, 0x006C, 0x0038, 0x0038, 0x006C, 0x01C7, 0x0183,
		/* Y */	0x0003, 0x0007, 0x000C, 0x01F8, 0x01F8, 0x000C, 0x0007, 0x0003,
		/* Z */	0x0181, 0x01C1, 0x0161, 0x0131, 0x0119, 0x010D, 0x0107, 0x0103,
		/* [ */	0x0000, 0x07FF, 0x07FF, 0x0401,
		/* \ */	0x0000, 0x0007, 0x001F, 0x0078, 0x01E0, 0x0180,
		/* ] */	0x0000, 0x0401, 0x07FF, 0x07FF,
		/* ^ */	0x0000, 0x0002, 0x0003, 0x0001, 0x0001, 0x0003, 0x0002,
		/* _ */	0x0400, 0x0400, 0x0400, 0x0400, 0x0400, 0x0400, 0x0400,
		/* ` */	0x0000, 0x0001, 0x0003, 0x0002,
		/* a */	0x0000, 0x00C0, 0x01E8, 0x0128, 0x0128, 0x01F8, 0x01F0,
		/* b */	0x0000, 0x01FF, 0x01FF, 0x0108, 0x0108, 0x01F8, 0x00F0,
		/* c */	0x0000, 0x00F0, 0x01F8, 0x0108, 0x0108, 0x0198, 0x0090,
		/* d */	0x0000, 0x00F0, 0x01F8, 0x0108, 0x0108, 0x01FF, 0x01FF,
		/* e */	0x0000, 0x00F0, 0x01F8, 0x0128, 0x0128, 0x01B8, 0x00B0,
		/* f */	0x0000, 0x01FE, 0x01FF, 0x0009,
		/* g */	0x0000, 0x04F0, 0x05F8, 0x0508, 0x0508, 0x07F8, 0x03F8,
		/* h */	0x0000, 0x01FF, 0x01FF, 0x0018, 0x0008, 0x01F8, 0x01F0,
		/* i */	0x0000, 0x01F9, 0x01F9,
		/* j */	0x0000, 0x07F9, 0x07F9,
		/* k */	0x0000, 0x01FF, 0x01FF, 0x0070, 0x00D8, 0x0188, 0x0100,
		/* l */	0x0000, 0x01FF, 0x01FF,
		/* m */	0x0000, 0x01F8, 0x01F8, 0x0008, 0x01F8, 0x01F8, 0x0008, 0x01F8, 0x01F0,
		/* n */	0x0000, 0x01F8, 0x01F8, 0x0018, 0x0008, 0x01F8, 0x01F0,
		/* o */	0x0000, 0x00F0, 0x01F8, 0x0108, 0x0108, 0x01F8, 0x00F0,
		/* p */	0x0000, 0x07F8, 0x07F8, 0x0108, 0x0108, 0x01F8, 0x00F0,
		/* q */	0x0000, 0x00F0, 0x01F8, 0x0108, 0x0108, 0x07F8, 0x07F8,
		/* r */	0x0000, 0x01F8, 0x01F8, 0x0008,
		/* s */	0x0000, 0x0090, 0x01B8, 0x0168, 0x01D8, 0x0090,
		/* t */	0x0000, 0x00FE, 0x01FE, 0x0108,
		/* u */	0x0000, 0x00F8, 0x01F8, 0x0100, 0x0180, 0x01F8, 0x01F8,
		/* v */	0x0000, 0x0018, 0x0078, 0x01E0, 0x01E0, 0x0078, 0x0018,
		/* w */	0x0000, 0x0078, 0x01F8, 0x01E0, 0x0078, 0x0078, 0x01E0, 0x01F8, 0x0078,
		/* x */	0x0000, 0x0198, 0x01F8, 0x0060, 0x01F8, 0x0198,
		/* y */	0x0400, 0x0478, 0x07F8, 0x0380, 0x00F8, 0x0078,
		/* z */	0x0000, 0x0188, 0x01C8, 0x0168, 0x0138, 0x0118,
		/* { */	0x0000, 0x0010, 0x01FF, 0x03EF, 0x0200,
		/* | */	0x0000, 0x03FF, 0x03FF,
		/* } */	0x0000, 0x0200, 0x03EF, 0x01FF, 0x0010,
		/* ~ */	0x0000, 0x0004, 0x0006, 0x0002, 0x0006, 0x0004, 0x0006, 0x0002
	};
#endif

/* fontLarger - Tahoma, 11, Bold */
#if GDISP_INCLUDE_FONT_LARGER
    /* Forward Declarations of internal arrays */
    static const uint8_t        fontLarger_Widths[];
    static const uint16_t       fontLarger_Offsets[];
    static const fontcolumn_t   fontLarger_Data[];

    static const struct font fontLarger = {
									"Larger",
									12, 1, 13, 2, 2, 13, ' ', '~', 1, 1,
									fontLarger_Widths,
									fontLarger_Offsets,
									fontLarger_Data};
    static const struct font fontLargerDouble = {
									"Larger Double",
									12, 1, 13, 2, 2, 13, ' ', '~', 2, 2,
									fontLarger_Widths,
									fontLarger_Offsets,
									fontLarger_Data};
    static const struct font fontLargerNarrow = {
									"Larger Narrow",
									12, 1, 13, 2, 2, 13, ' ', '~', 1, 2,
									fontLarger_Widths,
									fontLarger_Offsets,
									fontLarger_Data};
	static const uint8_t fontLarger_Widths[] = {
		2, 3, 5, 8, 7, 13, 8, 2, 4, 4, 7, 8, 3, 4, 3, 5,
		7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 3, 3, 9, 8, 9, 6,
		9, 8, 7, 7, 8, 6, 5, 7, 8, 4, 5, 7, 6, 10, 7, 8,
		7, 8, 8, 7, 6, 7, 7, 11, 7, 6, 6, 4, 5, 4, 9, 8,
		5, 6, 7, 5, 7, 6, 5, 7, 7, 2, 3, 6, 2, 10, 7, 7,
		7, 7, 4, 5, 5, 7, 6, 10, 6, 6, 5, 6, 4, 6, 9, 0
	};
	static const uint16_t fontLarger_Offsets[] = {
		0, 2, 5, 10, 18, 25, 38, 46,
		48, 52, 56, 63, 71, 74, 78, 81,
		86, 93, 100, 107, 114, 121, 128, 135,
		142, 149, 156, 159, 162, 171, 179, 188,
		194, 203, 211, 218, 225, 233, 239, 244,
		251, 259, 263, 268, 275, 281, 291, 298,
		306, 313, 321, 329, 336, 342, 349, 356,
		367, 374, 380, 386, 390, 395, 399, 408,
		416, 421, 427, 434, 439, 446, 452, 457,
		464, 471, 473, 476, 482, 484, 494, 501,
		508, 515, 522, 526, 531, 536, 543, 549,
		559, 565, 571, 576, 582, 586, 592, 0
	};
	static const fontcolumn_t fontLarger_Data[] = {
		/*   */	0x0000, 0x0000,
		/* ! */	0x0000, 0x037E, 0x037E,
		/* " */	0x0007, 0x0007, 0x0000, 0x0007, 0x0007,
		/* # */	0x00C0, 0x03D8, 0x00F8, 0x00DE, 0x03D8, 0x00F8, 0x00DE, 0x0018,
		/* $ */	0x0118, 0x023C, 0x0264, 0x0FFF, 0x0264, 0x03C4, 0x0188,
		/* % */	0x001C, 0x003E, 0x0022, 0x023E, 0x011C, 0x00C0, 0x0020, 0x0018, 0x01C4, 0x03E2, 0x0220, 0x03E0,
				0x01C0,
		/* & */	0x01CC, 0x03FE, 0x0232, 0x0272, 0x03DE, 0x018C, 0x03E0, 0x0260,
		/* ' */	0x0007, 0x0007,
		/* ( */	0x01F8, 0x07FE, 0x0E07, 0x0801,
		/* ) */	0x0801, 0x0E07, 0x07FE, 0x01F8,
		/* * */	0x0000, 0x000A, 0x0004, 0x001F, 0x001F, 0x0004, 0x000A,
		/* + */	0x0000, 0x0020, 0x0020, 0x0020, 0x01FC, 0x0020, 0x0020, 0x0020,
		/* , */	0x0000, 0x0F00, 0x0700,
		/* - */	0x0020, 0x0020, 0x0020, 0x0020,
		/* . */	0x0000, 0x0300, 0x0300,
		/* / */	0x0C00, 0x0380, 0x0060, 0x001C, 0x0003,
		/* 0 */	0x01FC, 0x03FE, 0x0202, 0x0202, 0x0202, 0x03FE, 0x01FC,
		/* 1 */	0x0000, 0x0204, 0x0204, 0x03FE, 0x03FE, 0x0200, 0x0200,
		/* 2 */	0x0204, 0x0302, 0x0382, 0x02C2, 0x0262, 0x023E, 0x021C,
		/* 3 */	0x0104, 0x0202, 0x0222, 0x0222, 0x0222, 0x03FE, 0x01DC,
		/* 4 */	0x0060, 0x0050, 0x0048, 0x0044, 0x03FE, 0x03FE, 0x0040,
		/* 5 */	0x0100, 0x021E, 0x021E, 0x0212, 0x0212, 0x03F2, 0x01E2,
		/* 6 */	0x01F8, 0x03FC, 0x0216, 0x0212, 0x0212, 0x03F2, 0x01E0,
		/* 7 */	0x0002, 0x0002, 0x0382, 0x03E2, 0x007A, 0x001E, 0x0006,
		/* 8 */	0x01DC, 0x03FE, 0x0222, 0x0222, 0x0222, 0x03FE, 0x01DC,
		/* 9 */	0x003C, 0x027E, 0x0242, 0x0242, 0x0342, 0x01FE, 0x00FC,
		/* : */	0x0000, 0x0318, 0x0318,
		/* ; */	0x0000, 0x0F18, 0x0718,
		/* < */	0x0000, 0x0060, 0x0060, 0x0090, 0x0090, 0x0108, 0x0108, 0x0204, 0x0204,
		/* = */	0x0000, 0x0090, 0x0090, 0x0090, 0x0090, 0x0090, 0x0090, 0x0090,
		/* > */	0x0000, 0x0204, 0x0204, 0x0108, 0x0108, 0x0090, 0x0090, 0x0060, 0x0060,
		/* ? */	0x0004, 0x0002, 0x0362, 0x0372, 0x001E, 0x000C,
		/* @ */	0x01F8, 0x0204, 0x04F2, 0x05FA, 0x050A, 0x04FA, 0x05FA, 0x0104, 0x00F8,
		/* A */	0x0380, 0x03F0, 0x00FC, 0x008E, 0x008E, 0x00FC, 0x03F0, 0x0380,
		/* B */	0x03FE, 0x03FE, 0x0222, 0x0222, 0x0222, 0x03FE, 0x01DC,
		/* C */	0x01FC, 0x03FE, 0x0202, 0x0202, 0x0202, 0x0202, 0x018C,
		/* D */	0x03FE, 0x03FE, 0x0202, 0x0202, 0x0202, 0x0306, 0x01FC, 0x00F8,
		/* E */	0x03FE, 0x03FE, 0x0222, 0x0222, 0x0222, 0x0222,
		/* F */	0x03FE, 0x03FE, 0x0022, 0x0022, 0x0022,
		/* G */	0x01FC, 0x03FE, 0x0202, 0x0202, 0x0222, 0x03E2, 0x03EC,
		/* H */	0x03FE, 0x03FE, 0x0020, 0x0020, 0x0020, 0x0020, 0x03FE, 0x03FE,
		/* I */	0x0202, 0x03FE, 0x03FE, 0x0202,
		/* J */	0x0200, 0x0202, 0x0202, 0x03FE, 0x01FE,
		/* K */	0x03FE, 0x03FE, 0x0070, 0x00D8, 0x018C, 0x0306, 0x0202,
		/* L */	0x03FE, 0x03FE, 0x0200, 0x0200, 0x0200, 0x0200,
		/* M */	0x03FE, 0x000E, 0x001C, 0x0038, 0x0070, 0x0030, 0x0018, 0x000C, 0x03FE, 0x03FE,
		/* N */	0x03FE, 0x000E, 0x001C, 0x0070, 0x01E0, 0x0380, 0x03FE,
		/* O */	0x01FC, 0x03FE, 0x0202, 0x0202, 0x0202, 0x0202, 0x03FE, 0x01FC,
		/* P */	0x03FE, 0x03FE, 0x0042, 0x0042, 0x0042, 0x007E, 0x003C,
		/* Q */	0x01FC, 0x03FE, 0x0202, 0x0202, 0x0602, 0x0E02, 0x0BFE, 0x09FC,
		/* R */	0x03FE, 0x03FE, 0x0022, 0x0062, 0x00E2, 0x01BE, 0x031C, 0x0200,
		/* S */	0x019C, 0x023E, 0x0222, 0x0222, 0x0222, 0x03E2, 0x01CC,
		/* T */	0x0002, 0x0002, 0x03FE, 0x03FE, 0x0002, 0x0002,
		/* U */	0x01FE, 0x03FE, 0x0200, 0x0200, 0x0200, 0x03FE, 0x01FE,
		/* V */	0x000E, 0x007E, 0x03F0, 0x0380, 0x03F0, 0x007E, 0x000E,
		/* W */	0x001E, 0x00FE, 0x03E0, 0x03E0, 0x00FC, 0x000E, 0x00FC, 0x03E0, 0x03E0, 0x00FE, 0x001E,
		/* X */	0x0306, 0x038E, 0x00F8, 0x0070, 0x00F8, 0x038E, 0x0306,
		/* Y */	0x000E, 0x003E, 0x03F0, 0x03F0, 0x003E, 0x000E,
		/* Z */	0x0382, 0x03C2, 0x0262, 0x0232, 0x021E, 0x020E,
		/* [ */	0x0FFF, 0x0FFF, 0x0801, 0x0801,
		/* \ */	0x0003, 0x001C, 0x0060, 0x0380, 0x0C00,
		/* ] */	0x0801, 0x0801, 0x0FFF, 0x0FFF,
		/* ^ */	0x0000, 0x0010, 0x0008, 0x0004, 0x0002, 0x0002, 0x0004, 0x0008, 0x0010,
		/* _ */	0x0800, 0x0800, 0x0800, 0x0800, 0x0800, 0x0800, 0x0800, 0x0800,
		/* ` */	0x0000, 0x0000, 0x0001, 0x0003, 0x0002,
		/* a */	0x0180, 0x03D0, 0x0248, 0x0248, 0x03F8, 0x03F0,
		/* b */	0x03FF, 0x03FF, 0x0210, 0x0208, 0x0208, 0x03F8, 0x01F0,
		/* c */	0x01F0, 0x03F8, 0x0208, 0x0208, 0x0208,
		/* d */	0x01F0, 0x03F8, 0x0208, 0x0208, 0x0108, 0x03FF, 0x03FF,
		/* e */	0x01F0, 0x03F8, 0x0248, 0x0248, 0x0278, 0x0170,
		/* f */	0x0008, 0x03FE, 0x03FF, 0x0009, 0x0001,
		/* g */	0x01F0, 0x0BF8, 0x0A08, 0x0A08, 0x0908, 0x0FF8, 0x07F8,
		/* h */	0x03FF, 0x03FF, 0x0010, 0x0008, 0x0008, 0x03F8, 0x03F0,
		/* i */	0x03FA, 0x03FA,
		/* j */	0x0808, 0x0FFA, 0x07FA,
		/* k */	0x03FF, 0x03FF, 0x00E0, 0x01B0, 0x0318, 0x0208,
		/* l */	0x03FF, 0x03FF,
		/* m */	0x03F8, 0x03F8, 0x0008, 0x0008, 0x03F8, 0x03F0, 0x0008, 0x0008, 0x03F8, 0x03F0,
		/* n */	0x03F8, 0x03F8, 0x0010, 0x0008, 0x0008, 0x03F8, 0x03F0,
		/* o */	0x01F0, 0x03F8, 0x0208, 0x0208, 0x0208, 0x03F8, 0x01F0,
		/* p */	0x0FF8, 0x0FF8, 0x0210, 0x0208, 0x0208, 0x03F8, 0x01F0,
		/* q */	0x01F0, 0x03F8, 0x0208, 0x0208, 0x0108, 0x0FF8, 0x0FF8,
		/* r */	0x03F8, 0x03F8, 0x0010, 0x0018,
		/* s */	0x0130, 0x0278, 0x0248, 0x03C8, 0x0190,
		/* t */	0x0008, 0x01FE, 0x03FE, 0x0208, 0x0208,
		/* u */	0x01F8, 0x03F8, 0x0200, 0x0200, 0x0100, 0x03F8, 0x03F8,
		/* v */	0x0038, 0x00F8, 0x03C0, 0x03C0, 0x00F8, 0x0038,
		/* w */	0x0018, 0x00F8, 0x03E0, 0x0380, 0x00F8, 0x00F8, 0x0380, 0x03E0, 0x00F8, 0x0018,
		/* x */	0x0318, 0x03B8, 0x00E0, 0x00E0, 0x03B8, 0x0318,
		/* y */	0x0038, 0x0CF8, 0x0FC0, 0x03C0, 0x00F8, 0x0038,
		/* z */	0x0388, 0x03C8, 0x0268, 0x0238, 0x0218,
		/* { */	0x0020, 0x0020, 0x07FE, 0x0FDF, 0x0801, 0x0801,
		/* | */	0x0000, 0x0000, 0x0FFF, 0x0FFF,
		/* } */	0x0801, 0x0801, 0x0FDF, 0x07FE, 0x0020, 0x0020,
		/* ~ */	0x00E0, 0x0030, 0x0030, 0x0030, 0x0060, 0x00C0, 0x00C0, 0x00C0, 0x0070
	};
#endif

/* fontUI1 - UI Font 1 Medium Bold */
#if GDISP_INCLUDE_FONT_UI1
	/* Forward Declarations of internal arrays */
    static const uint8_t        fontUI1_Widths[];
    static const uint16_t       fontUI1_Offsets[];
    static const fontcolumn_t   fontUI1_Data[];

    static const struct font fontUI1 = {
									"UI1",
									13, 0, 15, 2, 3, 13, ' ', '~', 1, 1,
									fontUI1_Widths,
									fontUI1_Offsets,
									fontUI1_Data};
    static const struct font fontUI1Double = {
									"UI1 Double",
									13, 0, 15, 2, 3, 13, ' ', '~', 2, 2,
									fontUI1_Widths,
									fontUI1_Offsets,
									fontUI1_Data};
    static const struct font fontUI1Narrow = {
									"UI1 Narrow",
									13, 0, 15, 2, 3, 13, ' ', '~', 1, 2,
									fontUI1_Widths,
									fontUI1_Offsets,
									fontUI1_Data};

	static const uint8_t fontUI1_Widths[] = {
		3, 3, 6, 8, 7, 13, 9, 3, 5, 5, 6, 8, 3, 5, 3, 7,
		7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 3, 3, 8, 8, 8, 6,
		10, 8, 7, 7, 8, 7, 7, 8, 8, 5, 5, 7, 7, 9, 8, 8,
		7, 8, 8, 7, 8, 8, 7, 11, 7, 7, 7, 5, 7, 5, 9, 8,
		5, 7, 7, 6, 7, 7, 5, 7, 7, 3, 4, 7, 3, 11, 7, 7,
		7, 7, 6, 6, 5, 7, 7, 9, 7, 7, 6, 7, 4, 7, 8, 0
	};
	static const uint16_t fontUI1_Offsets[] = {
		0, 3, 6, 12, 20, 27, 40, 49,
		52, 57, 62, 68, 76, 79, 84, 87,
		94, 101, 108, 115, 122, 129, 136, 143,
		150, 157, 164, 167, 170, 178, 186, 194,
		200, 210, 218, 225, 232, 240, 247, 254,
		262, 270, 275, 280, 287, 294, 303, 311,
		319, 326, 334, 342, 349, 357, 365, 372,
		383, 390, 397, 404, 409, 416, 421, 430,
		438, 443, 450, 457, 463, 470, 477, 482,
		489, 496, 499, 503, 510, 513, 524, 531,
		538, 545, 552, 558, 564, 569, 576, 583,
		592, 599, 606, 612, 619, 623, 630, 0
	};
	static const fontcolumn_t fontUI1_Data[] = {
		/*   */	0x0000, 0x0000, 0x0000,
		/* ! */	0x0000, 0x02FC, 0x02FC,
		/* " */	0x0000, 0x000E, 0x000E, 0x0000, 0x000E, 0x000E,
		/* # */	0x0000, 0x0080, 0x0390, 0x00F0, 0x039C, 0x00F0, 0x009C, 0x0010,
		/* $ */	0x0000, 0x0130, 0x0278, 0x0FC8, 0x027E, 0x03C8, 0x0190,
		/* % */	0x0000, 0x0038, 0x007C, 0x0044, 0x007C, 0x0338, 0x00C0, 0x0030, 0x01CC, 0x03E0, 0x0220, 0x03E0,
				0x01C0,
		/* & */	0x0000, 0x01D8, 0x03FC, 0x0224, 0x027C, 0x02D8, 0x0180, 0x0360, 0x0220,
		/* ' */	0x0000, 0x000E, 0x000E,
		/* ( */	0x0000, 0x01F0, 0x07FC, 0x0E0E, 0x0802,
		/* ) */	0x0000, 0x0802, 0x0E0E, 0x07FC, 0x01F0,
		/* * */	0x0000, 0x0014, 0x0008, 0x003E, 0x0008, 0x0014,
		/* + */	0x0000, 0x0040, 0x0040, 0x0040, 0x03F8, 0x0040, 0x0040, 0x0040,
		/* , */	0x0000, 0x0F00, 0x0700,
		/* - */	0x0000, 0x0040, 0x0040, 0x0040, 0x0040,
		/* . */	0x0000, 0x0300, 0x0300,
		/* / */	0x0000, 0x0C00, 0x0F00, 0x03E0, 0x00F8, 0x001E, 0x0006,
		/* 0 */	0x0000, 0x01F8, 0x03FC, 0x0204, 0x0204, 0x03FC, 0x01F8,
		/* 1 */	0x0000, 0x0000, 0x0208, 0x03FC, 0x03FC, 0x0200, 0x0000,
		/* 2 */	0x0000, 0x0308, 0x038C, 0x02C4, 0x0264, 0x023C, 0x0218,
		/* 3 */	0x0000, 0x0108, 0x030C, 0x0224, 0x0224, 0x03FC, 0x01D8,
		/* 4 */	0x0000, 0x00C0, 0x00A0, 0x0090, 0x03F8, 0x03FC, 0x0080,
		/* 5 */	0x0000, 0x0100, 0x033C, 0x023C, 0x0224, 0x03E4, 0x01C4,
		/* 6 */	0x0000, 0x01F0, 0x03F8, 0x022C, 0x0224, 0x03E4, 0x01C0,
		/* 7 */	0x0000, 0x0004, 0x0304, 0x03C4, 0x00F4, 0x003C, 0x000C,
		/* 8 */	0x0000, 0x01D8, 0x03FC, 0x0224, 0x0224, 0x03FC, 0x01D8,
		/* 9 */	0x0000, 0x0038, 0x027C, 0x0244, 0x0344, 0x01FC, 0x00F8,
		/* : */	0x0000, 0x0330, 0x0330,
		/* ; */	0x0000, 0x0F30, 0x0730,
		/* < */	0x0000, 0x0040, 0x00A0, 0x00A0, 0x0110, 0x0110, 0x0208, 0x0208,
		/* = */	0x0000, 0x0090, 0x0090, 0x0090, 0x0090, 0x0090, 0x0090, 0x0090,
		/* > */	0x0000, 0x0208, 0x0208, 0x0110, 0x0110, 0x00A0, 0x00A0, 0x0040,
		/* ? */	0x0000, 0x0008, 0x02C4, 0x02E4, 0x003C, 0x0018,
		/* @ */	0x0000, 0x01F0, 0x0208, 0x04E4, 0x05F4, 0x0514, 0x05F4, 0x05F4, 0x0104, 0x00F8,
		/* A */	0x0000, 0x0380, 0x03F0, 0x00FC, 0x008C, 0x00FC, 0x03F0, 0x0380,
		/* B */	0x0000, 0x03FC, 0x03FC, 0x0224, 0x0224, 0x03FC, 0x01D8,
		/* C */	0x0000, 0x01F8, 0x03FC, 0x0204, 0x0204, 0x0204, 0x0108,
		/* D */	0x0000, 0x03FC, 0x03FC, 0x0204, 0x0204, 0x030C, 0x01F8, 0x00F0,
		/* E */	0x0000, 0x03FC, 0x03FC, 0x0224, 0x0224, 0x0224, 0x0224,
		/* F */	0x0000, 0x03FC, 0x03FC, 0x0024, 0x0024, 0x0024, 0x0024,
		/* G */	0x0000, 0x01F8, 0x03FC, 0x0204, 0x0204, 0x0244, 0x03C4, 0x03C8,
		/* H */	0x0000, 0x03FC, 0x03FC, 0x0020, 0x0020, 0x0020, 0x03FC, 0x03FC,
		/* I */	0x0000, 0x0204, 0x03FC, 0x03FC, 0x0204,
		/* J */	0x0200, 0x0204, 0x0204, 0x03FC, 0x01FC,
		/* K */	0x0000, 0x03FC, 0x03FC, 0x00F0, 0x0198, 0x030C, 0x0204,
		/* L */	0x0000, 0x03FC, 0x03FC, 0x0200, 0x0200, 0x0200, 0x0200,
		/* M */	0x0000, 0x03FC, 0x001C, 0x0038, 0x0070, 0x0020, 0x0010, 0x03F8, 0x03FC,
		/* N */	0x0000, 0x03FC, 0x0018, 0x0030, 0x0060, 0x00C0, 0x0180, 0x03FC,
		/* O */	0x0000, 0x01F8, 0x03FC, 0x0204, 0x0204, 0x0204, 0x03FC, 0x01F8,
		/* P */	0x0000, 0x03FC, 0x03FC, 0x0044, 0x0044, 0x007C, 0x0038,
		/* Q */	0x0000, 0x01F8, 0x03FC, 0x0204, 0x0604, 0x0E04, 0x0BFC, 0x09F8,
		/* R */	0x0000, 0x03FC, 0x03FC, 0x0044, 0x00C4, 0x01FC, 0x0338, 0x0200,
		/* S */	0x0000, 0x0138, 0x027C, 0x0264, 0x0264, 0x03E4, 0x01C8,
		/* T */	0x0004, 0x0004, 0x0004, 0x03FC, 0x03FC, 0x0004, 0x0004, 0x0004,
		/* U */	0x0000, 0x01FC, 0x03FC, 0x0200, 0x0200, 0x0200, 0x03FC, 0x01FC,
		/* V */	0x0000, 0x001C, 0x00FC, 0x03E0, 0x03E0, 0x00FC, 0x001C,
		/* W */	0x0000, 0x001C, 0x00FC, 0x03E0, 0x03C0, 0x007C, 0x007C, 0x03C0, 0x03E0, 0x00FC, 0x001C,
		/* X */	0x0000, 0x030C, 0x039C, 0x00F0, 0x00F0, 0x039C, 0x030C,
		/* Y */	0x0000, 0x000C, 0x003C, 0x03F0, 0x03F0, 0x003C, 0x000C,
		/* Z */	0x0000, 0x0384, 0x03C4, 0x02E4, 0x0274, 0x023C, 0x021C,
		/* [ */	0x0000, 0x0FFE, 0x0FFE, 0x0802, 0x0802,
		/* \ */	0x0000, 0x0006, 0x001E, 0x00F8, 0x03E0, 0x0F00, 0x0C00,
		/* ] */	0x0000, 0x0802, 0x0802, 0x0FFE, 0x0FFE,
		/* ^ */	0x0000, 0x0020, 0x0030, 0x0018, 0x000C, 0x000C, 0x0018, 0x0030, 0x0020,
		/* _ */	0x0800, 0x0800, 0x0800, 0x0800, 0x0800, 0x0800, 0x0800, 0x0800,
		/* ` */	0x0000, 0x0000, 0x0002, 0x0006, 0x0004,
		/* a */	0x0000, 0x0180, 0x03D0, 0x0250, 0x0250, 0x03F0, 0x03E0,
		/* b */	0x0000, 0x03FE, 0x03FE, 0x0210, 0x0210, 0x03F0, 0x01E0,
		/* c */	0x0000, 0x01E0, 0x03F0, 0x0210, 0x0210, 0x0210,
		/* d */	0x0000, 0x01E0, 0x03F0, 0x0210, 0x0210, 0x03FE, 0x03FE,
		/* e */	0x0000, 0x01E0, 0x03F0, 0x0250, 0x0250, 0x0270, 0x0160,
		/* f */	0x0010, 0x03FC, 0x03FE, 0x0012, 0x0012,
		/* g */	0x0000, 0x01E0, 0x0BF0, 0x0A10, 0x0A10, 0x0FF0, 0x07F0,
		/* h */	0x0000, 0x03FE, 0x03FE, 0x0010, 0x0010, 0x03F0, 0x03E0,
		/* i */	0x0000, 0x03F4, 0x03F4,
		/* j */	0x0800, 0x0810, 0x0FF4, 0x07F4,
		/* k */	0x0000, 0x03FE, 0x03FE, 0x00C0, 0x01E0, 0x0330, 0x0210,
		/* l */	0x0000, 0x03FE, 0x03FE,
		/* m */	0x0000, 0x03F0, 0x03F0, 0x0010, 0x0010, 0x03F0, 0x03E0, 0x0010, 0x0010, 0x03F0, 0x03E0,
		/* n */	0x0000, 0x03F0, 0x03F0, 0x0010, 0x0010, 0x03F0, 0x03E0,
		/* o */	0x0000, 0x01E0, 0x03F0, 0x0210, 0x0210, 0x03F0, 0x01E0,
		/* p */	0x0000, 0x0FF0, 0x0FF0, 0x0210, 0x0210, 0x03F0, 0x01E0,
		/* q */	0x0000, 0x01E0, 0x03F0, 0x0210, 0x0210, 0x0FF0, 0x0FF0,
		/* r */	0x0000, 0x03F0, 0x03F0, 0x0020, 0x0030, 0x0030,
		/* s */	0x0000, 0x0260, 0x02F0, 0x02D0, 0x03D0, 0x0190,
		/* t */	0x0010, 0x01FC, 0x03FC, 0x0210, 0x0210,
		/* u */	0x0000, 0x01F0, 0x03F0, 0x0200, 0x0200, 0x03F0, 0x03F0,
		/* v */	0x0000, 0x0070, 0x01F0, 0x0380, 0x0380, 0x01F0, 0x0070,
		/* w */	0x0000, 0x00F0, 0x03F0, 0x0300, 0x00F0, 0x00F0, 0x0300, 0x03F0, 0x00F0,
		/* x */	0x0000, 0x0330, 0x03F0, 0x00C0, 0x00C0, 0x03F0, 0x0330,
		/* y */	0x0000, 0x0030, 0x0CF0, 0x0FC0, 0x03C0, 0x00F0, 0x0030,
		/* z */	0x0000, 0x0310, 0x0390, 0x02D0, 0x0270, 0x0230,
		/* { */	0x0000, 0x0040, 0x0040, 0x07FC, 0x0FBE, 0x0802, 0x0802,
		/* | */	0x0000, 0x0000, 0x0FFE, 0x0FFE,
		/* } */	0x0000, 0x0802, 0x0802, 0x0FBE, 0x07FC, 0x0040, 0x0040,
		/* ~ */	0x0000, 0x01C0, 0x0020, 0x0020, 0x00C0, 0x0100, 0x0100, 0x00E0
	};
#endif

/* fontUI1 - UI Font 2 Medium Bold */
#if GDISP_INCLUDE_FONT_UI2
	/* Forward Declarations of internal arrays */
	static const uint8_t        fontUI2_Widths[];
	static const uint16_t       fontUI2_Offsets[];
	static const fontcolumn_t   fontUI2_Data[];

	static const struct font fontUI2 = {
									"UI2",
									11, 1, 13, 2, 2, 12, ' ', '~', 1, 1,
									fontUI2_Widths,
									fontUI2_Offsets,
									fontUI2_Data};
	static const struct font fontUI2Double = {
									"UI2 Double",
									11, 1, 13, 2, 2, 12, ' ', '~', 2, 2,
									fontUI2_Widths,
									fontUI2_Offsets,
									fontUI2_Data};
	static const struct font fontUI2Narrow = {
									"UI2 Narrow",
									11, 1, 13, 2, 2, 12, ' ', '~', 1, 2,
									fontUI2_Widths,
									fontUI2_Offsets,
									fontUI2_Data};

	static const uint8_t fontUI2_Widths[] = {
		2, 2, 5, 8, 6, 12, 8, 2, 4, 4, 6, 8, 2, 4, 2, 5,
		6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 2, 2, 8, 8, 8, 5,
		9, 7, 6, 6, 7, 5, 5, 7, 7, 4, 5, 6, 5, 9, 6, 7,
		6, 7, 7, 6, 6, 7, 6, 10, 6, 6, 6, 4, 5, 4, 7, 7,
		4, 6, 6, 5, 6, 6, 4, 6, 6, 2, 3, 6, 2, 10, 6, 6,
		6, 6, 4, 5, 4, 6, 6, 8, 6, 6, 5, 6, 4, 6, 8, 0
	};
	static const uint16_t fontUI2_Offsets[] = {
		0, 2, 4, 9, 17, 23, 35, 43,
		45, 49, 53, 59, 67, 69, 73, 75,
		80, 86, 92, 98, 104, 110, 116, 122,
		128, 134, 140, 142, 144, 152, 160, 168,
		173, 182, 189, 195, 201, 208, 213, 218,
		225, 232, 236, 241, 247, 252, 261, 267,
		274, 280, 287, 294, 300, 306, 313, 319,
		329, 335, 341, 347, 351, 356, 360, 367,
		374, 378, 384, 390, 395, 401, 407, 411,
		417, 423, 425, 428, 434, 436, 446, 452,
		458, 464, 470, 474, 479, 483, 489, 495,
		503, 509, 515, 520, 526, 530, 536, 0
	};
	static const fontcolumn_t fontUI2_Data[] = {
		/*   */	0x0000, 0x0000,
		/* ! */	0x017E, 0x017E,
		/* " */	0x0007, 0x0007, 0x0000, 0x0007, 0x0007,
		/* # */	0x00C0, 0x03D8, 0x00F8, 0x00DE, 0x03D8, 0x00F8, 0x00DE, 0x0018,
		/* $ */	0x0098, 0x013C, 0x07E4, 0x013F, 0x01E4, 0x00C8,
		/* % */	0x001C, 0x003E, 0x0022, 0x003E, 0x019C, 0x0060, 0x0018, 0x00E6, 0x01F0, 0x0110, 0x01F0, 0x00E0,
		/* & */	0x00EC, 0x01FE, 0x0112, 0x013E, 0x016C, 0x00C0, 0x01B0, 0x0110,
		/* ' */	0x0007, 0x0007,
		/* ( */	0x00F8, 0x03FE, 0x0707, 0x0401,
		/* ) */	0x0401, 0x0707, 0x03FE, 0x00F8,
		/* * */	0x000A, 0x0004, 0x001F, 0x001F, 0x0004, 0x000A,
		/* + */	0x0000, 0x0020, 0x0020, 0x0020, 0x01FC, 0x0020, 0x0020, 0x0020,
		/* , */	0x0780, 0x0380,
		/* - */	0x0020, 0x0020, 0x0020, 0x0020,
		/* . */	0x0180, 0x0180,
		/* / */	0x0600, 0x0180, 0x0070, 0x000C, 0x0003,
		/* 0 */	0x00FC, 0x01FE, 0x0102, 0x0102, 0x01FE, 0x00FC,
		/* 1 */	0x0000, 0x0104, 0x01FE, 0x01FE, 0x0100, 0x0000,
		/* 2 */	0x0184, 0x01C6, 0x0162, 0x0132, 0x011E, 0x010C,
		/* 3 */	0x0084, 0x0186, 0x0112, 0x0112, 0x01FE, 0x00EC,
		/* 4 */	0x0060, 0x0050, 0x0048, 0x01FC, 0x01FE, 0x0040,
		/* 5 */	0x0080, 0x019E, 0x011E, 0x0112, 0x01F2, 0x00E2,
		/* 6 */	0x00FC, 0x01FE, 0x0112, 0x0112, 0x01F2, 0x00E0,
		/* 7 */	0x0002, 0x0002, 0x01C2, 0x01FA, 0x003E, 0x0006,
		/* 8 */	0x00EC, 0x01FE, 0x0112, 0x0112, 0x01FE, 0x00EC,
		/* 9 */	0x001C, 0x013E, 0x0122, 0x0122, 0x01FE, 0x00FC,
		/* : */	0x0198, 0x0198,
		/* ; */	0x0798, 0x0398,
		/* < */	0x0000, 0x0020, 0x0050, 0x0050, 0x0088, 0x0088, 0x0104, 0x0104,
		/* = */	0x0000, 0x0048, 0x0048, 0x0048, 0x0048, 0x0048, 0x0048, 0x0048,
		/* > */	0x0000, 0x0104, 0x0104, 0x0088, 0x0088, 0x0050, 0x0050, 0x0020,
		/* ? */	0x0004, 0x0162, 0x0172, 0x001E, 0x000C,
		/* @ */	0x00F8, 0x0104, 0x0272, 0x02FA, 0x028A, 0x027A, 0x02FA, 0x0084, 0x0078,
		/* A */	0x01C0, 0x01F8, 0x007E, 0x0046, 0x007E, 0x01F8, 0x01C0,
		/* B */	0x01FE, 0x01FE, 0x0112, 0x0112, 0x01FE, 0x00EC,
		/* C */	0x00FC, 0x01FE, 0x0102, 0x0102, 0x0102, 0x0102,
		/* D */	0x01FE, 0x01FE, 0x0102, 0x0102, 0x0186, 0x00FC, 0x0078,
		/* E */	0x01FE, 0x01FE, 0x0112, 0x0112, 0x0112,
		/* F */	0x01FE, 0x01FE, 0x0012, 0x0012, 0x0012,
		/* G */	0x00FC, 0x01FE, 0x0102, 0x0102, 0x0122, 0x01E2, 0x01E2,
		/* H */	0x01FE, 0x01FE, 0x0010, 0x0010, 0x0010, 0x01FE, 0x01FE,
		/* I */	0x0102, 0x01FE, 0x01FE, 0x0102,
		/* J */	0x0100, 0x0102, 0x0102, 0x01FE, 0x00FE,
		/* K */	0x01FE, 0x01FE, 0x0078, 0x00CC, 0x0186, 0x0102,
		/* L */	0x01FE, 0x01FE, 0x0100, 0x0100, 0x0100,
		/* M */	0x01FE, 0x000E, 0x001C, 0x0038, 0x0030, 0x0018, 0x000C, 0x01FE, 0x01FE,
		/* N */	0x01FE, 0x000E, 0x001C, 0x0038, 0x0070, 0x01FE,
		/* O */	0x00FC, 0x01FE, 0x0102, 0x0102, 0x0102, 0x01FE, 0x00FC,
		/* P */	0x01FE, 0x01FE, 0x0022, 0x0022, 0x003E, 0x001C,
		/* Q */	0x00FC, 0x01FE, 0x0102, 0x0302, 0x0702, 0x05FE, 0x04FC,
		/* R */	0x01FE, 0x01FE, 0x0022, 0x0062, 0x00FE, 0x019C, 0x0100,
		/* S */	0x011C, 0x013E, 0x0132, 0x0132, 0x01F2, 0x00E2,
		/* T */	0x0002, 0x0002, 0x01FE, 0x01FE, 0x0002, 0x0002,
		/* U */	0x00FE, 0x01FE, 0x0100, 0x0100, 0x0100, 0x01FE, 0x00FE,
		/* V */	0x000E, 0x007E, 0x01F0, 0x01F0, 0x007E, 0x000E,
		/* W */	0x000E, 0x007E, 0x01F0, 0x01E0, 0x003E, 0x003E, 0x01E0, 0x01F0, 0x007E, 0x000E,
		/* X */	0x0186, 0x01CE, 0x0078, 0x0078, 0x01CE, 0x0186,
		/* Y */	0x0006, 0x001E, 0x01F8, 0x01F8, 0x001E, 0x0006,
		/* Z */	0x01C2, 0x01E2, 0x0172, 0x013A, 0x011E, 0x010E,
		/* [ */	0x07FF, 0x07FF, 0x0401, 0x0401,
		/* \ */	0x0003, 0x000C, 0x0070, 0x0180, 0x0600,
		/* ] */	0x0401, 0x0401, 0x07FF, 0x07FF,
		/* ^ */	0x0010, 0x0008, 0x0004, 0x0002, 0x0004, 0x0008, 0x0010,
		/* _ */	0x0400, 0x0400, 0x0400, 0x0400, 0x0400, 0x0400, 0x0400,
		/* ` */	0x0000, 0x0001, 0x0003, 0x0002,
		/* a */	0x00C0, 0x01E8, 0x0128, 0x0128, 0x01F8, 0x01F0,
		/* b */	0x01FF, 0x01FF, 0x0108, 0x0108, 0x01F8, 0x00F0,
		/* c */	0x00F0, 0x01F8, 0x0108, 0x0108, 0x0108,
		/* d */	0x00F0, 0x01F8, 0x0108, 0x0108, 0x01FF, 0x01FF,
		/* e */	0x00F0, 0x01F8, 0x0128, 0x0128, 0x0138, 0x0130,
		/* f */	0x01FE, 0x01FF, 0x0009, 0x0001,
		/* g */	0x00F0, 0x05F8, 0x0508, 0x0508, 0x07F8, 0x03F8,
		/* h */	0x01FF, 0x01FF, 0x0008, 0x0008, 0x01F8, 0x01F0,
		/* i */	0x01FA, 0x01FA,
		/* j */	0x0408, 0x07FA, 0x03FA,
		/* k */	0x01FF, 0x01FF, 0x0060, 0x00F0, 0x0198, 0x0108,
		/* l */	0x01FF, 0x01FF,
		/* m */	0x01F8, 0x01F8, 0x0008, 0x0008, 0x01F8, 0x01F0, 0x0008, 0x0008, 0x01F8, 0x01F0,
		/* n */	0x01F8, 0x01F8, 0x0008, 0x0008, 0x01F8, 0x01F0,
		/* o */	0x00F0, 0x01F8, 0x0108, 0x0108, 0x01F8, 0x00F0,
		/* p */	0x07F8, 0x07F8, 0x0108, 0x0108, 0x01F8, 0x00F0,
		/* q */	0x00F0, 0x01F8, 0x0108, 0x0108, 0x07F8, 0x07F8,
		/* r */	0x01F8, 0x01F8, 0x0010, 0x0018,
		/* s */	0x0130, 0x0178, 0x0168, 0x01E8, 0x00C8,
		/* t */	0x00FE, 0x01FE, 0x0108, 0x0108,
		/* u */	0x00F8, 0x01F8, 0x0100, 0x0100, 0x01F8, 0x01F8,
		/* v */	0x0018, 0x0078, 0x01E0, 0x01E0, 0x0078, 0x0018,
		/* w */	0x0078, 0x01F8, 0x01C0, 0x0078, 0x0078, 0x01C0, 0x01F8, 0x0078,
		/* x */	0x0198, 0x01F8, 0x0060, 0x0060, 0x01F8, 0x0198,
		/* y */	0x0018, 0x0678, 0x07E0, 0x01E0, 0x0078, 0x0018,
		/* z */	0x0188, 0x01C8, 0x0168, 0x0138, 0x0118,
		/* { */	0x0020, 0x0020, 0x03FE, 0x07DF, 0x0401, 0x0401,
		/* | */	0x0000, 0x0000, 0x07FF, 0x07FF,
		/* } */	0x0401, 0x0401, 0x07DF, 0x03FE, 0x0020, 0x0020,
		/* ~ */	0x0060, 0x0010, 0x0010, 0x0030, 0x0060, 0x0040, 0x0040, 0x0030
	};
#endif

/*
	fontLargeNumbers:
		Large numbers font, height = 16 (including the decenders)
		Characters include:  0 - 9, -, +, ., %, :, Space, Comma
*/
#if GDISP_INCLUDE_FONT_LARGENUMBERS
	/* Forward Declarations of internal arrays */
    static const uint8_t        fontLargeNumbers_Widths[];
    static const uint16_t       fontLargeNumbers_Offsets[];
    static const fontcolumn_t   fontLargeNumbers_Data[];

    static const struct font fontLargeNumbers = {
									"LargeNumbers",
									16, 2, 21, 1, 3, 15, '%', ':', 1, 1,
									fontLargeNumbers_Widths,
									fontLargeNumbers_Offsets,
									fontLargeNumbers_Data};
    static const struct font fontLargeNumbersDouble = {
									"LargeNumbers Double",
									16, 2, 21, 1, 3, 15, '%', ':', 2, 2,
									fontLargeNumbers_Widths,
									fontLargeNumbers_Offsets,
									fontLargeNumbers_Data};
    static const struct font fontLargeNumbersNarrow = {
									"LargeNumbers Narrow", 16, 2, 21, 1, 3, 15, '%', ':', 1, 2,
									fontLargeNumbers_Widths,
									fontLargeNumbers_Offsets,
									fontLargeNumbers_Data};

	static const uint8_t fontLargeNumbers_Widths[] = {
		15, 0, 0, 0, 0, 0, 11, 3, 6, 3, 0, 10, 10, 10, 10, 10,
		10, 10, 10, 10, 10, 4, 0, 0
	};
	static const uint16_t fontLargeNumbers_Offsets[] = {
		0, 0, 0, 0, 0, 0, 15, 26,
		29, 35, 0, 38, 48, 58, 68, 78,
		88, 98, 108, 118, 128, 138, 0, 0
	};
	static const fontcolumn_t fontLargeNumbers_Data[] = {
		/* % */	0x007E, 0x00FF, 0x00C3, 0x80C3, 0xE0FF, 0x7C7E, 0x1F00, 0x07C0, 0x00F0, 0x7E3E, 0xFF0F, 0xC303,
				0xC300, 0xFF00, 0x7E00,
		/* + */	0x01C0, 0x01C0, 0x01C0, 0x01C0, 0x1FFC, 0x1FFC, 0x1FFC, 0x01C0, 0x01C0, 0x01C0, 0x01C0,
		/* , */	0x7000, 0x7000, 0xF000,
		/* - */	0x0700, 0x0700, 0x0700, 0x0700, 0x0700, 0x0700,
		/* . */	0x7000, 0x7000, 0x7000,
		/* 0 */	0x0FF8, 0x3FFE, 0x3FFE, 0x7007, 0x6003, 0x6003, 0x7007, 0x3FFE, 0x3FFE, 0x0FF8,
		/* 1 */	0x0000, 0x0070, 0x0038, 0x0038, 0x001C, 0x7FFF, 0x7FFF, 0x7FFF, 0x0000, 0x0000,
		/* 2 */	0x600C, 0x700E, 0x7C0F, 0x7E07, 0x6F03, 0x6783, 0x63C7, 0x61FF, 0x60FE, 0x603C,
		/* 3 */	0x180C, 0x380E, 0x780F, 0x70C3, 0x60C3, 0x60E3, 0x71FF, 0x3FFE, 0x3F3C, 0x0E00,
		/* 4 */	0x0F00, 0x0DC0, 0x0CE0, 0x0C38, 0x0C1E, 0x7FFF, 0x7FFF, 0x7FFF, 0x0C00, 0x0C00,
		/* 5 */	0x18C0, 0x38FC, 0x78FF, 0x707F, 0x6063, 0x6063, 0x70E3, 0x3FE3, 0x3FC3, 0x0F80,
		/* 6 */	0x0FF8, 0x3FFE, 0x3FFE, 0x70C7, 0x6063, 0x6063, 0x70E7, 0x3FEF, 0x3FC6, 0x0F04,
		/* 7 */	0x0003, 0x0003, 0x7803, 0x7F03, 0x7FC3, 0x07F3, 0x00FB, 0x003F, 0x000F, 0x0007,
		/* 8 */	0x1E1C, 0x3F3E, 0x7FFF, 0x71E7, 0x60C3, 0x60C3, 0x71E7, 0x7FFF, 0x3F3E, 0x1E1C,
		/* 9 */	0x1078, 0x39FE, 0x7BFE, 0x7387, 0x6303, 0x6303, 0x7187, 0x3FFE, 0x3FFE, 0x0FF8,
		/* : */	0x0000, 0x0E38, 0x0E38, 0x0E38
	};
#endif

static const struct font *BuiltinFontTable[] = {
	#if GDISP_INCLUDE_FONT_SMALL
		&fontSmall, &fontSmallDouble, &fontSmallNarrow,
	#endif
	#if GDISP_INCLUDE_FONT_LARGER
		&fontLarger, &fontLargerDouble, &fontLargerNarrow,
	#endif
	#if GDISP_INCLUDE_FONT_UI1
		&fontUI1, &fontUI1Double, &fontUI1Narrow,
	#endif
	#if GDISP_INCLUDE_FONT_UI2
		&fontUI2, &fontUI2Double, &fontUI2Narrow,
	#endif
	#if GDISP_INCLUDE_FONT_LARGENUMBERS
		&fontLargeNumbers, &fontLargeNumbersDouble, &fontLargeNumbersNarrow,
	#endif
	};

/**
 * Match a pattern against the font name.
 */
static bool_t matchfont(const char *pattern, const char *name) {
	while(1) {
		switch (pattern[0]) {
		case '*':
			if (name[0] == 0)
				return pattern[1] == 0;
			if (pattern[1] == name[0])
				pattern++;
			else
				name++;
			break;
		case 0:
			return name[0] == 0;
		default:
			if (name[0] != pattern[0])
				return FALSE;
			pattern++;
			name++;
			break;
		}
	}
}

font_t gdispOpenFont(const char *name) {
	const struct font **p;

	for(p = BuiltinFontTable; p < BuiltinFontTable+sizeof(BuiltinFontTable)/sizeof(BuiltinFontTable[0]); p++) {
		if (matchfont(name, p[0]->name))
			return p[0];
	}
	return 0;
}

void gdispCloseFont(font_t font) {
	(void) font;
}

const char *gdispGetFontName(font_t font) {
	return font->name;
}

#endif /* GFX_USE_GDISP && GDISP_NEED_TEXT */
/** @} */
