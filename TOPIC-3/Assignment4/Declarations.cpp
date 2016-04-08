#include "Assignment4.h"

// DLNode Definitions
DLNode::DLNode() {
    contents = "None";
    previous_node = NULL;
    next_node = NULL;
}

DLNode::DLNode(string newContents) {
    contents = newContents;
}

DLNode::~DLNode() {
    // Do nothing
}

void DLNode::setContents(string newContents) {
    contents = newContents;
}

void DLNode::setNext(DLNode* newNext) {
    next_node = newNext;
}

void DLNode::setPrevious(DLNode* newPrevious) {
    previous_node = newPrevious;
}

string DLNode::getContents() const {
    return contents;
}

DLNode* DLNode::getNext() const {
    return next_node;
}

DLNode* DLNode::getPrevious() const {
    return previous_node;
}

// DLList Class Definitions
DLList::DLList() {
    node_count = 0;
    head_node = NULL;
    tail_node = NULL;
}

DLList::~DLList() {
    // Come back to this (CLEAR FUNCTION)
}

unsigned int DLList::getSize() const {
    return node_count;
}

void DLList::pushFront(string newContents) {
    // Create new DLNode with newContents and attach at the head
}

void DLList::pushBack(string newContents) {
    // Create new DLNode with newContents and attach at the tail
}

void DLList::insert(string newContents) {
    // Inserts New Node with newContents and attach in order
    /*
    DLNode* temp;
    temp = head_node;
    
    if(head_node == NULL || newContents <= temp->getContents()) {
        pushFront(newContents);
    }
    else if(tail_node->getContents() < newContents) {
        pushBack(newContents);
    }
    else
    {
            DLNode* previous = temp;
            
            while(temp->getContents() < getContents) {
                previous = temp;
                temp = temp->getNext();
            }
            
            DLNode* new_node = new DLNode(newContents);
            new_node->setNext(temp);
            previous->setNext(new_node);
            size_ = size_ + 1;
    }*/
}

string DLList::getFront() const {
    // Return content of head node
}

string DLList::getBack() const {
    // Return content of tail node
}

bool DLList::get(string target) const {
    // Return true if target is in list, else return false
    return false;
}

string getStop(int number) {
    
}

void DLList::popFront() {
    // Remove current head node; do nothing if list is empty
}

void DLList::popBack() {
    // Remove current head node; do nothing if list is empty
}

bool DLList::removeFirst(string target) {
    
}

bool DLList::removeAll(string target) {
    
}

void DLList::clear() {
    // Clear ALL nodes, reset count to zero, set head and tail to NULL
}

ostream& operator<<(ostream& out, const DLList& src) {
/*
 *
 *  display the contents of each node in the list
 *  formatted per the program specification
 *  ("NUM1,NUM2,NUM3,...,NUMX")
 *  to the output stream out
 *
 */
}