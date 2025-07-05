CC := $(CROSS_COMPILE)
CFLAGS := -O2 -ffreestanding -ffunction-sections -nostdlib -mcpu=cortex-a72

SRC_C   := main.c
LD 		:= linker.ld
ELF     := blink.elf
IMG     := blink.bin

all: $(IMG)

$(ELF): $(SRC_C)
	$(CC)gcc $(CFLAGS) -T $(LD) -o $@ $<

$(IMG): $(ELF)
	$(CC)objcopy -O binary $< $@

clean:
	rm -f $(ELF) $(IMG)