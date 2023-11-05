# Compiler and compiler flags
CXX = g++
CXXFLAGS = -g -std=c++14 -Wall -Wextra

# Source files and output binary
#TODO: Change name of source file
SRC_FILES = main.cpp 
OUTPUT = chi_compiler

OBJ_FILES = $(SRC_FILES:.cpp=.o)

all: $(OUTPUT)

$(OUTPUT): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_FILES) $(OUTPUT)

