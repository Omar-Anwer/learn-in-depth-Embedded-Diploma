#@copyright : Omar	
Project_Name=learn-in-depth
CC=arm-none-eabi-
CFLAGS=-g -mcpu=arm926ej-s
INCS=-I .
LIBS=
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
As=$(wildcard *.s)
AsOBJ=$(As:.s=.o)

all: $(Project_Name).bin
	@echo "Building done..."
	
%.o: %.s
	$(CC)as.exe $(CFLAGS) $< -o $@
	
%.o: %.c
	$(CC)gcc.exe -c $(CFLAGS) $(INCS) $< -o $@

$(Project_Name).elf: $(AsOBJ) $(OBJ)
	$(CC)ld.exe -T linker_script.ld $(LIBS) $(AsOBJ) $(OBJ) -o $@ -Map=output.map

$(Project_Name).bin:  $(Project_Name).elf
	$(CC)objcopy.exe -O binary $< $@
	
clean:
	@rm *.bin *.elf
	
clean-all:
	@rm *.o *.bin *.elf