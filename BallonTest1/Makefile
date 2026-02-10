# Compiler settings
CC = emcc
CXX = emcc
CFLAGS = -O2 -std=c++11 -Wall -Wextra
LDFLAGS = -O2 -s USE_SDL=2 -s ASYNCIFY -s ALLOW_MEMORY_GROWTH=1 --bind

# Directories
SRCDIR = src
INCLUDEDIR = include
OBJDIR = obj
BINDIR = bin

# Source files
SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)
TARGET = $(BINDIR)/game.js

# Create directories
$(shell mkdir -p $(OBJDIR) $(BINDIR))

# Build target
$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET) $(LDFLAGS)

# Compile source files
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CFLAGS) -I$(INCLUDEDIR) -c $< -o $@

# Clean build files
clean:
	rm -rf $(OBJDIR)/*
	rm -rf $(BINDIR)/*

# Build all
all: $(TARGET)

# Run the game using emrun
run: $(TARGET)
	emrun index.html

.PHONY: clean all run