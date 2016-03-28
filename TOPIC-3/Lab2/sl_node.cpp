// Michael Harris
// CSCI 21
// March 28th 2016

#include "sl_node.h"

// Default Constructor.
SLNode::SLNode() {
    next_node_ = NULL;
    contents_ = 0;
}
// Constructor with contents parameter
SLNode::SLNode(int contents) {
    //Setting next node to null by default
    next_node_ = NULL;
    contents_ = contents;
}
// Destructor (does nothing)
SLNode::~SLNode() {
    
}
// Change the contents of the object
void SLNode::set_contents(int contents){
    contents_ = contents;
}
// Set our NULL default node to something
void SLNode::set_next_node(SLNode* next_node) {
    next_node_ = next_node;
}
// Accessor for Contents
int SLNode::contents() const {
    return contents_;
}
// Accessor for next object
SLNode* SLNode::next_node() const {
    return next_node_;
}