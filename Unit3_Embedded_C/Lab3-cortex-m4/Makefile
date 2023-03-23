#@copyright : Omar	
Project_Name = learn-in-depth-cortex-m4
CC = arm-none-eabi-
CFLAGS = -mcpu=cortex-m4 -g -gdwarf-2
INCS = -I .
LIBS =
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
As = $(wildcard *.s)
AsOBJ = $(As:.s=.o)

all: $(Project_Name).bin
	@echo "Building done..."
	
%.o: %.s
	$(CC)as.exe $(CFLAGS) $< -o $@
	
%.o: %.c
	$(CC)gcc.exe -c $(CFLAGS) $(INCS) $< -o $@

$(Project_Name).elf: $(AsOBJ) $(OBJ)
	$(CC)ld.exe -T linker_script.ld $(LIBS) $(AsOBJ) $(OBJ) -o $@ -Map=output.map
	@cp $(Project_Name).elf $(Project_Name).axf
	
$(Project_Name).bin: $(Project_Name).elf
	$(CC)objcopy.exe -O binary $< $@
	$(CC)objcopy.exe -O ihex $< $(Project_Name).hex
	
clean:
	@rm *.bin *.hex *.elf *.axf
	
clean-all:
	@rm *.o *.bin *.hex *.elf *.axf
	@echo "All cleaned..."