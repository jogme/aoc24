CC=g++
C_FLAGS=-Wall -Wextra -Werror
BUILD_DIR=build
SRC_DIR=src
TARGET=$(BUILD_DIR)/aoc

SRCS = $(shell find $(SRC_DIR) -name "*.cpp")
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)
OBJS := $(subst /,_,$(OBJS))  # Flatten subdirectories
OBJS := $(subst build_,build/,$(OBJS)) # keep the first dir as a dir

all: $(TARGET)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)/*

include src/Makefile
