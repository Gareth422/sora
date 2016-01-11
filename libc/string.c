#include <stdint.h>
#include <string.h>

size_t strlen(const char* str)
{
	const char *s;
	for(s = str; *s; s++) ;
	return s - str;
}

char* strcat(char *dest, const char* src)
{
	char *rdest = dest;
	while(*dest) dest++;
	while(*dest++ = *src++);
	return rdest;
}

char* strcpy(char *dest, const char* src)
{
	char* temp = dest;
	while(*dest++ = *src++);
	return temp;
}

int strcmp(const char* s1, const char* s2)
{
	while(*s1 && (*s1 == *s2)) s1++, s2++;
	return *(const unsigned char*) s1 - *(const unsigned char*) s2;
}

void memcpy(void* dest, void* src, size_t count)
{
	for(size_t i = 0; i < count; i++)
		((char*) dest)[i] = ((char*) src)[i];
}
