#---------------------------------------------------------------------------------------------------
# Algorithm Tutoring                                                                       Fall 2023
#
# Author: Kim Jaeyun <jaeyunkim@snu.ac.kr>
#
# this makefile is base on prof. Bernhard Egger's snuplc makefile
#


#
# variables
#

# directories
SRC_DIR=src
OBJ_DIR=obj
DEP_DIR=.deps

# compilation w/ automatic dependency generation
CC=g++
CCFLAGS=-std=c++17 -Wall -g -O2
DEPFLAGS=-MMD -MP -MT $@ -MF $(DEP_DIR)/$*.d

# sources for various targets
ALGO=algo.cpp
SOURCES=$(ALGO)

# object files of various targets
DEPS=$(SOURCES:.cpp=$(DEP_DIR)/.d)
OBJ_ALGO=$(patsubst %.cpp,$(OBJ_DIR)/%.o,$(ALGO))

#
# compilations rules
#
.PHONY: doc clean mrproper

all: test_algo

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(DEP_DIR) $(OBJ_DIR)
	$(CC) $(CCFLAGS) $(DEPFLAGS) -c -o $@ $<

$(DEP_DIR):
	@mkdir -p $(DEP_DIR)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)


-include $(DEPS)

test_algo: $(OBJ_DIR)/test_algo.o $(OBJ_ALGO)
	$(CC) $(CCFLAGS) -o $@ $(OBJ_DIR)/test_algo.o $(OBJ_ALGO)

clean:
	rm -rf $(OBJ_DIR) $(DEP_DIR)

mrproper: clean
	rm -rf test_algo

