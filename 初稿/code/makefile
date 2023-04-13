CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -Wpedantic
EXECUTABLE = main.exe

# Automatically detect all .cpp files in the directory
SOURCES = $(wildcard *.cpp)

# Generate a list of object files from the source files
OBJECTS = $(SOURCES:.cpp=.o)

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(EXECUTABLE)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(EXECUTABLE) $(OBJECTS)
