CC = gcc
CFLAGS = -Iinclude
SRC_DIR = src
OBJ_DIR = build
TARGET_DIR = bin
SRC = $(notdir $(wildcard $(SRC_DIR)/*.c))
OBJ = $(SRC:.c=.o)
TARGET = binary_tree

all: $(TARGET) run

run:
	./$(TARGET_DIR)/$(TARGET)

%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $(addprefix $(OBJ_DIR)/, $@)

$(TARGET): $(OBJ)
	$(CC) -g -o $(TARGET_DIR)/$@ $(addprefix $(OBJ_DIR)/, $^)

dir:
	mkdir $(OBJ_DIR)
	mkdir $(TARGET_DIR)

clean:
	rm $(TARGET_DIR)/* $(OBJ_DIR)/*

.PHONY: run clean dir