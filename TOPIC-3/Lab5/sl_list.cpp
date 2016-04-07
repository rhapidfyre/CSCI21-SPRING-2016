// Michael Harris
// CSCI 21
// March 28th 2016

#include "sl_list.h"
#include "sl_node.h"
#include <iostream>

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
    tail_->set_next_node(new_node);
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
        SLNode* temp = head_;
        while(temp->next_node() != tail_) {
            temp = temp->next_node();
        }
        temp->set_next_node(NULL);
        delete tail_;
        tail_ = temp;
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
void SLList::Insert(int contents) {
    // If the head of the linked list is NULL, there is no list.
    // Insert as new Head
    
    // Create Pointers
    SLNode* temp;
    temp = head_;
        
    if(head_ == NULL || contents <= temp->contents()) {
        InsertHead(contents);
    }
    else if(tail_->contents() < contents) {
        InsertTail(contents);
    }
    else
    {
            SLNode* previous = temp;
            
            // Loop temp through until it's pointed content is equal or higher
            // to the new node's content
            while(temp->contents() < contents) {
                previous = temp;
                temp = temp->next_node();
            }
            
            // Add New Node
            SLNode* new_node = new SLNode(contents);
            // Set next node of new node to the object of pointer temp
            new_node->set_next_node(temp);
            // Set next node of the object pointed by previous to new node
            previous->set_next_node(new_node);
            // Set the current node selected by temp to point at new node
            size_ = size_ + 1;
    }
}
bool SLList::RemoveFirstOccurence(int contents) {
    /*remove the first occurence of the supplied parameter
    found as the data of a node. Return true on successful
    removal or false if the list is empty or if the value
    is not found.*/
    if(head_ == NULL) {
        return false;
    }
    if(head_->contents() == contents) {
        RemoveHead();
        return true;
    }/*
    else if(tail_->contents() == contents) {
        RemoveTail();
        return true;
    }*/
    else {
        SLNode* i = head_;
        SLNode* previous = head_;
        
        while(i->contents() != contents && i->next_node() != tail_) {
            previous = i;
            i = i->next_node();
        }
        
        if(tail_->contents() == contents) {
            RemoveTail();
            return true;
        }
        
        else if(i->contents() == contents) {
            previous->set_next_node(i->next_node());
            delete i;
            i = NULL;
            size_ = size_ - 1;
            return true;
        }
        else
        {
            return false;
        }
    }
    return false;
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