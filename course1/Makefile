#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# Week2 Assignment: build system for host and msp432
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      %.i		: 	generate a preprocessed file 
#      %.asm		:	generate assembly file
#      %.o		:	generate object file
#      compile-all	: 	compile all object files; no linking
#      build		:	compile and build a final executable
#      clean		:	remove compiled object, preprocessed files,
#      				assembly files, maps, executables
#
# NOTE: invoke make clean prior to switching PLATFORM
#
# Platform Overrides:
#      PLATFORM - Platform (HOST, MSP432)
#
#------------------------------------------------------------------------------

# Platform Overrides - Default is HOST
ifndef PLATFORM
 override PLATFORM = HOST
endif

include sources.mk

TARGET = c1m4

#
# Architectures Specific Flags
# 
LINKER_FILE = msp432p401r.lds
CPU = cortex-m4
ARCH = armv7e-m 
FLOAT = hard
FPU = fpv4-sp-d16
SPECS = nosys.specs

LDFLAGS_COMMON = -Map=$(TARGET).map -lm
CFLAGS_COMMON = -Wall -g -Werror -O0 -std=c99
CPPFLAGS_COMMON = -DCOURSE1 -DVERBOSE

#
# Compiler Flags and Defines
# 
ifeq ($(PLATFORM),MSP432)
	CC = arm-none-eabi-gcc
	LD = arm-none-eabi-ld
	LDFLAGS = $(LDFLAGS_COMMON) -T $(LINKER_FILE)
	CFLAGS = $(CFLAGS_COMMON) -mthumb -mcpu=$(CPU) -march=$(ARCH) -mfpu=$(FPU) -mfloat-abi=$(FLOAT) --specs=$(SPECS)
#	CFLAGS = $(CFLAGS_COMMON) -mthumb -mcpu=$(CPU) -march=$(ARCH) --specs=$(SPECS)
	CPPFLAGS = $(CPPFLAGS_COMMON) -DMSP432
else
	CC = gcc
	LD = gcc
	LDFLAGS = -Wl,$(LDFLAGS_COMMON) 
	CFLAGS = $(CFLAGS_COMMON)
	CPPFLAGS = $(CPPFLAGS_COMMON) -DHOST
endif

OBJECTS = $(SOURCES:.c=.o)
ALL_OBJECTS = $(ALL_SOURCES:.c=.o)
ALL_INTS = $(ALL_SOURCES:.c=.i)
ALL_ASMS = $(ALL_SOURCES:.c=.asm)

%.i: %.c
	$(CC) -E $< $(CPPFLAGS) $(CFLAGS) $(INCLUDES) -o $@

%.asm: %.c
	$(CC) -S $< $(CPPFLAGS) $(CFLAGS) $(INCLUDES) -o $@

%.o: %.c 
	$(CC) -c -o $@ $< $(CPPFLAGS) $(CFLAGS) $(INCLUDES)


.PHONY: build
build: all

.PHONY: compile_all
compile-all: $(OBJECTS)

.PHONY: all
all: $(TARGET).out

$(TARGET).out: $(OBJECTS)
	$(LD) $(OBJECTS) $(LDFLAGS) -o $@

.PHONY: clean
clean:
	rm -f $(ALL_OBJECTS) $(ALL_INTS) $(ALL_ASMS) $(TARGET).out $(TARGET).map

