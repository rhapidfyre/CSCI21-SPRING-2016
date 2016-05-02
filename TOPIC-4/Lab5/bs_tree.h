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
        bool Remove(int contents);
        int FindMin();
    private:
        bool Insert(int contents, BSTNode*& node);
        void Clear(BSTNode*& node);
        string InOrder(BSTNode*& node);
        bool Remove(int contents, BSTNode*& node);
        int FindMin(BSTNode* node) const;
        BSTNode* root_;
        unsigned int size_;
};

#endif