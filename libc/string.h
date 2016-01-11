#include <stdint.h>

#ifndef STRING_H
#define STRING_H

size_t strlen(const char* str);
char* strcat(char *dest, const char* src);
char* strcpy(char *dest, const char* src);
int strcmp(const char* str1, const char* str2);

void memcpy(void* dest, void* src, size_t count);

#endif
