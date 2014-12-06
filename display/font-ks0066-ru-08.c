#include <avr/pgmspace.h>

const uint8_t font_ks0066_ru_08[] PROGMEM = {

	0x01,	// font height in bytes
	0x7F,	// position of symbol-space between letters
	0xC0,	// count of chars
	0x20,	// ascii char offset
	0x40,	// non-ascii char offset

	// ascii char widths
	0x05, 0x01, 0x03, 0x05, 0x05, 0x05, 0x05, 0x02,
	0x03, 0x03, 0x05, 0x05, 0x02, 0x05, 0x01, 0x05,

	0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05,
	0x05, 0x05, 0x01, 0x02, 0x04, 0x05, 0x04, 0x05,

	0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05,
	0x05, 0x04, 0x05, 0x05, 0x04, 0x05, 0x05, 0x05,

	0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05,
	0x05, 0x05, 0x05, 0x03, 0x05, 0x03, 0x05, 0x05,

	0x02, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05,
	0x05, 0x03, 0x04, 0x04, 0x03, 0x05, 0x04, 0x05,

	0x05, 0x05, 0x04, 0x05, 0x05, 0x05, 0x05, 0x05,
	0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x01,


	// non-ascii char widths
	0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05,
	0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05,

	0x05, 0x05, 0x05, 0x04, 0x04, 0x05, 0x05, 0x04,
	0x05, 0x05, 0x04, 0x04, 0x05, 0x04, 0x04, 0x05,

	0x04, 0x05, 0x05, 0x05, 0x04, 0x05, 0x05, 0x05,
	0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05,

	0x01, 0x01, 0x03, 0x03, 0x05, 0x05, 0x05, 0x03,
	0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x04,

	0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x01,
	0x03, 0x05, 0x05, 0x05, 0x05, 0x05, 0x04, 0x03,

	0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05,
	0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05,

	// font data
	0x00, 0x00, 0x00, 0x00, 0x00,	/* 0x20 =>   */
	0x5F,							/* 0x21 => ! */
	0x07, 0x00, 0x07,				/* 0x22 => " */
	0x14, 0x7F, 0x14, 0x7F, 0x14,	/* 0x23 => # */
	0x24, 0x2A, 0x7F, 0x2A, 0x12,	/* 0x24 => $ */
	0x23, 0x13, 0x08, 0x64, 0x62,	/* 0x25 => % */
	0x36, 0x49, 0x55, 0x22, 0x50,	/* 0x26 => & */
	0x05, 0x03,						/* 0x27 => ' */
	0x1C, 0x22, 0x41,				/* 0x28 => ( */
	0x41, 0x22, 0x1C,				/* 0x29 => ) */
	0x14, 0x08, 0x3E, 0x08, 0x14,	/* 0x2A => * */
	0x08, 0x08, 0x3E, 0x08, 0x08,	/* 0x2B => + */
	0x80, 0x40,						/* 0x2C => , */
	0x08, 0x08, 0x08, 0x08, 0x08,	/* 0x2D => - */
	0x40,							/* 0x2E => . */
	0x20, 0x10, 0x08, 0x04, 0x02,	/* 0x2F => / */

	0x3E, 0x51, 0x49, 0x45, 0x3E,	/* 0x30 => 0 */
	0x00, 0x42, 0x7F, 0x40, 0x00,	/* 0x31 => 1 */
	0x42, 0x61, 0x51, 0x49, 0x46,	/* 0x32 => 2 */
	0x21, 0x41, 0x45, 0x4B, 0x31,	/* 0x33 => 3 */
	0x18, 0x14, 0x12, 0x7F, 0x10,	/* 0x34 => 4 */
	0x27, 0x45, 0x45, 0x45, 0x39,	/* 0x35 => 5 */
	0x3C, 0x4A, 0x49, 0x49, 0x30,	/* 0x36 => 6 */
	0x01, 0x71, 0x09, 0x05, 0x03,	/* 0x37 => 7 */
	0x36, 0x49, 0x49, 0x49, 0x36,	/* 0x38 => 8 */
	0x06, 0x49, 0x49, 0x29, 0x1E,	/* 0x39 => 9 */
	0x24,							/* 0x3A => : */
	0x40, 0x24,						/* 0x3B => ; */
	0x08, 0x14, 0x22, 0x41,			/* 0x3C => < */
	0x14, 0x14, 0x14, 0x14, 0x14,	/* 0x3D => = */
	0x41, 0x22, 0x14, 0x08,			/* 0x3E => > */
	0x02, 0x01, 0x51, 0x09, 0x06,	/* 0x3F => ? */

	0x3E, 0x41, 0x5D, 0x55, 0x1E,	/* 0x40 => @ */
	0x7E, 0x11, 0x11, 0x11, 0x7E,	/* 0x41 => A */
	0x7F, 0x49, 0x49, 0x49, 0x36,	/* 0x42 => B */
	0x3E, 0x41, 0x41, 0x41, 0x22,	/* 0x43 => C */
	0x7F, 0x41, 0x41, 0x22, 0x1C,	/* 0x44 => D */
	0x7F, 0x49, 0x49, 0x49, 0x41,	/* 0x45 => E */
	0x7F, 0x09, 0x09, 0x09, 0x01,	/* 0x46 => F */
	0x3E, 0x41, 0x49, 0x49, 0x7A,	/* 0x47 => G */
	0x7F, 0x08, 0x08, 0x08, 0x7F,	/* 0x48 => H */
	0x00, 0x41, 0x7F, 0x41,			/* 0x49 => I */
	0x20, 0x40, 0x41, 0x3F, 0x01,	/* 0x4A => J */
	0x7F, 0x08, 0x14, 0x22, 0x41,	/* 0x4B => K */
	0x7F, 0x40, 0x40, 0x40,			/* 0x4C => L */
	0x7F, 0x02, 0x0C, 0x02, 0x7F,	/* 0x4D => M */
	0x7F, 0x04, 0x08, 0x10, 0x7F,	/* 0x4E => N */
	0x3E, 0x41, 0x41, 0x41, 0x3E,	/* 0x4F => O */

	0x7F, 0x09, 0x09, 0x09, 0x06,	/* 0x50 => P */
	0x3E, 0x41, 0x51, 0x21, 0x5E,	/* 0x51 => Q */
	0x7F, 0x09, 0x19, 0x29, 0x46,	/* 0x52 => R */
	0x26, 0x49, 0x49, 0x49, 0x32,	/* 0x53 => S */
	0x01, 0x01, 0x7F, 0x01, 0x01,	/* 0x54 => T */
	0x3F, 0x40, 0x40, 0x40, 0x3F,	/* 0x55 => U */
	0x07, 0x18, 0x60, 0x18, 0x07,	/* 0x56 => V */
	0x3F, 0x40, 0x38, 0x40, 0x3F,	/* 0x57 => W */
	0x63, 0x14, 0x08, 0x14, 0x63,	/* 0x58 => X */
	0x07, 0x08, 0x70, 0x08, 0x07,	/* 0x59 => Y */
	0x61, 0x51, 0x49, 0x45, 0x43,	/* 0x00 => Z */
	0x7F, 0x41, 0x41,				/* 0x5B => [ */
	0x18, 0x24, 0x7E, 0x24, 0x10,	/* 0x5C => ¢ */
	0x41, 0x41, 0x7F,				/* 0x5D => ] */
	0x04, 0x02, 0x01, 0x02, 0x04,	/* 0x5E => ^ */
	0x40, 0x40, 0x40, 0x40, 0x40,	/* 0x5F => - */

	0x01, 0x02,						/* 0x60 => ` */
	0x20, 0x54, 0x54, 0x54, 0x78,	/* 0x61 => a */
	0x7F, 0x48, 0x44, 0x44, 0x38,	/* 0x62 => b */
	0x38, 0x44, 0x44, 0x44, 0x20,	/* 0x63 => c */
	0x38, 0x44, 0x44, 0x48, 0x7F,	/* 0x64 => d */
	0x38, 0x54, 0x54, 0x54, 0x18,	/* 0x65 => e */
	0x08, 0x7E, 0x09, 0x01, 0x02,	/* 0x66 => f */
	0x18, 0xA4, 0xA4, 0xA4, 0x7C,	/* 0x67 => g */
	0x7F, 0x08, 0x04, 0x04, 0x78,	/* 0x68 => h */
	0x44, 0x7D, 0x40,				/* 0x69 => i */
	0x40, 0x80, 0x84, 0x7D,			/* 0x6A => j */
	0x7F, 0x10, 0x28, 0x44,			/* 0x6B => k */
	0x41, 0x7F, 0x40,				/* 0x6C => l */
	0x7C, 0x04, 0x18, 0x04, 0x78,	/* 0x6D => m */
	0x7C, 0x08, 0x04, 0x78,			/* 0x6E => n */
	0x38, 0x44, 0x44, 0x44, 0x38,	/* 0x6F => o */

	0xFC, 0x24, 0x44, 0x44, 0x38,	/* 0x70 => p */
	0x38, 0x44, 0x44, 0x24, 0xFC,	/* 0x71 => q */
	0x7C, 0x08, 0x04, 0x08,			/* 0x72 => r */
	0x08, 0x54, 0x54, 0x54, 0x20,	/* 0x73 => s */
	0x04, 0x3F, 0x44, 0x40, 0x20,	/* 0x74 => t */
	0x3C, 0x40, 0x40, 0x20, 0x7C,	/* 0x75 => u */
	0x0C, 0x30, 0x40, 0x30, 0x0C,	/* 0x76 => v */
	0x3C, 0x40, 0x30, 0x40, 0x3C,	/* 0x77 => w */
	0x44, 0x28, 0x10, 0x28, 0x44,	/* 0x78 => x */
	0x0C, 0x50, 0x50, 0x50, 0x3C,	/* 0x79 => y */
	0x44, 0x64, 0x54, 0x4C, 0x44,	/* 0x7A => z */
	0x1F, 0x00, 0x1F, 0x11, 0x1F,	/* 0x7B => ⑩ */
	0x1F, 0x00, 0x1D, 0x15, 0x17,	/* 0x7C => ⑫ */
	0x1F, 0x00, 0x17, 0x15, 0x1D,	/* 0x7D => ⑮ */
	0x08, 0x1C, 0x2A, 0x08, 0x0F,	/* 0x7E => ↵ */
	0x00,							/* 0x7F =>  */


	0x7F, 0x49, 0x49, 0x49, 0x31,	/* 0xA0 => Б */
	0x7F, 0x01, 0x01, 0x01, 0x03,	/* 0xA1 => Г */
	0x7E, 0x4B, 0x4A, 0x4B, 0x42,	/* 0xA2 => Ё */
	0x77, 0x08, 0x7F, 0x08, 0x77,	/* 0xA3 => Ж */
	0x41, 0x49, 0x49, 0x49, 0x36,	/* 0xA4 => З */
	0x7F, 0x10, 0x08, 0x04, 0x7F,	/* 0xA5 => И */
	0x7E, 0x20, 0x13, 0x08, 0x7E,	/* 0xA6 => Й */
	0x40, 0x3C, 0x02, 0x01, 0x7F,	/* 0xA7 => Л */
	0x7F, 0x01, 0x01, 0x01, 0x7F,	/* 0xA8 => П */
	0x07, 0x48, 0x48, 0x48, 0x3F,	/* 0xA9 => У */
	0x3C, 0x42, 0xFF, 0x42, 0x3C,	/* 0xAA => Ф */
	0x07, 0x08, 0x08, 0x08, 0x7F,	/* 0xAB => Ч */
	0x7F, 0x40, 0x7F, 0x40, 0x7F,	/* 0xAC => Ш */
	0x01, 0x7F, 0x48, 0x48, 0x30,	/* 0xAD => Ъ */
	0x7F, 0x48, 0x30, 0x00, 0x7F,	/* 0xAE => Ы */
	0x22, 0x41, 0x49, 0x49, 0x3E,	/* 0xAF => Э */

	0x7F, 0x08, 0x3E, 0x41, 0x3E,	/* 0xB0 => Ю */
	0x46, 0x29, 0x19, 0x09, 0x7F,	/* 0xB1 => Я */
	0x3C, 0x4A, 0x4A, 0x49, 0x30,	/* 0xB2 => б */
	0x7C, 0x54, 0x54, 0x28,			/* 0xB3 => в */
	0x7C, 0x04, 0x04, 0x0C,			/* 0xB4 => г */
	0x38, 0x55, 0x54, 0x55, 0x18,	/* 0xB5 => ё */
	0x6C, 0x10, 0x7C, 0x10, 0x6C,	/* 0xB6 => ж */
	0x44, 0x54, 0x54, 0x28,			/* 0xB7 => з */
	0x7C, 0x20, 0x10, 0x08, 0x7C,	/* 0xB8 => и */
	0x7C, 0x21, 0x12, 0x09, 0x7C,	/* 0xB9 => й */
	0x7C, 0x10, 0x28, 0x44,			/* 0xBA => к */
	0x70, 0x08, 0x04, 0x7C,			/* 0xBB => л */
	0x7C, 0x08, 0x10, 0x08, 0x7C,	/* 0xBC => м */
	0x7C, 0x10, 0x10, 0x7C,			/* 0xBD => н */
	0x7C, 0x04, 0x04, 0x7C,			/* 0xBE => п */
	0x04, 0x04, 0x7C, 0x04, 0x04,	/* 0xBF => т */

	0x0C, 0x10, 0x10, 0x7C,			/* 0xC0 => ч */
	0x7C, 0x40, 0x7C, 0x40, 0x7C,	/* 0xC1 => ш */
	0x04, 0x7C, 0x50, 0x50, 0x20,	/* 0xC2 => ъ */
	0x7C, 0x50, 0x20, 0x00, 0x7C,	/* 0xC3 => ы */
	0x7C, 0x50, 0x50, 0x20,			/* 0xC4 => ь */
	0x28, 0x44, 0x54, 0x54, 0x38,	/* 0xC5 => э */
	0x7C, 0x10, 0x38, 0x44, 0x38,	/* 0xC6 => ю */
	0x08, 0x54, 0x34, 0x14, 0x7C,	/* 0xC7 => я */
	0x08, 0x14, 0x22, 0x08, 0x14,	/* 0xC8 => « */
	0x14, 0x08, 0x22, 0x14, 0x08,	/* 0xC9 => » */
	0x60, 0x50, 0x00, 0x60, 0x50,	/* 0xCA => “ */
	0x05, 0x03, 0x00, 0x05, 0x03,	/* 0xCB => ” */
	0x0F, 0x02, 0x3C, 0x2F, 0x38,	/* 0xCC => Ṇ */
	0x30, 0x48, 0x45, 0x40, 0x20,	/* 0xCD => ¿ */
	0x40, 0x48, 0x3E, 0x09, 0x01,	/* 0xCE => ⨍ */
	0x48, 0x7E, 0x49, 0x49, 0x42,	/* 0xCF => £ */

	0x00,							/* 0xD0 => ˌ */
	0x78,							/* 0xD1 => ╷ */
	0x5C, 0x40, 0x5C,				/* 0xD2 => ⥣ */
	0x5C, 0x00, 0x5C,				/* 0xD3 => ⥥ */
	0x45, 0x24, 0x15, 0x08, 0x04,	/* 0xD4 => ⅟ */
	0x22, 0x36, 0x1C, 0x36, 0x22,	/* 0xD5 => × */
	0x45, 0x22, 0x15, 0x08, 0x04,	/* 0xD6 => ⁄ */
	0x21, 0x3F, 0x21,				/* 0xD7 => Ⅰ */
	0x21, 0x3F, 0x21, 0x3F, 0x21,	/* 0xD8 => Ⅱ */
	0x04, 0x02, 0x7F, 0x02, 0x04,	/* 0xD9 => ↑ */
	0x10, 0x20, 0x7F, 0x20, 0x10,	/* 0xDA => ↓ */
	0x10, 0x38, 0x7C, 0xEE, 0xC6,	/* 0xDB => ⇤ */
	0xC6, 0xEE, 0x7C, 0x38, 0x10,	/* 0xDC => ⇥ */
	0x7F, 0x08, 0x1C, 0x08, 0x3E,	/* 0xDD => ⤠ */
	0x47, 0x22, 0x12, 0x08, 0x04,	/* 0xDE => ⍘ */
	0x06, 0x09,	0x09, 0x06,			/* 0xDF => ° */

	0xC0, 0x7E, 0x41, 0x7F, 0xC0,	/* 0xE0 => Д */
	0x7F, 0x40, 0x40, 0x7F, 0xC0,	/* 0xE1 => Ц */
	0x7F, 0x40, 0x7F, 0x40, 0xFF,	/* 0xE2 => Щ */
	0xC0, 0x78, 0x44, 0x7C, 0xC0,	/* 0xE3 => д */
	0x30, 0x48, 0xFC, 0x48, 0x30,	/* 0xE4 => ф */
	0x7C, 0x40, 0x40, 0x7C, 0xC0,	/* 0xE5 => ц */
	0x7C, 0x40, 0x7C, 0x40, 0xFC,	/* 0xE6 => щ */
	0x02,							/* 0xE7 => ‘ */
	0x01, 0x00, 0x01,				/* 0xE8 => ¨ */
	0x02, 0x01, 0x02, 0x02, 0x01,	/* 0xE9 => ~ */
	0x06, 0x49, 0x4A, 0x49, 0x3E,	/* 0xEA => Ў */
	0x0C, 0x51, 0x52, 0x51, 0x3C,	/* 0xEB => ў */
	0x3E, 0x49, 0x49, 0x41, 0x22,	/* 0xEC => Є */
	0x38, 0x54, 0x54, 0x44, 0x28,	/* 0xED => є */
	0x00, 0x41, 0x7F, 0x41,			/* 0xEE => Ї */
	0x45, 0x7D, 0x41,				/* 0xEF => ї */

	0x17, 0x08, 0x34, 0x2A, 0x7D,	/* 0xF0 => ¼ */
	0x17, 0x08, 0x54, 0x56, 0x7D,	/* 0xF1 => ⅓ */
	0x17, 0x08, 0x74, 0x56, 0x5D,	/* 0xF2 => ½ */
	0x15, 0x1F, 0x60, 0x50, 0xF8,	/* 0xF3 => ¾ */
	0x7F, 0x2A, 0x2A, 0x2A, 0x7F,	/* 0xF4 => ☰ */
	0x01, 0x11, 0x10, 0x04, 0x04,	/* 0xF5 => ∴ */
	0x0E, 0x45, 0xEE, 0x40, 0x78,	/* 0xF6 => ⏎ */
	0x80, 0xFF, 0xAA, 0x2A, 0x08,	/* 0xF7 => ⁅ */
	0x08, 0xAA, 0xFF, 0xAA, 0x08,	/* 0xF8 => ┼ */
	0x08, 0x2A, 0xAA, 0xC0, 0xAA,	/* 0xF9 => ┽ */
	0x08, 0x2A, 0xAA, 0xFF, 0x80,	/* 0xFA => ⁆ */
	0x08, 0x2A, 0x7F, 0x2A, 0x08,	/* 0xFB => ⁘ */
	0x22, 0x14, 0x88, 0xFF, 0x80,	/* 0xFC => ⁙ */
	0x40, 0x9A, 0xA5, 0x59, 0x02,	/* 0xFD => § */
	0x06, 0x09, 0x7F, 0x09, 0x7F,	/* 0xFE => ¶ */
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF,	/* 0xFF => █ */
};
