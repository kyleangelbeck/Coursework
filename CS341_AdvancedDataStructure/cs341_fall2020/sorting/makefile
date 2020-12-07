A1.exe: Driver.o Insertion.o Bubble.o
	g++ Driver.o Insertion.o Bubble.o -o A1.exe

Driver.o: Driver.cpp
	g++ -c Driver.cpp -o Driver.o

Insertion.o: Insertion.cpp
	g++ -c Insertion.cpp -o Insertion.o

Bubble.o: Bubble.cpp
	g++ -c Bubble.cpp -o Bubble.o

clean:
	rm -f Driver.o Insertion.o Bubble.o A1.exe