#include "bst_node.h"

BSTNode::BSTNode() {
    left_child_ = NULL;
    right_child_ = NULL;
    contents_ = 0;
}

BSTNode::BSTNode(int contents) {
    left_child_ = NULL;
    right_child_ = NULL;
    contents_ = contents;
}

BSTNode::~BSTNode() {
    left_child_ = NULL;
    right_child_ = NULL;
}

void BSTNode::set_contents(int contents) {
    contents_ = contents;
}

void BSTNode::set_left_child(BSTNode* Node) {
    left_child_ = Node;
}

void BSTNode::set_right_child(BSTNode* Node) {
    right_child_ = Node;
}

int BSTNode::contents() const {
    return contents_;
}

int& BSTNode::contents() {
    return contents_;
}

BSTNode* BSTNode::left_child() const {
    return left_child_;
}
BSTNode*& BSTNode::left_child() {
    return left_child_;
}

BSTNode* BSTNode::right_child() const {
    return right_child_;
}

BSTNode*& BSTNode::right_child() {
    return right_child_;
}