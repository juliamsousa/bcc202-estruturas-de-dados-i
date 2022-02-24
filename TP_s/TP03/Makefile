all: lista.o main.cpp
	g++ -o main main.cpp lista.o
lista.o: lista.cpp
	g++ -o lista.o -c lista.cpp
	
clean:
	rm -f *.o
run:
	./main
