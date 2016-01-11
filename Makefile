OBJECTS = loader.o kmain.o terminal.o serial.o vfs.o sorash.o libc/string.o libc/stdlib.o externals/memman.o
CC = clang++
CFLAGS = -I libc -I externals -ffreestanding -Wall -Wextra -w -fno-exceptions -fno-rtti -std=c++0x -m32 -fpermissive -c
LDFLAGS = -T link.ld -nostdlib -melf_i386
AS = nasm
ASFLAGS = -f elf

all: kernel.elf

kernel.elf: $(OBJECTS)
	ld $(LDFLAGS) $(OBJECTS) -o kernel.elf

os.iso: kernel.elf
	cp kernel.elf iso/boot/kernel.elf
	genisoimage -R \
	-b boot/grub/stage2_eltorito \
	-no-emul-boot \
	-boot-load-size 4 \
	-A os \
	-quiet \
	-boot-info-table \
	-o os.iso \
	iso


%.o: %.c
	$(CC) $(CFLAGS) $< -o $@
%.o: %.s
	$(AS) $(ASFLAGS) $< -o $@
clean:
	rm -rf *.o kernel.elf os.iso
	rm -rf include/*.o
	rm -rf externals/*.o
