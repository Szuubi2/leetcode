# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -Ilib #-I/usr/include/SDL2 to add SDL

# Source files
SRCS = main.cpp #lib/lib1.c

# Object files (replace .cpp/.c with .o in SRCS)
OBJS = $(SRCS:.cpp=.o)
OBJS := $(OBJS:.c=.o)

# Target executable
TARGET = program

# Build the executable
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET) #-lSDL2  # Link against SDL2

# Compile main.cpp and lib1.c to object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

%.o: %.c
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(OBJS) $(TARGET)

# Phony targets to avoid conflicts with files named 'clean' or 'all'
.PHONY: all clean