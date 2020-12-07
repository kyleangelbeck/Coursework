// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// Kyle Angelbeck

#include <fstream>      // File Stream
#include <iostream>     // Input/Output Stream
#include <string>       // Strings

#include "Sort.h"
#include "Insertion.h"
#include "Bubble.h"

// Main Function
int main()
{   
    // User inputs
    bool sorting = true;
    std::string sortSpecifier;
    std::string inFile;
    std::string outFile;

    // Sorting Objects
    Bubble bubble;
    Insertion insertion;

    // Store output of std::getline()
    std::string value;

    // File Streams
    std::ifstream inStream;
    std::ofstream outStream;
    
    while(sorting) {
        // Get inputs from user
        std::cout << "Enter the name of the input file:" << std::endl;
        std::cin >> inFile;

        std::cout << "Would you like to sort this file using (b)ubble sort or (i)nsertion sort?" << std::endl;
        std::cin >> sortSpecifier;
        if(sortSpecifier != "b" && sortSpecifier != "i") {
            std::cout << "ERROR: Invalid Input" << std::endl;
            exit(EXIT_FAILURE);
        }

        std::cout << "Enter the name of the output file:" << std::endl;
        std::cin >> outFile;


        // Open ifstream
        inStream.open(inFile);
        if(!inStream.is_open()) {
            std::cout << "ERROR: Could not open the input file \"" << inFile << "\"" << std::endl;
            exit(EXIT_FAILURE);
        }

        // First loop through file to determine array length
        int arrayLength = 0;
        while(std::getline(inStream, value, ' ')) {
            arrayLength++;
        }

        // Create unsorted array
        int array[arrayLength];

        // Move inStream to beginning of file
        inStream.clear();
        inStream.seekg(0);

        // Second loop through file to fill unsorted array
        int arrayPos = 0;
        while(std::getline(inStream, value, ' ')) {
            array[arrayPos] = std::stoi(value);
            arrayPos++;
        }

        // Close ifstream
        inStream.close();


        // Sort array
        if(sortSpecifier == "b") {
            bubble.sortArray(array, arrayLength);
        } else if(sortSpecifier == "i") {
            insertion.sortArray(array, arrayLength);
        } else {
            // Should never reach here
            std::cout << "ERROR: Neither 'i' or 'b' were inputted for sorting specification" << std::endl;
            exit(EXIT_FAILURE);
        }

 
        // Open ofstream
        outStream.open(outFile);
        if(!outStream.is_open()) {
            std::cout << "ERROR: Could not open the output file \"" << outFile << "\"" << std::endl;
            exit(EXIT_FAILURE);
        }

        // Fill outfile
        for(int i = 0; i < arrayLength; i++) {
            outStream << array[i] << " ";
        }

        // Close ofstream
        outStream.close();


        // Update while() conditional
        std::string temp = "";
        while(temp != "Y" && temp != "N") {
            std::cout << "Would you like to continue (‘Y’) or terminate (‘N’)?" << std::endl;
            std::cin >> temp;
        }
        sorting = temp == "Y";
    }
    
    return 0;
}
