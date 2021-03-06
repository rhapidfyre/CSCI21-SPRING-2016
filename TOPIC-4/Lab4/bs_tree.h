#include "bst_node.h"

#ifndef NODE
#define NODE

class BSTree {
    public:
        BSTree();
        ~BSTree();
        bool Insert(int contents);
        void Clear();
        unsigned int size() const;
        string InOrder();
    private:
        bool Insert(int contents, BSTNode*& node);
        void Clear(BSTNode*& node);
        string InOrder(BSTNode*& node);
        BSTNode* root_;
        unsigned int size_;
};

#endif