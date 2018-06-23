# Compiler command
CC = g++

# The root directory of headers
IDIR = -I./include -I./Robust

# The root directory of the includes
ODIR = .

# Compile Flags
CFLAGS= $(IDIR) -std=c++14 -lpthread -Wall

# Linker Flags
LFLAGS = -pthread

HEADERS = $(shell find ./include -name '*.h')

# All singlefile tests: A quick macro for making test cases

DEPS = $(shell find ./src -name '*.cpp') 
OBJECTS = $(DEPS:.cpp=.o)

robust-robot: $(OBJECTS)  
	g++ -o robust-robot $(OBJECTS) ./Robust.a  $(LFLAGS)


%.o: %.cpp $(DEPS) $(HEADERS)
	$(CC) -c $(CFLAGS) $< -o $@

# Cleans up object files
.PHONY: clean
clean:
	rm $(OBJECTS)

