BUILD_DIR:=../$(BUILD_DIR)

$(TARGET): $(OBJS) | $(BUILD_DIR)
	$(CC) $(C_FLAGS) $^ -o $@

include src/utils/Makefile
include src/tests/Makefile
