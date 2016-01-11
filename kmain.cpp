#include <stdlib.h>

#include "externals/multiboot.h"
#include "terminal.h"
#include "io.h"
#include "vfs.h"
#include "serial.h"
#include "sorash.h"

extern "C"
void kmain(multiboot_info_t* mbd, unsigned int magic)
{
	char* buffer = (char*) malloc(8);

	Terminal::SetColour(Terminal::COLOUR_WHITE, Terminal::COLOUR_BLUE);
	Terminal::Clear();

	Terminal::WriteString("Kernel loaded at 0x");
	Terminal::WriteString(itoa(int(&kmain), buffer, 16));
	Terminal::WriteCharacter('\n');

	Terminal::WriteString(itoa(int(mbd->mem_lower + mbd->mem_upper), buffer, 10));
	Terminal::WriteString(" KB RAM\n");

	Terminal::WriteString("Setting up virtual file system...\n");
	VFS::Setup();
	
	Terminal::WriteString("Setting up serial communications...\n");
	Serial::Setup();	
	Terminal::WriteString("Starting Sorash...\n");
	Sorash::main();
	
	Terminal::WriteString("System halted");

	for(;;) {}
}
