#ifndef _VFS_H
#define _VFS_H

#include <stdint.h>

#include "errors.h"

typedef uint64_t nodeid_t;

namespace VFS
{
	enum Error
	{
		SUCCESS = 0,
		NOT_FOUND = 1
	};

	struct Node
	{
		nodeid_t id;
		char* name;
	};

	extern Node root;

	error_t Read(nodeid_t id, void* buffer, size_t count);
	error_t Write(nodeid_t id, void* buffer, size_t count);
	error_t GetChildren(nodeid_t id);
	error_t Setup();
};

#endif
