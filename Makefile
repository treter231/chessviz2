OBJ = 
CC = gcc
CFLAGS  = -Wall -Werror -std=c99

.PHONY: clean open

default: bin/board

test: ./bin/board-test
	./bin/board-test

./bin/board: ./build/main.o ./build/board.o ./build/check_strokes.o bin test
		$(CC) $(CFLAGS) -o ./bin/board ./build/main.o ./build/board.o ./build/check_strokes.o -lm

./build/main.o: ./src/main.c ./src/board.h build
		$(CC) $(CFLAGS) -o build/main.o -c src/main.c -lm

./build/board.o: ./src/board.c ./src/board.h build
		$(CC) $(CFLAGS) -o ./build/board.o -c ./src/board.c -lm

./build/check_strokes.o: ./src/check_strokes.c ./src/check_strokes.h build
		$(CC) $(CFLAGS) -o ./build/check_strokes.o -c ./src/check_strokes.c -lm

bin/board-test: ./build/main_test.o ./build/board.o ./build/check_strokes.o bin
	$(CC) $(CFLAGS) ./build/main_test.o ./build/board.o ./build/check_strokes.o -o bin/board-test -lm

./build/main_test.o: ./test/main.c ./thirdparty/ctest.h ./src/board.h ./src/check_strokes.h build
	$(CC) $(CFLAGS) -I thirdparty -I src -c ./test/main.c -o ./build/main_test.o -lm

build:
	mkdir build

bin:
	mkdir bin

clean:
	rm -rf build bin

open:
	./bin/board