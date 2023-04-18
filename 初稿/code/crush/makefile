CXX = g++
SRC=src/
OBJ=obj/
TOOLPATH=../tools/src/
CXXFLAGS = -std=c++11 -Wall -Wextra -Wpedantic -I ./inc -I ../tools/inc
EXECUTABLE = main.exe

VPATH=$(SRC):$(TOOLPATH)
# Automatically detect all .cpp files in the directory
SOURCES = $(wildcard $(SRC)*.cpp)
TOOLS = $(wildcard $(TOOLPATH)*.cpp)

# Generate a list of object files from the source files
OBJECTS=$(SOURCES:.cpp=.o)
TOOLTARGET=$(TOOLS:.cpp=.o)

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) $(TOOLTARGET)
	$(CXX) $(CXXFLAGS) $^ -o $(EXECUTABLE)
	mv $(SRC)*.o $(OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	-rm -f $(EXECUTABLE) 
	-rm -f $(OBJ)*.o
	-rm -f $(TOOLPATH)*.o

