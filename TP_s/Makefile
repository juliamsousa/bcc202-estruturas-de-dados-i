all:  lista.o main.o 
	g++ -o main main.cpp 

lista.o: lista.cpp
	g++ -o lista.o -c lista.cpp

clean: 
	rm -f *.o main
run:
	./main
