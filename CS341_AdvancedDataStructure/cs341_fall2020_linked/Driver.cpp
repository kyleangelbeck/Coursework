// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// Kyle Angelbeck
// Paul Merkamp

#include "DoubleLinkedList.h"

#include <iostream>
#include <fstream>
#include <string>

void doAssignment(std::string fileIn, std::string fileOut);

int main() {
    std::ofstream clearReadme;
    clearReadme.open("README.txt",std::ofstream::trunc);
    clearReadme.close();


    doAssignment("data.txt", "output.txt");
    doAssignment("sorted.txt", "sortedOutput.txt");

    return 0;
}

void doAssignment(std::string fileIn, std::string fileOut) {
    // read in data from data.txt
    std::ifstream readDataIn;

    std::cout << "Retrieving data from " << fileIn << std::endl;
    readDataIn.open(fileIn);
    // exit if file could not be read
    if (!readDataIn) {
        std::cout << "Read in of " << fileIn << " failed." << std::endl;
        exit(1);
    }

    // write read-in integers to linked nodes in doubly linked list
    DoubleLinkedList<int> * dll = new DoubleLinkedList<int>();
    int x;
    while (readDataIn >> x){
        dll->insertNode(x);
    }

    readDataIn.close();

    // do inserts from inserts.txt
    std::ifstream readInsertsIn;

    readInsertsIn.open("inserts.txt");
    if (!readInsertsIn) {
        std::cout << "Read in of inserts.txt failed." << std::endl;
        exit(1);
    }

    int y;
    int totalHops(0);
    while (readInsertsIn >> y){
        // check if head or tail require less hops
        int hopsFromHead(0);
        LinkedNode<int> * hopsCheckHead = dll->getHead();
        while (hopsCheckHead!=nullptr && y>hopsCheckHead->getData()) {
            hopsCheckHead = hopsCheckHead->getNext();
            hopsFromHead++;
        }
        int hopsFromTail(0);
        LinkedNode<int> * hopsCheckTail = dll->getTail();
        while (hopsCheckTail!=nullptr && y<hopsCheckTail->getData()) {
            hopsCheckTail = hopsCheckTail->getPrev();
            hopsFromTail++;
        }

        if (hopsFromHead<hopsFromTail) {
            dll->insertBefore(hopsCheckHead, y);
            totalHops += hopsFromHead;
        } else {
            dll->insertAfter(hopsCheckTail, y);
            totalHops += hopsFromTail;
        }
    }
    readInsertsIn.close();

    std::ofstream readmeOut;
    readmeOut.open("README.txt", std::ofstream::app);
    if (!readmeOut.is_open()) {
        std::cout << "Read out failure" << std::endl;
    }
    readmeOut << "Hops in " << fileIn << ": " << totalHops << std::endl;
    readmeOut.close();

    std::ofstream sternumRub;
    sternumRub.open(fileOut);
    sternumRub << dll->getString();
    sternumRub.close();

    // dll->printList();

    delete dll;
}

