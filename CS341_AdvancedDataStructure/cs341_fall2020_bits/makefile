# Rule: Dependency Line
# <<TAB>> Shell Line

A3.exe: Driver.o BitVector.o Dictionary.o Node.o
	g++ Driver.o BitVector.o Dictionary.o Node.o -o A3.exe

Driver.o: Driver.cpp
	g++ -c Driver.cpp -o Driver.o

BitVector.o: BitVector.cpp
	g++ -c BitVector.cpp -o BitVector.o

Dictionary.o: Dictionary.cpp
	g++ -c Dictionary.cpp -o Dictionary.o

Node.o: Node.cpp
	g++ -c Node.cpp -o Node.o

clean:
	rm -f Driver.o BitVector.o Dictionary.o Node.o A3.exe