#include <stdint.h>

#include "serial.h"
#include "io.h"

const uint16_t PORT = 0x3F8;

void Serial::Setup()
{
	IO::OutB(PORT + 1, 0x00);
	IO::OutB(PORT + 3, 0x80);
	IO::OutB(PORT + 0, 0x03);
	IO::OutB(PORT + 1, 0x00);
	IO::OutB(PORT + 3, 0x03);
	IO::OutB(PORT + 2, 0xC7);
	IO::OutB(PORT + 4, 0x0B);
}

bool Serial::IsSignalReceived()
{
	return (bool) IO::InB(PORT + 5) & 1;
}

bool Serial::IsTransmitEmpty()
{
	return (bool) IO::InB(PORT + 5) & 0x20;
}

char Serial::ReadCharacter()
{
	while(!IsSignalReceived()); // Wait until something comes on the serial port
	return IO::InB(PORT);
}


void Serial::WriteCharacter(char data)
{
	while(IsTransmitEmpty()); // Wait for transmit to be ready
	IO::OutB(PORT, data);
}

void Serial::WriteString(char* data)
{
	for(char* ptr = data; *ptr != NULL; ptr++)
	{
		Serial::WriteCharacter(*ptr);
	}
}
