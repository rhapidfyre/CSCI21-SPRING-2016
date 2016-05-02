#include <iostream>
#include <cstdlib>
#include <sstream>
#include <string>
using namespace std;

#ifndef BST
#define BST

class BSTNode {
    public:
        BSTNode();
        BSTNode(int contents);
        ~BSTNode();
        void set_contents(int contents);
        void set_left_child(BSTNode* Node);
        void set_right_child(BSTNode* Node);
        int contents() const;
        int& contents();
        BSTNode* left_child() const;
        BSTNode* right_child() const;
        BSTNode*& left_child();
        BSTNode*& right_child();
    private:
        BSTNode* left_child_;
        BSTNode* right_child_;
        int contents_;
};

#endif