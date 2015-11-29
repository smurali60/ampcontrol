#include <avr/pgmspace.h>

const uint8_t icons_32[] PROGMEM = {
	// Mute ON
	0x03, 0x07, 0x0E, 0x1C, 0x38, 0x70, 0xE0, 0xC0, 0x80, 0x00, 0x00, 0x00, 0x80, 0xC0, 0xE0, 0xF0,
	0xF8, 0xFC, 0xFE, 0xFF, 0xFF, 0x00, 0x00, 0x80, 0xC0, 0xE0, 0x70, 0x38, 0x1C, 0x0E, 0x07, 0x03,
	0x00, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0xFD, 0xFB, 0x07, 0xEE, 0xDD, 0xBB, 0x77, 0xEF, 0xDF,
	0xDF, 0xEF, 0x77, 0xBB, 0xDD, 0x0E, 0x67, 0xE3, 0xC1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0xBF, 0xDF, 0xE0, 0x77, 0xBB, 0xDD, 0xEE, 0xF7, 0xFB,
	0xFB, 0xF7, 0xEE, 0xDD, 0xBB, 0x70, 0xE6, 0xC7, 0x83, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0xC0, 0xE0, 0x70, 0x38, 0x1C, 0x0E, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x0F,
	0x1F, 0x3F, 0x7F, 0xFF, 0xFF, 0x00, 0x00, 0x01, 0x03, 0x07, 0x0E, 0x1C, 0x38, 0x70, 0xE0, 0xC0,
	// Mute OFF
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xC0, 0xE0, 0xF0,
	0xF8, 0xFC, 0xFE, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x60, 0xE0, 0xC0, 0x80, 0x00, 0x00, 0x00, 0x00,
	0x00, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0x00, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x60, 0xE6, 0xCE, 0x1C, 0xF9, 0xE3, 0x0F, 0xFE, 0xF8, 0x00,
	0x00, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x00, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x06, 0x67, 0x73, 0x38, 0x9F, 0xC7, 0xF0, 0x7F, 0x1F, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x0F,
	0x1F, 0x3F, 0x7F, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x06, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00,
	// Loudness ON
	0x00, 0x00, 0x88, 0x88, 0xFE, 0xFE, 0x88, 0x88, 0x00, 0x00, 0x00, 0x00, 0x00, 0x88, 0x88, 0xFE,
	0xFE, 0x88, 0x88, 0x00, 0x00, 0x00, 0x00, 0x00, 0x88, 0x88, 0xFE, 0xFE, 0x88, 0x88, 0x00, 0x00,
	0x00, 0x3C, 0x3C, 0x3C, 0xFF, 0xFF, 0x3C, 0x3C, 0x3C, 0x00, 0x00, 0x00, 0xC0, 0xC8, 0xC8, 0xFF,
	0xFF, 0xC8, 0xC8, 0xC0, 0x00, 0x00, 0x00, 0x3C, 0x3C, 0x3C, 0xFF, 0xFF, 0x3C, 0x3C, 0x3C, 0x00,
	0x00, 0x00, 0x11, 0x11, 0xFF, 0xFF, 0x11, 0x11, 0x00, 0x00, 0x00, 0x00, 0x03, 0x13, 0x13, 0xFF,
	0xFF, 0x13, 0x13, 0x03, 0x00, 0x00, 0x00, 0x00, 0x11, 0x11, 0xFF, 0xFF, 0x11, 0x11, 0x00, 0x00,
	0x00, 0x00, 0x11, 0x11, 0x7F, 0x7F, 0x11, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x11, 0x7F,
	0x7F, 0x11, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x11, 0x7F, 0x7F, 0x11, 0x11, 0x00, 0x00,
	// Loudness OFF
	0x00, 0x00, 0x88, 0x88, 0xFE, 0xFE, 0x88, 0x88, 0x00, 0x00, 0x00, 0x00, 0x00, 0x88, 0x88, 0xFE,
	0xFE, 0x88, 0x88, 0x00, 0x00, 0x00, 0x00, 0x00, 0x88, 0x88, 0xFE, 0xFE, 0x88, 0x88, 0x00, 0x00,
	0x00, 0xC0, 0xC8, 0xC8, 0xFF, 0xFF, 0xC8, 0xC8, 0xC0, 0x00, 0x00, 0x00, 0xC0, 0xC8, 0xC8, 0xFF,
	0xFF, 0xC8, 0xC8, 0xC0, 0x00, 0x00, 0x00, 0xC0, 0xC8, 0xC8, 0xFF, 0xFF, 0xC8, 0xC8, 0xC0, 0x00,
	0x00, 0x03, 0x13, 0x13, 0xFF, 0xFF, 0x13, 0x13, 0x03, 0x00, 0x00, 0x00, 0x03, 0x13, 0x13, 0xFF,
	0xFF, 0x13, 0x13, 0x03, 0x00, 0x00, 0x00, 0x03, 0x13, 0x13, 0xFF, 0xFF, 0x13, 0x13, 0x03, 0x00,
	0x00, 0x00, 0x11, 0x11, 0x7F, 0x7F, 0x11, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x11, 0x7F,
	0x7F, 0x11, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x11, 0x7F, 0x7F, 0x11, 0x11, 0x00, 0x00,
	// Surround ON
	0x00, 0x00, 0x88, 0x88, 0xFE, 0xFE, 0x88, 0x88, 0x00, 0x00, 0x00, 0x00, 0x00, 0x88, 0x88, 0xFE,
	0xFE, 0x88, 0x88, 0x00, 0x00, 0x00, 0x00, 0x00, 0x88, 0x88, 0xFE, 0xFE, 0x88, 0x88, 0x00, 0x00,
	0x00, 0x3C, 0x3C, 0x3C, 0xFF, 0xFF, 0x3C, 0x3C, 0x3C, 0x00, 0x00, 0x00, 0xC0, 0xC8, 0xC8, 0xFF,
	0xFF, 0xC8, 0xC8, 0xC0, 0x00, 0x00, 0x00, 0x3C, 0x3C, 0x3C, 0xFF, 0xFF, 0x3C, 0x3C, 0x3C, 0x00,
	0x00, 0x00, 0x11, 0x11, 0xFF, 0xFF, 0x11, 0x11, 0x00, 0x00, 0x00, 0x00, 0x03, 0x13, 0x13, 0xFF,
	0xFF, 0x13, 0x13, 0x03, 0x00, 0x00, 0x00, 0x00, 0x11, 0x11, 0xFF, 0xFF, 0x11, 0x11, 0x00, 0x00,
	0x00, 0x00, 0x11, 0x11, 0x7F, 0x7F, 0x11, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x11, 0x7F,
	0x7F, 0x11, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x11, 0x7F, 0x7F, 0x11, 0x11, 0x00, 0x00,
	// Surround OFF
	0x00, 0x00, 0x88, 0x88, 0xFE, 0xFE, 0x88, 0x88, 0x00, 0x00, 0x00, 0x00, 0x00, 0x88, 0x88, 0xFE,
	0xFE, 0x88, 0x88, 0x00, 0x00, 0x00, 0x00, 0x00, 0x88, 0x88, 0xFE, 0xFE, 0x88, 0x88, 0x00, 0x00,
	0x00, 0xC0, 0xC8, 0xC8, 0xFF, 0xFF, 0xC8, 0xC8, 0xC0, 0x00, 0x00, 0x00, 0xC0, 0xC8, 0xC8, 0xFF,
	0xFF, 0xC8, 0xC8, 0xC0, 0x00, 0x00, 0x00, 0xC0, 0xC8, 0xC8, 0xFF, 0xFF, 0xC8, 0xC8, 0xC0, 0x00,
	0x00, 0x03, 0x13, 0x13, 0xFF, 0xFF, 0x13, 0x13, 0x03, 0x00, 0x00, 0x00, 0x03, 0x13, 0x13, 0xFF,
	0xFF, 0x13, 0x13, 0x03, 0x00, 0x00, 0x00, 0x03, 0x13, 0x13, 0xFF, 0xFF, 0x13, 0x13, 0x03, 0x00,
	0x00, 0x00, 0x11, 0x11, 0x7F, 0x7F, 0x11, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x11, 0x7F,
	0x7F, 0x11, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x11, 0x7F, 0x7F, 0x11, 0x11, 0x00, 0x00,
	// Effect 3D ON
	0x00, 0x00, 0x88, 0x88, 0xFE, 0xFE, 0x88, 0x88, 0x00, 0x00, 0x00, 0x00, 0x00, 0x88, 0x88, 0xFE,
	0xFE, 0x88, 0x88, 0x00, 0x00, 0x00, 0x00, 0x00, 0x88, 0x88, 0xFE, 0xFE, 0x88, 0x88, 0x00, 0x00,
	0x00, 0x3C, 0x3C, 0x3C, 0xFF, 0xFF, 0x3C, 0x3C, 0x3C, 0x00, 0x00, 0x00, 0xC0, 0xC8, 0xC8, 0xFF,
	0xFF, 0xC8, 0xC8, 0xC0, 0x00, 0x00, 0x00, 0x3C, 0x3C, 0x3C, 0xFF, 0xFF, 0x3C, 0x3C, 0x3C, 0x00,
	0x00, 0x00, 0x11, 0x11, 0xFF, 0xFF, 0x11, 0x11, 0x00, 0x00, 0x00, 0x00, 0x03, 0x13, 0x13, 0xFF,
	0xFF, 0x13, 0x13, 0x03, 0x00, 0x00, 0x00, 0x00, 0x11, 0x11, 0xFF, 0xFF, 0x11, 0x11, 0x00, 0x00,
	0x00, 0x00, 0x11, 0x11, 0x7F, 0x7F, 0x11, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x11, 0x7F,
	0x7F, 0x11, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x11, 0x7F, 0x7F, 0x11, 0x11, 0x00, 0x00,
	// Effect 3D OFF
	0x00, 0x00, 0x88, 0x88, 0xFE, 0xFE, 0x88, 0x88, 0x00, 0x00, 0x00, 0x00, 0x00, 0x88, 0x88, 0xFE,
	0xFE, 0x88, 0x88, 0x00, 0x00, 0x00, 0x00, 0x00, 0x88, 0x88, 0xFE, 0xFE, 0x88, 0x88, 0x00, 0x00,
	0x00, 0xC0, 0xC8, 0xC8, 0xFF, 0xFF, 0xC8, 0xC8, 0xC0, 0x00, 0x00, 0x00, 0xC0, 0xC8, 0xC8, 0xFF,
	0xFF, 0xC8, 0xC8, 0xC0, 0x00, 0x00, 0x00, 0xC0, 0xC8, 0xC8, 0xFF, 0xFF, 0xC8, 0xC8, 0xC0, 0x00,
	0x00, 0x03, 0x13, 0x13, 0xFF, 0xFF, 0x13, 0x13, 0x03, 0x00, 0x00, 0x00, 0x03, 0x13, 0x13, 0xFF,
	0xFF, 0x13, 0x13, 0x03, 0x00, 0x00, 0x00, 0x03, 0x13, 0x13, 0xFF, 0xFF, 0x13, 0x13, 0x03, 0x00,
	0x00, 0x00, 0x11, 0x11, 0x7F, 0x7F, 0x11, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x11, 0x7F,
	0x7F, 0x11, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x11, 0x7F, 0x7F, 0x11, 0x11, 0x00, 0x00,
	// Tone defeat ON
	0x00, 0x00, 0x88, 0x88, 0xFE, 0xFE, 0x88, 0x88, 0x00, 0x00, 0x00, 0x00, 0x00, 0x88, 0x88, 0xFE,
	0xFE, 0x88, 0x88, 0x00, 0x00, 0x00, 0x00, 0x00, 0x88, 0x88, 0xFE, 0xFE, 0x88, 0x88, 0x00, 0x00,
	0x00, 0x3C, 0x3C, 0x3C, 0xFF, 0xFF, 0x3C, 0x3C, 0x3C, 0x00, 0x00, 0x00, 0xC0, 0xC8, 0xC8, 0xFF,
	0xFF, 0xC8, 0xC8, 0xC0, 0x00, 0x00, 0x00, 0x3C, 0x3C, 0x3C, 0xFF, 0xFF, 0x3C, 0x3C, 0x3C, 0x00,
	0x00, 0x00, 0x11, 0x11, 0xFF, 0xFF, 0x11, 0x11, 0x00, 0x00, 0x00, 0x00, 0x03, 0x13, 0x13, 0xFF,
	0xFF, 0x13, 0x13, 0x03, 0x00, 0x00, 0x00, 0x00, 0x11, 0x11, 0xFF, 0xFF, 0x11, 0x11, 0x00, 0x00,
	0x00, 0x00, 0x11, 0x11, 0x7F, 0x7F, 0x11, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x11, 0x7F,
	0x7F, 0x11, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x11, 0x7F, 0x7F, 0x11, 0x11, 0x00, 0x00,
	// Tone defeat OFF
	0x00, 0x00, 0x88, 0x88, 0xFE, 0xFE, 0x88, 0x88, 0x00, 0x00, 0x00, 0x00, 0x00, 0x88, 0x88, 0xFE,
	0xFE, 0x88, 0x88, 0x00, 0x00, 0x00, 0x00, 0x00, 0x88, 0x88, 0xFE, 0xFE, 0x88, 0x88, 0x00, 0x00,
	0x00, 0xC0, 0xC8, 0xC8, 0xFF, 0xFF, 0xC8, 0xC8, 0xC0, 0x00, 0x00, 0x00, 0xC0, 0xC8, 0xC8, 0xFF,
	0xFF, 0xC8, 0xC8, 0xC0, 0x00, 0x00, 0x00, 0xC0, 0xC8, 0xC8, 0xFF, 0xFF, 0xC8, 0xC8, 0xC0, 0x00,
	0x00, 0x03, 0x13, 0x13, 0xFF, 0xFF, 0x13, 0x13, 0x03, 0x00, 0x00, 0x00, 0x03, 0x13, 0x13, 0xFF,
	0xFF, 0x13, 0x13, 0x03, 0x00, 0x00, 0x00, 0x03, 0x13, 0x13, 0xFF, 0xFF, 0x13, 0x13, 0x03, 0x00,
	0x00, 0x00, 0x11, 0x11, 0x7F, 0x7F, 0x11, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x11, 0x7F,
	0x7F, 0x11, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x11, 0x7F, 0x7F, 0x11, 0x11, 0x00, 0x00,
};
