
.PHONY: all

all: main

main: ./src/leitura.c ./src/solver.c ./src/main.c
	gcc ./src/leitura.c ./src/solver.c ./src/main.c -o main

clean:
ifeq ($(OS),Windows_NT)
	del main
else
	rm main
endif