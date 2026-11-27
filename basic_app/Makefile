CC = gcc
CFLAGS = -Wall -Wextra -g -std=c11 -Iinclude
CPPFLAGS = -MMD -MP
LDFLAGS =

SRC_DIR = src
INC_DIR = include
BUILD_DIR = build
BIN_DIR = bin

TARGET = $(BIN_DIR)/app
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS))
DEPS = $(OBJS:.o=.d)

all: $(TARGET)

$(TARGET): $(OBJS) | $(BIN_DIR)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(BUILD_DIR) $(BIN_DIR):
	mkdir -p $@

-include $(DEPS)

clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)

.PHONY: all clean
