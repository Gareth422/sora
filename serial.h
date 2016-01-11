#ifndef _SERIAL_H
#define _SERIAL_H

#include <stdint.h>

namespace Serial
{
	void Setup();
	bool IsSignalReceived();
	bool IsTransmitEmpty();
	char ReadCharacter();
	void WriteCharacter(char character);
	void WriteString(char* data);
}

#endif
