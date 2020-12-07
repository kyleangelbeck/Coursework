// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// Kyle Angelbeck
// Paul Merkamp

#include <algorithm>    //std::sort
#include <fstream>      //std::ifstream, std::ofstream
#include <iostream>     //std::cout
#include <vector>       //std::vector
#include "BitVector.h"

/**
 * Compare the values of two dictionaries to be used in std::sort()
 * @param two Dictionaries to compare
 * @return true if first Dictionary is larger, else false
 */
bool compareDictionaries(Dictionary a, Dictionary b){
    return a.getData() > b.getData();
}

int main() {
    
    // Read in data from data.txt
    std::ifstream readDataIn;
    std::cout << "Retrieving data from data.txt" << std::endl;
    readDataIn.open("data.txt");
    // Exit if file could not be read
    if (!readDataIn) {
        std::cout << "Read in of data.txt failed." << std::endl;
        exit(1);
    }

    // Write read-in integers to integer vector
    std::vector<int> dataVector;
    int x;
    while (readDataIn >> x){
        dataVector.push_back(x);
    }
    std::vector<Dictionary> dictionaryVector;

    // Use bit vector to find duplicates, and then sort them
    BitVector bitVector(1000);
    bitVector.findDuplicates(dataVector, dictionaryVector);
    std::sort (dictionaryVector.begin(), dictionaryVector.end(), compareDictionaries);

    // Output duplicates to "duplicates.txt"
    std::ofstream sternumRub;
    sternumRub.open("duplicates.txt");
    if (!sternumRub.is_open()) {
        std::cout << "Read out failure" << std::endl;
    }
    for (Dictionary d: dictionaryVector) { sternumRub << d.getId() << " : " << d.getData()+1 << std::endl; }
    sternumRub.close();

    return 0;   
}
