#include <stdint.h>
#include <stddef.h>
#include "terminal.h"

size_t Terminal::cursor_row = 0;
size_t Terminal::cursor_column = 0;
uint8_t Terminal::cursor_colour = 0x07;
uint16_t* Terminal::vram = (uint16_t*) 0xB8000;	

uint8_t Terminal::GetColourCode(enum VGAColour foreground, enum VGAColour background)
{
	return foreground | background << 4;
}

uint16_t Terminal::GetVGAEntry(char character, uint8_t colour)
{
	return (uint16_t) character | (uint16_t) colour << 8;
}

void Terminal::SetColour(enum VGAColour foreground, enum VGAColour background)
{
	cursor_colour = GetColourCode(foreground, background);
}

void Terminal::SetColour(uint8_t colour)
{
	cursor_colour = colour;
}

void Terminal::WriteVGAEntry(char character, uint8_t colour, size_t x, size_t y)
{
	vram[y * VGA_WIDTH + x] = GetVGAEntry(character, colour);
}

void Terminal::WriteCharacter(char character)
{
	if(character >= 0x20)
	{
		WriteVGAEntry(character, cursor_colour, cursor_column, cursor_row);
		if(++cursor_column == VGA_WIDTH)
		{
			cursor_column = 0;
			if(++cursor_row == VGA_HEIGHT)
			{
				Scroll();
				cursor_row--;
			}
		}
	}

	else if(character == '\n')
	{
		cursor_column = 0;
		cursor_row++;
	}	
}

void Terminal::WriteString(char* string)
{
	for(size_t i = 0; string[i] != 0; i++)
		WriteCharacter(string[i]);
}

void Terminal::Clear()
{
	cursor_row = 0;
	cursor_column = 0;
	for(size_t y = 0; y < VGA_HEIGHT; y++)
	{
		for(size_t x = 0; x < VGA_WIDTH; x++)
		{
			vram[y * VGA_WIDTH + x] = GetVGAEntry(' ', cursor_colour);
		}
	}
}

void Terminal::Scroll()
{
	uint16_t blank = GetVGAEntry(' ', cursor_colour);
	for(size_t y = 0; y < VGA_HEIGHT - 1; y++)
	{
		for(size_t x = 0; x < VGA_WIDTH; x++) // Skip the last row
		{
			vram[y * VGA_WIDTH + x] = vram[(y + 1) * VGA_WIDTH + x];
		}
	}

	for(size_t x = 0; x < VGA_WIDTH; x++) // Clear the last row
	{
		vram[(VGA_HEIGHT - 1) * VGA_WIDTH + x] = blank;
	}
}