all: professortad.o disciplinatad.o alunotad.o encargotad.o atestadotad.o main.cpp
	g++ -o main main.cpp professortad.o disciplinatad.o alunotad.o encargotad.o atestadotad.o
professortad.o: professortad.cpp
	g++ -o professortad.o -c professortad.cpp
disciplinatad.o: disciplinatad.cpp
	g++ -o disciplinatad.o -c disciplinatad.cpp
alunotad.o: alunotad.cpp
	g++ -o alunotad.o -c alunotad.cpp
encargotad.o: encargotad.cpp
	g++ -o encargotad.o -c encargotad.cpp
atestado.o: atestado.cpp
	g++ -o atestado.o -c atestado.cpp
	
clean:
	rm -f *.o
run:
	./main < input.txt > output.txt 
