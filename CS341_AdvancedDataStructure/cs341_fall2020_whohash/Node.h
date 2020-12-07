// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// Kyle Angelbeck
// Paul Merkamp

#ifndef NODE_H
#define NODE_H

// Header File for Node class.
class Node
{
    // Public Constructors/Destructors/Member Methods
    public:
        // constructor
		Node(int data);
		// destructor
		virtual ~Node();

        /**
        * Getter of node's data
        * @return int
        */
        virtual int getData();
        /**
        * Setter of node's data
        */
		virtual void setData(int data);
    private:
        // data of the node - hidden
        int data_;
    protected:
        // attempted prevention of an empty node
        Node();
};

#endif
