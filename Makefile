##########################
######## Commands ########
##########################
MKDIR_P = mkdir -p
RM_R = rm -rf

##########################
######## Binaries ########
##########################
BLINK_EXEC = blink 

##########################
####### Directories ######
##########################
BINARY_DIR = bin
OBJECT_DIR = bits
SOURCE_DIR = cpp
MAIN_SOURCE_DIR = $(SOURCE_DIR)/main

##########################
####### Main Files #######
##########################
BLINK_SOURCE = $(MAIN_SOURCE_DIR)/blink.cpp

##########################
######### Recipes ########
##########################

# Scan for source files 
SOURCE_FILES := $(shell find $(SOURCE_DIR) ! -path '$(MAIN_SOURCE_DIR)/*' -name '*.cpp')

# Client object paths
BLINK_SOURCE_FILES = $(SOURCE_FILES) $(BLINK_SOURCE) 
BLINK_OBJECT_FILES_WITH_ROOT = $(addprefix $(OBJECT_DIR)/,$(BLINK_SOURCE_FILES:%.cpp=%.o))
BLINK_OBJECT_FILES = $(BLINK_SOURCE_FILES:%.cpp=%.o)

#Declaration of variables
CC = g++
CC_FLAGS = -w -I$(SOURCE_DIR) -std=c++11

# Removed files
FILES_TO_REMOVE = \
		$(BINARY_DIR)/ \
		$(OBJECT_DIR)/

# Create compilation directories
.PHONY: directories

# Build all binaries
all: directories $(BLINK_EXEC)

directories:
	${MKDIR_P} $(BINARY_DIR)

# Compile blink binary
$(BLINK_EXEC): $(BLINK_OBJECT_FILES) 
	@$(CC) $(BLINK_OBJECT_FILES_WITH_ROOT) -o $(BINARY_DIR)/$(BLINK_EXEC)

# Compile source
%.o: %.cpp
	@echo $(OBJECT_DIR)/$@
	@if [ -e $(dir $@) ] ; \
		then \
			${MKDIR_P} $(OBJECT_DIR)/$(dir $@) ; \
	fi;
	@$(CC) -c $(CC_FLAGS) $< -o $(OBJECT_DIR)/$@ 

# To remove generated files
clean:
	rm -rf $(FILES_TO_REMOVE) 
