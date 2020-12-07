// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// Kyle Angelbeck
// Paul Merkamp

#include "BitVector.h"
#include <bitset>

// Private constructor
BitVector::BitVector() : data_(nullptr) {}

// Public Constructors
BitVector::BitVector(std::vector<int> * data) : data_(data) {}
BitVector::BitVector(int size) : data_(new std::vector<int>(size, 0)) {}
BitVector::~BitVector() {delete data_;}

std::vector<int> * BitVector::getData() {return data_;}
void BitVector::setData(std::vector<int> * data) {data_ = data;}

bool BitVector::getBit(int position) {
    /* 32 bits per integer, so dividing by 32 will give us
     * The correct integer in the vector, and modulo will
     * give us the correct bit position within the integer
     */
    // Integer division truncates

    // Create a bitset of the integer at position / 32
    std::bitset<32> intBitSet (data_->at(position / 32));

    // Return the bit at position modulo 32
    return intBitSet[position % 32];
}

void BitVector::setBit(int position, bool value) {
    std::bitset<32> intBitSet (data_->at(position / 32));
    intBitSet[position % 32] = value;
    data_->at(position / 32) = (int)(intBitSet.to_ulong());
}

// data is the raw integers from the data.txt to check if they are duplicated
// data_ is the bitvector tracking which ints have been used
// duplicates is the Dictionaries tracking the counts of each duplicate
void BitVector::findDuplicates(std::vector<int> data, std::vector<Dictionary> & duplicates) {

    for(int d : data) {
        // If new int, setBit to 1, else add to duplicates
        if(!getBit(d)) {
            setBit(d, true);
        } else {
            // If dictionary already exists, increment it.
            bool entryFound = false;
            for(int i = 0; i < duplicates.size(); i++) {
                if(duplicates[i].getId() == d) {
                    duplicates[i].setData(duplicates[i].getData()+1);
                    entryFound = true;
                    break;
                }
            }
            // Else create a new Dictionary entry for d
            if(!entryFound) duplicates.push_back(Dictionary(d,1));
        }
    }
}
