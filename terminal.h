#ifndef TERMINAL_H
#define TERMINAL_H

#include <stdint.h>

namespace Terminal
{
	static const size_t VGA_WIDTH = 80;
	static const size_t VGA_HEIGHT = 25;

	extern size_t cursor_row;
	extern size_t cursor_column;
	extern uint8_t cursor_colour;
	extern uint16_t* vram;	

	enum VGAColour
	{
		COLOUR_BLACK = 0,
		COLOUR_BLUE = 1,
		COLOUR_GREEN = 2,
		COLOUR_CYAN = 3,
		COLOUR_RED = 4,
		COLOUR_MAGENTA = 5,
		COLOUR_BROWN = 6,
		COLOUR_LIGHT_GREY = 7,
		COLOUR_DARK_GREY = 8,
		COLOUR_LIGHT_BLUE = 9,
		COLOUR_LIGHT_GREEN = 10,
		COLOUR_LIGHT_CYAN = 11,
		COLOUR_LIGHT_RED = 12,
		COLOUR_LIGHT_MAGENTA = 13,
		COLOUR_LIGHT_BROWN = 14,
		COLOUR_WHITE = 15,
	};

	uint8_t GetColourCode(enum VGAColour foreground, enum VGAColour background);
	uint16_t GetVGAEntry(char character, uint8_t colour);
	void SetColour(enum VGAColour foreground, enum VGAColour background);
	void SetColour(uint8_t colour);
	void WriteVGAEntry(char character, uint8_t colour, size_t x, size_t y);
	void WriteCharacter(char character);
	void WriteString(char* string);
	void Clear();
	void Scroll();
};

#endif