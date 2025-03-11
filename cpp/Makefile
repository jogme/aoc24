CC=g++
C_FLAGS=-Wall -Wextra -Werror
BUILD_DIR=build
BUILD_DIR_SRC=$(BUILD_DIR)/src
BUILD_DIR_TESTS=$(BUILD_DIR)/tests
SRC_DIR=src
TARGET_NAME=aoc
TARGET=$(BUILD_DIR)/$(TARGET_NAME)

SRC=$(wildcard src/*.cpp)
SRC_OBJS = $(SRC:src/%.cpp=$(BUILD_DIR_SRC)/%.o)

TESTS=$(wildcard tests/*.cpp)
TESTS_EXE = $(TESTS:tests/%.cpp=$(BUILD_DIR_TESTS)/%)

all: $(TARGET)

tests: $(TESTS_EXE)

.PHONY: run
run: $(TARGET)
	@$(TARGET)

$(SRC_OBJS): $(BUILD_DIR_SRC)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CC) $(C_FLAGS) -c $^ -o $@

$(TARGET): $(SRC_OBJS) | $(BUILD_DIR)
	$(CC) $(C_FLAGS) -o $@ $^

$(TESTS_EXE): $(TESTS) | $(BUILD_DIR)
	$(CC) $(C_FLAGS) -c $^ -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR_SRC) $(BUILD_DIR_TESTS)

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)
