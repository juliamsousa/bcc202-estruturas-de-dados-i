all: algoritmosOrdenacao.o geraVetor.o  main.cpp
	g++ -o main main.cpp algoritmosOrdencao.o geraVetor.o
algoritmosOrdencao.o: algoritmosOrdenacao.cpp
	g++ -o algoritmosOrdenacao.o -c algoritmosOrdenacao.cpp
geraVetor.o: geraVetor.cpp
	g++ -o geraVetor.o -c geraVetor.cpp
	
clean:
	rm -f *.o
run:
	./main < input.txt > output.txt 
