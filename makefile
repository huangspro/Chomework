# Makefile for C++ ncurses game

# Compiler and flags
CC = g++
CFLAGS = -w -Wextra -std=c++11 -O2
LDFLAGS = -lncurses

# Target executable
TARGET = game

# Source files (all .C files)
SRCS = \
	Bomber.C \
	Bullet.C \
	Cruiser.C \
	Destroyer.C \
	Game.C \
	Gui.C \
	Gunboat.C \
	Item.C \
	main.C \
	MedicalPack.C \
	Missile.C \
	Pack.C \
	Player.C \
	Ship.C \
	Torpedo.C \
	Weapon.C \
	Island.C \
	WeaponPack.C

# Object files
OBJS = $(SRCS:.C=.o)

# Default target
all: $(TARGET)

# Link object files to create executable
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) $(LDFLAGS)

# Compile each .C file to .o
%.o: %.C
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up
clean:
	rm -f *.o $(TARGET)

# Remove all generated files
distclean: clean
	rm -f *~ .deps/*

# Phony targets
.PHONY: all clean distclean

# Include dependency generation (optional but recommended)
# Uncomment next line if you want automatic dependencies
# -include .deps/*.d
