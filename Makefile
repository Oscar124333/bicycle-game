# Compiler and flags
CC      = gcc
CFLAGS  = -g -Wall -Wextra -MMD -MP -Iheaders

# Directories
SRC_DIR = src
OBJ_DIR = obj
BIN     = bicycle

# Collect all .c files and map to .o
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Default target
all: $(BIN)

# Link all objects into final executable
$(BIN): $(OBJS)
	$(CC) $(OBJS) -o $@

# Compile each .c into .o inside obj/
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Create obj directory if missing
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Clean build artifacts
clean:
	rm -rf $(OBJ_DIR) $(BIN)

# Convenience run target
run: $(BIN)
	./$(BIN)