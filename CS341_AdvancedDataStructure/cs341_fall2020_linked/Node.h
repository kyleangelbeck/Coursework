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
template <class T>
class Node
{
    // Public Constructors/Destructors/Member Methods
    public:
        // constructor
		Node(T data);
		// destructor
		virtual ~Node();

        /**
        * Getter of node's data
        * @return T
        */
        virtual T getData();
        /**
        * Setter of node's data
        */
		virtual void setData(T data);
    private:
        // data of the node - hidden
        T data_;
    protected:
        // attempted prevention of an empty node
        Node();
};

#endif
