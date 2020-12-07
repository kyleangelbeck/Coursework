# Rule: Dependency Line
# <<TAB>> Shell Line

A5.exe: Driver.o HashTableChaining.o HashTableArray.o HashEntry.o DoubleLinkedList.o LinkedList.o LinkedNode.o Node.o
	g++ Driver.o HashTableChaining.o HashTableArray.o HashEntry.o DoubleLinkedList.o LinkedList.o LinkedNode.o Node.o -o A5.exe

Driver.o: Driver.cpp
	g++ -c Driver.cpp -o Driver.o

HashTableChaining.o: HashTableChaining.cpp
	g++ -c HashTableChaining.cpp -o HashTableChaining.o

HashTableArray.o: HashTableArray.cpp
	g++ -c HashTableArray.cpp -o HashTableArray.o

HashEntry.o: HashEntry.cpp
	g++ -c HashEntry.cpp -o HashEntry.o

DoubleLinkedList.o: DoubleLinkedList.cpp
	g++ -c DoubleLinkedList.cpp -o DoubleLinkedList.o

LinkedList.o: LinkedList.cpp
	g++ -c LinkedList.cpp -o LinkedList.o

LinkedNode.o: LinkedNode.cpp
	g++ -c LinkedNode.cpp -o LinkedNode.o

Node.o: Node.cpp
	g++ -c Node.cpp -o Node.o

clean:
	rm -f Driver.o HashTableChaining.o HashTableArray.o HashEntry.o DoubleLinkedList.o LinkedList.o LinkedNode.o Node.o A5.exe
