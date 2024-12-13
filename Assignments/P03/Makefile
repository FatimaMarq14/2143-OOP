# Makefile for SFML Project

# Compiler and flags
CXX = g++
CXXFLAGS = -I/mingw64/include
LDFLAGS = -L/mingw64/lib -lsfml-graphics -lsfml-window -lsfml-system

# Source files and output
SRC = main.cpp
OUT = main

# Rule for building the project
$(OUT): $(SRC)
	$(CXX) $(SRC) -o $(OUT) $(CXXFLAGS) $(LDFLAGS)  # This line should start with a tab

# Clean rule to remove compiled files
clean:
	rm -f $(OUT)  # This line should also start with a tab
