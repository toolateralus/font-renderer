COMPILER := clang++
COMPILER_FLAGS := -std=c++23 -Ideps -g
LD_FLAGS := -lGL -lGLEW -lglfw -lfreetype
OBJ_DIR := objs
BIN_DIR := bin

SRCS := $(wildcard *.cpp)
OBJS := $(patsubst %.cpp,$(OBJ_DIR)/%.o,$(wildcard *.cpp))

all: directories font

directories:
	mkdir -p $(OBJ_DIR) $(BIN_DIR)

font: $(OBJS)
	$(COMPILER) $(COMPILER_FLAGS) -o $(BIN_DIR)/$@ $^ $(LD_FLAGS)

$(OBJ_DIR)/%.o: %.cpp
	mkdir -p $(@D)
	$(COMPILER) $(COMPILER_FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

run: all font
	./$(BIN_DIR)/font