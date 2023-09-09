CC := g++ -std=c++11

all: 1.out

1.out: main.o JsonObject.o JsonBuilder.o Exceptions.o
	$(CC) main.o JsonObject.o JsonBuilder.o Exceptions.o -o 1.out

main.o: main.cpp JsonObject.hpp JsonBuilder.hpp Exceptions.hpp
	$(CC) -c main.cpp -o main.o

JsonBuilder.o: JsonBuilder.hpp JsonBuilder.cpp JsonObject.hpp Exceptions.hpp
	$(CC) -c JsonBuilder.cpp -o JsonBuilder.o

JsonObject.o: JsonObject.hpp JsonObject.cpp Exceptions.hpp
	$(CC) -c JsonObject.cpp -o JsonObject.o

Exceptions.o: Exceptions.hpp Exceptions.cpp
	$(CC) -c Exceptions.cpp -o Exceptions.o

clean:
	rm -r *.o
	rm -r *.out