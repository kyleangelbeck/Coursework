// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// Kyle Angelbeck
// Paul Merkamp

#include "Dictionary.h"

Dictionary::Dictionary(): id_(0), data_(0) {}
Dictionary::Dictionary(int id, int data): id_(id), data_(data) {}
Dictionary::~Dictionary() {}

int Dictionary::getId() { return id_.getData(); }
void Dictionary::setId(int id) {id_ = Node(id);}

int Dictionary::getData() {return data_.getData();}
void Dictionary::setData(int data) {data_ = Node(data);}
