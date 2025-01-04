build:
	g++ -Wall -std=c++17 src/*.cpp -I"./libs" -I/opt/homebrew/include/ -L/opt/homebrew/lib -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer -llua -o gameengine;

run:
	./gameengine

clean:
	rm gameengine
