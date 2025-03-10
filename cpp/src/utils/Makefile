BUILD_DIR::=../$(BUILD_DIR)

$(BUILD_DIR)/%.o: $(SRCS) | $(BUILD_DIR)
	$(CC) $(C_FLAGS) -c $< -o $@
