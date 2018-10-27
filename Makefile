SRC=jeu.c display.c 
BIN=jeu

$(BIN): $(SRC) display.h constants.h
	gcc -g -std=c99 $(SRC) `sdl-config --cflags --libs` -o $(BIN)

clean:
	rm -f $(BIN)
