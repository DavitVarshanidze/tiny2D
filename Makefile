# CC = g++
# LANG_STD = -std=c++17
# COMPILER_FLAGS = -Wall -Wfatal-errors
# INCLUDE_PATH = -I"./libs/" -I/opt/homebrew/include -L/opt/homebrew/lib
# SRC_FILES = ./src/*.cpp \
# 			./src/Game/*.cpp \
# 			./src/Logger/*.cpp \
# 			./src/ECS/*.cpp \
# 			./src/AssetStore/*.cpp \
# 			./libs/imgui/*.cpp
# LINKER_FLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer -llua
# OBJ_NAME = tiny2d

# build:
# 	$(CC) $(COMPILER_FLAGS) $(LANG_STD) $(INCLUDE_PATH) $(SRC_FILES) $(LINKER_FLAGS) -o $(OBJ_NAME)

# run:
# 	./$(OBJ_NAME)

# clean:
# 	rm $(OBJ_NAME)

###############################################################

# So basically I reworked makefile to support windows
# However if it's not building correctly and you checked that you have installed neccesary libraries, please check path's

CC = g++
LANG_STD = -std=c++17
COMPILER_FLAGS = -Wall -Wfatal-errors

SRC_FILES = ./src/*.cpp \
            ./src/Game/*.cpp \
            ./src/Logger/*.cpp \
            ./src/ECS/*.cpp \
            ./src/AssetStore/*.cpp \
            ./libs/imgui/*.cpp

UNAME := $(shell uname)

ifeq ($(UNAME), Darwin)  # macOS
    INCLUDE_PATH = -I"./libs/" -I/opt/homebrew/include
    LIB_PATH = -L/opt/homebrew/lib
    LINKER_FLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer -llua
    OBJ_NAME = tiny2d
    RM = rm -f
else  # Windows (assume MSYS2/MinGW)
    INCLUDE_PATH = -I"./libs/" -IC:/libs/SDL2/include -IC:/libs/lua/include
    LIB_PATH = -LC:/libs/SDL2/lib -LC:/libs/lua/lib
    LINKER_FLAGS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer -llua
    OBJ_NAME = tiny2d.exe
    RM = del
endif

build:
	$(CC) $(COMPILER_FLAGS) $(LANG_STD) $(INCLUDE_PATH) $(LIB_PATH) $(SRC_FILES) $(LINKER_FLAGS) -o $(OBJ_NAME)

run:
	./$(OBJ_NAME)

clean:
	$(RM) $(OBJ_NAME)