CC       = gcc
PKGS    := libpulse-simple

PKG_CFLAGS := $(shell pkg-config --cflags $(PKGS))
PKG_LIBS   := $(shell pkg-config --libs $(PKGS))

CFLAGS   = -Wall -Wextra -g -std=gnu11 -Iinclude $(PKG_CFLAGS)
CPPFLAGS = -MMD -MP
LDFLAGS  =
LDLIBS   = $(PKG_LIBS) -lm

SRC_DIR   = src
INC_DIR   = include
BUILD_DIR = build
BIN_DIR   = bin

TARGET = $(BIN_DIR)/app
SRCS   = $(wildcard $(SRC_DIR)/*.c)
OBJS   = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS))
DEPS   = $(OBJS:.o=.d)

all: $(TARGET)

# Added $(LDLIBS) at the end
$(TARGET): $(OBJS) | $(BIN_DIR)
	$(CC) $(LDFLAGS) $(OBJS) -o $@ $(LDLIBS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(BUILD_DIR) $(BIN_DIR):
	mkdir -p $@

-include $(DEPS)

clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)

.PHONY: all clean

