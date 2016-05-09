#include "bst_node.h"

template <class ND>
BSTNodeT<ND>::BSTNodeT() {
    left_child_ = NULL;
    right_child_ = NULL;
    contents_ = 0;
}

template <class ND>
BSTNodeT<ND>::BSTNodeT(ND contents) {
    left_child_ = NULL;
    right_child_ = NULL;
    contents_ = contents;
}

template <class ND>
BSTNodeT<ND>::~BSTNodeT() {
    left_child_ = NULL;
    right_child_ = NULL;
}

template <class ND>
void BSTNodeT<ND>::set_contents(ND contents) {
    contents_ = contents;
}

template <class ND>
void BSTNodeT<ND>::SetLeft(BSTNodeT<ND>* Node) {
    left_child_ = Node;
}

template <class ND>
void BSTNodeT<ND>::SetRight(BSTNodeT<ND>* Node) {
    right_child_ = Node;
}

template <class ND>
ND BSTNodeT<ND>::GetContents() const {
    return contents_;
}

template <class ND>
ND& BSTNodeT<ND>::GetContents() {
    return contents_;
}

template <class ND>
BSTNodeT<ND>* BSTNodeT<ND>::GetLeft() const {
    return left_child_;
}

template <class ND>
BSTNodeT<ND>*& BSTNodeT<ND>::GetLeft() {
    return left_child_;
}

template <class ND>
BSTNodeT<ND>* BSTNodeT<ND>::GetRight() const {
    return right_child_;
}

template <class ND>
BSTNodeT<ND>*& BSTNodeT<ND>::GetRight() {
    return right_child_;
}