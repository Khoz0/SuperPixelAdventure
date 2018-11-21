SRC=jeu.c mapBuilder.c mapBoolean.c menu.c isFull.c 
BIN=jeu

$(BIN): $(SRC) mapBuilder.h constants.h mapBoolean.h menu.h isFull.h
	gcc -g -std=c99 $(SRC) `sdl-config --cflags --libs` -lSDL_ttf -lSDL_mixer -lm -o $(BIN)

clean:
	rm -f $(BIN)
