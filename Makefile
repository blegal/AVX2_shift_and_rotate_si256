CC=g++

CFLAGS=-O3 -march=native -mtune=native -std=c++11

LDFLAGS=

EXEC=main

SRC=./src/main.cpp

OBJ= $(SRC:.cpp=.o)

all: $(EXEC)

main: $(OBJ)
	$(CC) $(CFLAGS) -o ./bin/$@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CC) $(CFLAGS) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper

clean:
	find . -name "./bin/main"    -exec rm {} \;

mrproper: clean
	rm $(EXEC)
