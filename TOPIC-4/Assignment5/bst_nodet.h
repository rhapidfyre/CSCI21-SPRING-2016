#include <iostream>
#include <cstdlib>
#include <sstream>
#include <string>
#include <fstream>
#include <istream>
using namespace std;

#ifndef BST
#define BST

template <class ND>
class BSTNodeT {
    public:
    //    BSTNodeT();
        BSTNodeT(ND value = ND());
        ~BSTNodeT();
        void SetContents(ND contents);
        void SetLeft(BSTNodeT<ND>* Node);
        void SetRight(BSTNodeT<ND>* Node);
        ND GetContents() const;
        ND& GetContents();
        BSTNodeT<ND>* GetLeft() const;
        BSTNodeT<ND>* GetRight() const;
        BSTNodeT<ND>*& GetLeft();
        BSTNodeT<ND>*& GetRight();
    private:
        BSTNodeT<ND>* left_child_;
        BSTNodeT<ND>* right_child_;
        ND contents_;
};
/*
template <class ND>
BSTNodeT<ND>::BSTNodeT() {
    left_child_ = NULL;
    right_child_ = NULL;
    Simple(const T &value = T()); 
}*/

template <class ND>
BSTNodeT<ND>::BSTNodeT(ND value) {
    left_child_ = NULL;
    right_child_ = NULL;
    contents_ = value;
}

template <class ND>
BSTNodeT<ND>::~BSTNodeT() {
    left_child_ = NULL;
    right_child_ = NULL;
}

template <class ND>
void BSTNodeT<ND>::SetContents(ND contents) {
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

#endif