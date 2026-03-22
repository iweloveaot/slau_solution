CC = g++
CCFLAGS = -std=c++17 -Wall -Wextra
TARGET = slau_solution
SOURCES = main.cpp slau_solution.cpp for_experiments.cpp experiments.cpp
OBJECTS = $(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CCFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Цели для запуска с конкретной функцией
exp1: $(TARGET)
	./$(TARGET) exp1

exp2: $(TARGET)
	./$(TARGET) exp2

exp3: $(TARGET)
	./$(TARGET) exp3

clean:
	rm -f $(OBJECTS) $(TARGET)
