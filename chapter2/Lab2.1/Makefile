CC := $(CROSS_COMPILE)
CFLAGS := -O2 -ffreestanding -nostdlib -mcpu=cortex-a72
ASFLAGS := -mcpu=cortex-a72


SRC_C   := main.c
SRC_S   := start.S
OBJ     := start.o main.o
ELF     := blink.elf
IMG     := kernel8.img          # filename required by the Boot ROM


all: $(IMG)

%.o: %.c
	$(CC)gcc $(CFLAGS) -c $< -o $@

%.o: %.S
	$(CC)as $(ASFLAGS) $< -o $@

$(ELF): $(OBJ) linker.ld
	$(CC)ld -T linker.ld -o $@ $(OBJ)

$(IMG): $(ELF)
	$(CC)objcopy -O binary $< $@

clean:
	rm -f $(OBJ) $(ELF) $(IMG)