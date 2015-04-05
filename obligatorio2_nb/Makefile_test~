CC= g++
WARNING = -Wall -Werror
LIB=

todo: main

Estrategias.o:	Estrategias.cpp Estrategias.h 
	$(CC) -c Estrategias.cpp $(WARNING)
Mundo.o: Mundo.cpp Mundo.h 
	$(CC) -c Mundo.cpp $(WARNING)
Territorio.o: Territorio.cpp Territorio.h 
	$(CC) -c Territorio.cpp $(WARNING)

main.o: main.cpp Estrategias.h Mundo.h Territorio.h ListaEnteros.h ColaEnteros.h
	$(CC) -c main.cpp $(WARNING)
main: main.o Estrategias.o Mundo.o Territorio.o ListaEnteros.o ColaEnteros.o 
	$(CC) main.o Estrategias.o Mundo.o Territorio.o ListaEnteros.o ColaEnteros.o -o main $(LIB)


clean:
	rm Estrategias.o
	rm Mundo.o
	rm Territorio.o
	rm main.o
	rm main	
