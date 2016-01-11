#include <stdint.h>
#include <string.h>
#include <memman.h>
#include <stdlib.h>

void* malloc(size_t size)
{
	return kr_malloc(size);
}

void free(void* ptr)
{
	kr_free(ptr);
}

char* itoa(int value, char* str, int base)
{
	int i = 0;
	bool negative = false;

	if(value == 0)
	{
		str[i++] = '0';
		str[i] = '\0';
		return str;
	}

	if(value < 0 && base == 10)
	{
		negative = true;
		value = -value;
	}

	while(value != 0)
	{
		int remainder = value % base;
		str[i++] = (remainder > 9) ? (remainder - 10) + 'a' : remainder + '0';
		value /= base;
	}

	if(negative)
		str[i++] = '-';

	str[i++] = '\0';

	// Reverse the digits

	int j, k = 0;
	k = strlen(str) - 1;

	for(j = 0; j < k; j++, k--)
	{
		str[j] ^= str[k];
		str[k] ^= str[j];
		str[j] ^= str[k];
	}

	return str;
}
