#@copyright : Omar Anwer

#Project name
PROJECT_NAME	= learn-in-depth-cortex-m4

#Architectures Specific Flags
CPU 			= arm926ej-s
CFLAGS_ARCH 	= -mcpu=$(CPU)
#CFLAGS_ARCH    = -mcpu=$(CPU) -m$(ARCH) --specs=$(SPECS)

#Compiler Flags and Defines
CC				= arm-none-eabi-
DBGCFLAGS		= -g -gdwarf-2
CFLAGS			= -ansi -std=c89 -O0 -Wall $(CFLAGS_ARCH) $(DBGCFLAGS)

#Linker Flags
LINKER_FILE		= linker_script.ld
LDFLAGS_ARCH 	= -T $(LINKER_FILE)
STARTUP_FILE	= startup.s

#includes
INCS			= -I .
LIBS			=

#.c and .s files 
SRC				= $(wildcard *.c)
AS				= $(wildcard *.s)

PRE				= $(SRC:.c=.i)
SRCOBJ			= $(SRC:.c=.o)
ASOBJ			= $(AS:.s=.o)


all: $(PROJECT_NAME).bin
	@echo ""
	@$(CC)size.exe $(PROJECT_NAME).elf
	@echo ""
	@echo "Building done..."
	
%.o: %.s
	$(CC)as.exe $(INCS) $< -o $@
	@echo ""

%.o: %.c
	$(CC)gcc.exe -S $(INCS) $<
	@echo ""
	$(CC)gcc.exe -c $(CFLAGS) $(INCS) $< -o $@
	@echo ""
	
%.i: %.c
	$(CC)gcc.exe -E $(INCS) $< -o $@
	@echo ""
	
$(PROJECT_NAME).elf: $(ASOBJ) $(SRCOBJ) $(PRE)
	$(CC)ld.exe $(LDFLAGS_ARCH) $(LIBS) $(ASOBJ) $(SRCOBJ) -o $@ -Map=$(PROJECT_NAME).map
	@echo ""
	$(CC)objdump.exe -h $@
	@echo ""
	$(CC)readelf.exe -S $@
	@echo ""
	@cp $(PROJECT_NAME).elf $(PROJECT_NAME).axf
	
$(PROJECT_NAME).bin: $(PROJECT_NAME).elf
	$(CC)objcopy.exe -O binary $< $@
	@echo ""
	$(CC)objcopy.exe -O ihex $< $(PROJECT_NAME).hex
	@echo ""
	
clean:
	@rm *.bin *.hex *.elf *.axf *.map 
	
clean-all:
	@rm  -rf $(filter-out $(STARTUP_FILE), $(AS))
	@rm  *.i *.o *.bin *.hex *.elf *.axf *.map
	@echo "All cleaned..."