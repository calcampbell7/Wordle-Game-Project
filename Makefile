CC = gcc
CFLAGS = -Wall -Wextra -std=c11

wordgame: main.o game.o
	$(CC) $(CFLAGS) main.o game.o -o wordgame

main.o: main.c game.h
	$(CC) $(CFLAGS) -c main.c

game.o: game.c game.h
	$(CC) $(CFLAGS) -c game.c

clean:
	rm -f *.o wordgame