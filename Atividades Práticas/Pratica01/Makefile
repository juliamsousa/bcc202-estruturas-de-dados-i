all: professortad.o disciplinatad.o alunotad.o  main.cpp
	g++ -o main main.cpp professortad.o disciplinatad.o alunotad.o
professortad.o: professortad.cpp
	g++ -o professortad.o -c professortad.cpp
disciplinatad.o: disciplinatad.cpp
	g++ -o disciplinatad.o -c disciplinatad.cpp
alunotad.o: alunotad.cpp
	g++ -o alunotad.o -c alunotad.cpp

clean:
	rm -f *.o
run:
	./main < input.txt > output.txt 
