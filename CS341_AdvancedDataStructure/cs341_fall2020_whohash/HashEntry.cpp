// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// Kyle Angelbeck
// Paul Merkamp

#include "HashEntry.h"

HashEntry::HashEntry(): key_(0), value_(0), status_(EMPTY) {}
HashEntry::HashEntry(int key, int value): key_(key), value_(value), status_(EMPTY) {}
HashEntry::~HashEntry() {}

int HashEntry::getKey() { return key_; }
void HashEntry::setKey(int key) {key_ = key;}

int HashEntry::getValue() {return value_;}
void HashEntry::setValue(int value) {value_ = value;}

Status HashEntry::getStatus() {return status_;}
void HashEntry::setStatus(Status status) {status_ = status;}
