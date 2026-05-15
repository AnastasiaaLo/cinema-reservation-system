# Makefile pentru Sistem Rezervare Cinema
# Compilare: make
# Curatare: make clean
# Rulare:   make run

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude
SRC_DIR = src
OBJ_DIR = obj
BIN = cinema

SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

all: $(BIN)

$(BIN): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(BIN)
	./$(BIN)

clean:
	rm -rf $(OBJ_DIR) $(BIN)

.PHONY: all run clean
