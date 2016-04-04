#include "Assignment4.h"

// DLNode Definitions
DLNode::DLNode() {
    contents_ = 0;
    previous_node_ = NULL;
    next_node_ = NULL;
}

DLNode::DLNode(int newContents) {
    contents_ = newContents;
}

DLNode::~DLNode() {
    // Do nothing
}

void DLNode::setContents(int newContents) {
    contents_ = newContents;
}

void DLNode::setNext(DLNode* newNext) {
    next_node_ = newNext;
}

void DLNode::setPrevious(DLNode* newPrevious) {
    previous_node_ = newPrevious;
}

int DLNode::getContents() {
    return contents_;
}

DLNode* DLNode::getNext() {
    return next_node_;
}

DLNode* DLNode::getPrevious() {
    return previous_node_;
}

// DLList Class Definitions
DLList::DLList() {
    node_count_ = 0;
    head_node_ = NULL;
    tail_node = NULL;
}

DLList::~DLList() {
    // Come back to this (CLEAR FUNCTION)
}

unsigned int DLList::getSize() {
    return node_count_;
}

void DLList::pushFront(int newContents) {
    // Create new DLNode with newContents and attach at the head
}

void DLList::pushBack(int newContents) {
    // Create new DLNode with newContents and attach at the tail
}

int DLList::getFront() {
    // Return content of head node
    return /**/;
}

int DLList::getBack() {
    // Return content of tail node
    return /**/;
}

bool DLList::get(int target) {
    // Return true if target is in list, else return false
    return false;
}

void DLList::popFront() {
    // Remove current head node; do nothing if list is empty
}

void DLList::popBack() {
    // Remove current head node; do nothing if list is empty
}

bool DLList::removeFirst(int target) {
    
}

bool DLList::removeAll(int target) {
    
}

void DLList::clear() {
    // Clear ALL nodes, reset count to zero, set head and tail to NULL
}

friend ostream& operator<<(ostream& out, const DLList& src) {
/*
 *
 *  display the contents of each node in the list
 *  formatted per the program specification
 *  ("NUM1,NUM2,NUM3,...,NUMX")
 *  to the output stream out
 *
 */
}