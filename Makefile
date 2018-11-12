SRC=jeu.c display.c menu.c
BIN=jeu

$(BIN): $(SRC) display.h constants.h menu.h
	gcc -g -std=c99 $(SRC) `sdl-config --cflags --libs` -o $(BIN)

clean:
	rm -f $(BIN)
