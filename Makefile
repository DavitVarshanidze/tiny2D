CC = g++
LANG_STD = -std=c++17
COMPILER_FLAG = -Wall -Wfatal-errors
INCLUDE_PATH = -I"./libs" -I/opt/homebrew/include/ -L/opt/homebrew/lib
SOURCE_FILES = src/*.cpp src/Game/*.cpp
LINKER_FLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer -llua -lspdlog -lfmt
OBJ_NAME = gameengine

build:
	$(CC) $(COMPILER_FLAGS) $(LANG_STD) $(SOURCE_FILES) $(INCLUDE_PATH) $(LINKER_FLAGS) -o ${OBJ_NAME};

run:
	./${OBJ_NAME}

clean:
	rm ${OBJ_NAME}
