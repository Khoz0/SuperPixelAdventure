SRC=jeu.c
SRC1=display.c
BIN=jeu

$(BIN): $(SRC)
	gcc -g -std=c99 $(SRC) `sdl-config --cflags --libs` -o $(BIN)

clean:
	rm -f $(BIN)
