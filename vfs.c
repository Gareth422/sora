#include <stdlib.h>

#include "vfs.h"
#include "errors.h"
#include "serial.h"

VFS::Node VFS::root;

error_t VFS::Read(nodeid_t id, void* buffer, size_t count)
{
	return SUCCESS; // TODO
}

error_t VFS::Write(nodeid_t id, void* buffer, size_t count)
{
	return SUCCESS; // TODO
}

error_t VFS::GetChildren(nodeid_t id)
{
	return NULL; // TODO
}

error_t VFS::Setup()
{
	root.id = 0;
	root.name = "@";
	return SUCCESS;
}
