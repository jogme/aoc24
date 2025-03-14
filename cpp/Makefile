CC=g++
C_FLAGS=-Wall -Wextra -Werror
LIBS=-lcurl
BUILD_DIR=build
BUILD_DIR_SRC=$(BUILD_DIR)/src
BUILD_DIR_TESTS=$(BUILD_DIR)/tests
SRC_DIR=src
TESTS_DIR=tests
TARGET_NAME=aoc
TARGET=$(BUILD_DIR)/$(TARGET_NAME)

SRC=$(wildcard $(SRC_DIR)/*.cpp)
SRC_OBJS=$(SRC:src/%.cpp=$(BUILD_DIR_SRC)/%.o)

TESTS=$(wildcard $(TESTS_DIR)/*.cpp)
TESTS_EXE=$(TESTS:$(TESTS_DIR)/%.cpp=$(BUILD_DIR_TESTS)/%)
TESTS_SRC_OBJS=$(filter-out $(BUILD_DIR_SRC)/$(TARGET_NAME).o, $(SRC_OBJS))

all: $(TARGET)

tests: $(TESTS_EXE)

.PHONY: run
run: $(TARGET)

$(SRC_OBJS): $(BUILD_DIR_SRC)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CC) $(C_FLAGS) -c $^ -o $@

$(TARGET): $(SRC_OBJS) | $(BUILD_DIR)
	$(CC) $(C_FLAGS) -o $@ $^ $(LIBS)

$(TESTS_EXE): $(TESTS) $(TESTS_SRC_OBJS) | $(BUILD_DIR)
	$(CC) $(C_FLAGS) -o $@ $^ $(LIBS) -I $(SRC_DIR)
	cp $(TESTS_DIR)/read_test $(BUILD_DIR_TESTS)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR_SRC) $(BUILD_DIR_TESTS)

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)
