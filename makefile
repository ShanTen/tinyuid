# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -I./TenLibs

# Target executable name (add .exe for Windows)
TARGET = tinyuid.exe

# Source and object files
SRCS = main.c TenLibs/trand.c
OBJS = $(SRCS:.c=.o)

# Default rule to build the program
all: $(TARGET)

# Link object files to create executable
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

# Compile each .c file into a .o file
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build artifacts
clean:
	del /Q $(OBJS) $(TARGET)

# Run the program
run: $(TARGET)
	$(TARGET)
