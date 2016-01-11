#ifndef _STDLIB_H
#define _STDLIB_H

#include <sys/types.h>

extern void* free_base;
extern void* free_top;

void* malloc(size_t size);
void free(void* ptr);
char* itoa(int value, char* str, int base);

#endif