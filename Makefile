main: main.o
	gcc -std=c11 -Wall -Wextra main.o -o main

main.o: main.c
	gcc -std=c11 -Wall -Wextra -c main.c -o main.o

clean:
	rm main main.o

launch: main
	./main
