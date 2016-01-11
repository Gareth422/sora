#ifndef _SORASH_H
#define _SORASH_H

namespace Sorash
{
	extern bool quit_requested;
	
	void WriteCharacter(char ch);
	void WriteString(char* str);
	char ReadCharacter();
	char* ReadLine();
	void InterpretCommand(char* command);
	int main();
}

#endif
