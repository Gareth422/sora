#include <stdlib.h>
#include <string.h>

#include "sorash.h"
#include "terminal.h"
#include "serial.h"
#include "vfs.h"

namespace Sorash
{
	bool quit_requested = false;
	VFS::Node* current_directory;

	void WriteCharacter(char ch)
	{
		Serial::WriteCharacter(ch);
	}

	void WriteString(char* str)
	{
		Serial::WriteString(str);
	}

	char ReadCharacter()
	{
		char ch = 0;
		while(ch == 0) ch = Serial::ReadCharacter();
		return ch;
	}

	char* ReadLine()
	{
		char ch;
		int len;
		char buffer[80];
		for(int i = 0; i < 80; i++)
		{
			ch = ReadCharacter();
			if(ch == 0x0D) // Carriage return
			{
				len = i; // i - 1 was the last non-newline character, so the +1 and -1 cancel out
				buffer[i] = NULL; // Null-terminate the string
				break;
			}	
			else if(ch == 0x7F) // Backspace
			{
				i -= 2; // Go back one character (plus the current one)
				i = i < -1 ? -1 : i; // Don't let i go negative (-1 is okay because it will be 0 after it is incremented)
				WriteCharacter(0x08); // Write backspace character
			}
			else
			{
				WriteCharacter(ch);
				buffer[i] = ch;
			}
		}

		char* str = (char*) malloc(len);
		strcpy(str, buffer);
		return str;
	}

	void InterpretCommand(char* command)
	{
		if(strcmp(command, "quit") == 0)
		{
			quit_requested = true;
		}
		else if(strcmp(command, "crdir") == 0)
		{
			WriteString(current_directory->name);
			WriteCharacter('\n');	
		}
		else if(strcmp(command, "") == 0); // Do nothing for an empty command
		else
		{
			WriteString("Command not found: ");
			WriteString(command);
			WriteCharacter('\n');
		}
	}

	int main()
	{
		WriteString("Welcome to Sorash, the kernel-mode shell!\n");
		char* input;

		current_directory = &VFS::root;

		while(!quit_requested)
		{
			WriteString("> ");
			input = ReadLine();
			WriteCharacter('\n');
			InterpretCommand(input);
			free(input);
		}
		WriteString("Exiting Sorash...");
		return 0;
	}
}
