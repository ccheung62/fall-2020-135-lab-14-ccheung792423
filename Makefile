main: main.o 
	g++ -o main main.o 

main.o: main.cpp MyVector.h MyVector.cxx

clean:
	rm -f main.o 
