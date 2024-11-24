# Makefile for the wordsolver project

# Compiler to use
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -std=c++17

# Target executable
TARGET = wordsolver

# Source files
SRC = wordsolver.cpp

# Object files (automatically inferred from source files)
OBJ = $(SRC:.cpp=.o)

# Build the target executable
$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

# Compile the .cpp files into .o object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up the build files
clean:
	rm -f $(OBJ) $(TARGET)

# Phony targets (not files)
.PHONY: clean
