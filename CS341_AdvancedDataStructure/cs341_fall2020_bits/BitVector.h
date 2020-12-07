// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// Kyle Angelbeck
// Paul Merkamp

#ifndef BITVECTOR_H
#define BITVECTOR_H

#include "Dictionary.h"
#include <vector>

class BitVector {
    // Private attributes
    private:
        // Bit Vector
        std::vector<int> * data_;

        // Unaccessible empty constructor
        BitVector();

    // Public Methods
    public:
        // Constructor
        BitVector(std::vector<int> * data);
        BitVector(int size);
        // Decstructor
        ~BitVector();

        /**
         * Getter of BitVector's data vector
         * @return vector<int>
         */
        std::vector<int> * getData();

        /**
         * Setter of BitVector's data vector
         * @param vector<int>
         */
        void setData(std::vector<int> * data);

        /**
         * Gets the bit at the given position
         * @param int of position to be get
         * @return value of bit as a bool
         */
        bool getBit(int position);

        /**
         * Sets the bit at the given position
         * @param int of position to be set
         * @param bool value to be set at position
         */
        void setBit(int position, bool value);

        /**
         * This will identify the duplicates via our bit vector and store the list of them in another vector
         * @param vector<int> of data to check for duplicates
         * @param vector<int> that tracks duplicate integers
         */
        void findDuplicates(std::vector<int> data, std::vector<Dictionary> & duplicates);
};

#endif
