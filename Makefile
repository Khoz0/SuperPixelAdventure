SRC=jeu.c mapBuilder.c mapBoolean.c
BIN=jeu

$(BIN): $(SRC) mapBuilder.h constants.h mapBoolean.h
	gcc -g -std=c99 $(SRC) `sdl-config --cflags --libs` -o $(BIN)

clean:
	rm -f $(BIN)
