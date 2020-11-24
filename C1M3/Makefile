#------------------------------------------------------------------------------
# Week3 Assignment:analize memory segments 
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      %.o		:	generate object file
#      build		:	compile and build a final executable
#      clean		:	remove compiled object, preprocessed files,
#      				assembly files, maps, executables
#
# Platform Overrides:
#      PLATFORM - Platform (HOST, MSP432)
#
#------------------------------------------------------------------------------

# Platform Overrides - Default is HOST
ifndef PLATFORM
 override PLATFORM = MSP432
endif

include sources.mk

TARGET = c1m3

#
# Architectures Specific Flags
# 
LINKER_FILE = msp432p401r.lds
CPU = cortex-m4
ARCH = armv7e-m 
FLOAT = hard
FPU = fpv4-sp-d16
SPECS = nosys.specs

LDFLAGS_COMMON = -Wl,-Map=$(TARGET).map
CFLAGS_COMMON = -Wall -Werror -g -O0 -std=c99

#
# Compiler Flags and Defines
# 
ifeq ($(PLATFORM),HOST)
	CC = gcc
	LD = gcc
	LDFLAGS = $(LDFLAGS_COMMON) 
	CFLAGS = $(CFLAGS_COMMON)
	CPPFLAGS = -DHOST
else
	CC = arm-none-eabi-gcc
	LD = arm-none-eabi-gcc
	CPPFLAGS = -DMSP432
	CFLAGS = $(CFLAGS_COMMON) -mthumb -mcpu=$(CPU) -march=$(ARCH) -mfpu=$(FPU) -mfloat-abi=$(FLOAT) --specs=$(SPECS)
#	CFLAGS = $(CFLAGS_COMMON) -mthumb -mcpu=$(CPU) --specs=$(SPECS)
endif
	LDFLAGS = $(LDFLAGS_COMMON) -T $(LINKER_FILE) $(CFLAGS)

OBJECTS = $(SOURCES:.c=.o)

%.o: %.c 
	$(CC) -c -o $@ $< $(CPPFLAGS) $(CFLAGS) $(INCLUDES)


.PHONY: build
build: all

.PHONY: all
all: $(TARGET).out

$(TARGET).out: $(OBJECTS)
	$(LD) $(OBJECTS) $(LDFLAGS) -o $@
	size ./$(TARGET).out

.PHONY: clean
clean:
	rm -f $(OBJECTS) $(TARGET).out $(TARGET).map

