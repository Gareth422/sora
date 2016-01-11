global loader
extern kmain

MAGIC_NUMBER		equ 0x1BADB002
FLAGS				equ 0x0
CHECKSUM			equ -MAGIC_NUMBER
KERNEL_STACK_SIZE	equ 4096

section .multiboot
align 4

dd MAGIC_NUMBER
dd FLAGS
dd CHECKSUM

section .text
align 4

loader:
	mov esp, kernel_stack + KERNEL_STACK_SIZE ; Set up the stack
	push 0 ; Clear flags
	popf
	push eax ; Push multiboot information
	push ebx
	call kmain
	mov word [0xB8000], 0x0748
	mov word [0xB8002], 0x0741
	mov word [0xB8004], 0x074E
	mov word [0xB8006], 0x0747
	hang:
	jmp hang

section .bss
align 4

kernel_stack:
	resb KERNEL_STACK_SIZE