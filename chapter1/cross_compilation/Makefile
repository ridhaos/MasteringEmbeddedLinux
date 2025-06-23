# Default compiler and flags
CC := $(CROSS_COMPILE)gcc
CFLAGS := -Wall -g -Werror

# Target bin and source
TARGET := helloWord
SRCS := helloWord.c
OBJS := helloWord.o

# Entry point
all: $(TARGET)

# Default target (build the binary)
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Rule to compile .c into .o
$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) -c -o $@ $<

#clean target
clean:
	rm -f $(TARGET) *.o

.PHONY: clean