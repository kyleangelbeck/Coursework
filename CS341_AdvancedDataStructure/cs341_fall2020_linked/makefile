# Rule: Dependency Line
# <<TAB>> Shell Line

A2.exe: Driver.o DoubleLinkedList.o LinkedList.o LinkedNode.o Node.o
	g++ Driver.o DoubleLinkedList.o LinkedList.o LinkedNode.o Node.o -o A2.exe

Driver.o: Driver.cpp
	g++ -c Driver.cpp -o Driver.o

DoubleLinkedList.o: DoubleLinkedList.cpp
	g++ -c DoubleLinkedList.cpp -o DoubleLinkedList.o

LinkedList.o: LinkedList.cpp
	g++ -c LinkedList.cpp -o LinkedList.o

LinkedNode.o: LinkedNode.cpp
	g++ -c LinkedNode.cpp -o LinkedNode.o

Node.o: Node.cpp
	g++ -c Node.cpp -o Node.o

clean:
	rm -f Driver.o DoubleLinkedList.o LinkedList.o LinkedNode.o Node.o A2.exe
