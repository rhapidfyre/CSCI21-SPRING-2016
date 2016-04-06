// Michael Harris
// CSCI 21
// March 28th 2016

#include "sl_list.h"
#include "sl_node.h"

SLList::SLList() {
    head_ = NULL;
    tail_ = NULL; // NEW
    size_ = 0;
}
SLList::~SLList() {
    Clear();
}
void SLList::InsertHead(int contents) {
    // Create a new object and fill it with contents
    SLNode *new_node = new SLNode(contents);
    // Set the node of the existing node's head to this new object
    new_node->set_next_node(head_);
    // Set this object's head to the existing node
    head_ = new_node;
    if(tail_ == NULL) {
        tail_ = new_node;
    }
    size_ = size_ + 1;
}
void SLList::InsertTail(int contents) {
    //Same as Head but a tad bit different.
    SLNode *new_node = new SLNode(contents);
    new_node->set_next_node(tail_);
    tail_ = new_node;
    if(head_ == NULL) {
        head_ = new_node;
    }
    size_ = size_ + 1;
}
void SLList::RemoveHead() {
    if (head_ != NULL){
        // Create Temp
        SLNode* temp;
        // Point Temp to Head
        temp = head_;
        // Head to Next
        head_ = temp->next_node();
        // Delete
        delete temp;
        // NULL
        temp = NULL;
        size_ = size_ - 1;
    }
}
void SLList::RemoveTail() {
    // Removes the last node from the list, or does nothing if empty
    if (tail_ != NULL) {
        SLNode* temp;
        while(temp->next_node() != tail_) {
            delete tail_;
            temp->set_next_node(NULL);
            tail_ = temp;
        }
        temp = NULL;
        size_ = size_ - 1;
    }
}
void SLList::Clear() {
    // Loop until the head is null, which means we're out of objects
    while(head_ != NULL) {
        RemoveHead();
    }
    tail_ = NULL; //NEW
}
int SLList::GetHead() const {
    // Returns the contents of the head node, returns 0 if empty
    if(head_ != NULL) {
        int get_contents = head_->contents();
        return get_contents;
    }
    return 0;
}
int SLList::GetTail() const {
    // Returns the contents of the tail node, returns 0 if empty
    if(tail_ != NULL) {
        int get_contents = tail_->contents();
        return get_contents;
    }
    return 0;
}
unsigned int SLList::size() const {
    return size_;
}
string SLList::ToString() const {
    // Create Stringstream
    stringstream ss;
    if (head_ == NULL)
        return "";
    // Create Temp
    SLNode* temp;
    temp = head_;
    
    // While loop through each obj
    while(temp != NULL) {
        ss << temp->contents();
        if(temp->next_node() != NULL) {
            ss << ", ";
        }
        temp = temp->next_node();
    }
    temp = NULL;
    
    return ss.str();
}