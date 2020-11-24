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

#Defaults
ifndef PLATFORM
	override PLATFORM = HOST
endif

#Root path for source and include files
SRC_PATH = .
INC_PATH = ../include

# Source files 
SRC_COMMON = $(SRC_PATH)/main.c \
	     $(SRC_PATH)/memory.c

SRC_ARM = $(SRC_PATH)/interrupts_msp432p401r_gcc.c \
	  $(SRC_PATH)/startup_msp432p401r_gcc.c \
	  $(SRC_PATH)/system_msp432p401r.c

# Include paths
INC_COMMON = -I$(INC_PATH)/common

#Add ARM specific source files and include paths if MSP432P platform is enabled
ifeq ($(PLATFORM),MSP432)
	SOURCES = $(SRC_COMMON) \
		  $(SRC_ARM)
	INCLUDES = $(INC_COMMON) \
		   -I$(INC_PATH)/CMSIS \
		   -I$(INC_PATH)/msp432
else
	SOURCES = $(SRC_COMMON)
	INCLUDES = $(INC_COMMON)
endif

ALL_SOURCES = $(SRC_COMMON) $(SRC_ARM)


