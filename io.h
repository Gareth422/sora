#ifndef _IO_H
#define _IO_H

#include <stdint.h>

namespace IO
{
	static inline void OutB(uint16_t port, uint8_t value);
	static inline void OutW(uint16_t port, uint16_t value);
	static inline void OutL(uint16_t port, uint32_t value);

	static inline uint8_t InB(uint16_t port);
	static inline uint16_t InW(uint16_t port);
	static inline uint32_t InL(uint16_t port);
};

static inline void IO::OutB(uint16_t port, uint8_t value)
{
	asm volatile("outb %0, %1" :: "a"(value), "Nd"(port));
}

static inline void IO::OutW(uint16_t port, uint16_t value)
{
	asm volatile("outw %0, %1" :: "a"(value), "Nd"(port));
}

static inline void IO::OutL(uint16_t port, uint32_t value)
{
	asm volatile("outl %0, %1" :: "a"(value), "Nd"(port));
}

static inline uint8_t IO::InB(uint16_t port)
{
	uint8_t ret;
	asm volatile("inb %[port], %[ret]" : [ret] "=a"(ret) : [port] "Nd"(port));
	return ret;
}

static inline uint16_t IO::InW(uint16_t port)
{
	uint16_t ret;
	asm volatile("inw %[port], %[ret]" : [ret] "=a"(ret) : [port] "Nd"(port));
	return ret;
}

static inline uint32_t IO::InL(uint16_t port)
{
	uint32_t ret;
	asm volatile("inl %[port], %[ret]" : [ret] "=a"(ret) : [port] "Nd"(port));
	return ret;
}

#endif
