/*  Michael Harris
    CSCI 21 04/27/2016
    Topic 4, Lab 4
    Recursion Trees
*/
#include "bs_tree.h"

BSTree::BSTree() {
    root_ = NULL;
    size_ = 0;
}

BSTree::~BSTree() {
    Clear();
}

bool BSTree::Insert(int newcontents) {
    return Insert(newcontents, root_);
}

void BSTree::Clear() {
    Clear(root_);
}

unsigned int BSTree::size() const {
    return size_;
}

string BSTree::InOrder() {
    return InOrder(root_);
}

bool BSTree::Insert(int newcontents, BSTNode*& node)
{
    /* I could not figure out for the life of me what the heck I was
    doing wrong, so I referenced Russel's code. I still don't know
    what I did wrong after referencing our codes together, so I ended up
    following what he did and it ran fine. Still don't know to this day
    what I was doing wrong but it works now...
    */
    
    // If our incoming node is NULL, we need a new one.
    if(node == NULL) {
        BSTNode* new_node = new BSTNode(newcontents);
        node = new_node;
        size_ ++;
        // Return true as per directions
        return true;
    }
    
    // If the incoming node is equal to the current node
    if(node->contents() == newcontents) {return false;}
    
    else if(newcontents < node->contents()) {
        // If the left child is not NULL, we need to dig in until it is.
        if(node->left_child() != NULL) {
            return Insert(newcontents, node->left_child());
        }
        // Once it's NULL< we insert our new one.
        if(node->left_child() == NULL)
        {
            BSTNode* new_node = new BSTNode(newcontents);
            node->set_left_child(new_node);
            size_++;
            return true;
        }
    }
    else if(newcontents > node->contents()) {
        if(node->right_child() != NULL) {
            return Insert(newcontents, node->right_child());
        }
        if(node->right_child() == NULL) {
            BSTNode* new_node = new BSTNode(newcontents);
            node->set_right_child(new_node);
            size_++;
            return true;
        }
    }
    // This is the catch-all, but it handles if incoming contents is greater
    else
    {
        if(node->right_child() == NULL) {
            BSTNode* new_node = new BSTNode(newcontents);
            node->set_right_child(new_node);
            size_ ++;
            return true;
        }else{
            // If the right is not NULL it will dig until it is NULL and Insert.
            return Insert(newcontents, node->right_child());
        }
    }
}

void BSTree::Clear(BSTNode*& node)
{
    // If the root is NULL, there's nothing to clear.
    if (root_ != NULL)
    {    
        // Dig in and clear the last one starting with the lowest number
        if(node->left_child() != NULL) return Clear(node->left_child());
        if(node->right_child() != NULL) return Clear(node->right_child());
        delete node;
        node = NULL;
        
        size_--;
        return Clear(root_);
    }
    
} 
string BSTree::InOrder(BSTNode*& node)
{
    stringstream ss;
    if (node != NULL) {
        if(node->left_child() != NULL) {
            ss << InOrder(node->left_child());
        }
        
        ss << node->contents() << " ";
        
        if(node->right_child() != NULL) {
            ss << InOrder(node->right_child());
        }
        return ss.str();
    } else {
        return "";
        
    }
}

bool BSTree::Remove(int contents) {
    return Remove(contents, root_);
}

int BSTree::FindMin() {
    if (root_ == NULL){
        return 0;
    } else {
        return FindMin(root_);
    }
}

bool BSTree::Remove(int contents, BSTNode*& node) {
    if(node == NULL) {
        return false;
    }
    else if(contents < node->contents()) {
        Remove(contents, node->left_child());
    }
    else if(contents > node->contents()) {
        Remove(contents, node->right_child());
    } else {
        if(node->left_child() == NULL && node->right_child() == NULL) {
            delete node;
            node = NULL;
            size_--;
            return true;
        }
        else if((node->left_child() != NULL && node->right_child() != NULL) || (node->left_child() == NULL && node->right_child() != NULL)) {
            int keep = FindMin(node->right_child());
            node->set_contents(keep);
            return Remove(keep, node->right_child());
        }
        else if(node->left_child() != NULL && node->right_child() == NULL) {
            BSTNode * temp = node;
            node = node->left_child();
            delete temp;
            temp = NULL;
            size_--;
            return true;
        } else {
            int keep = FindMin(node->left_child());
            node->set_contents(keep);
            return Remove(keep, node->left_child());
        }
    }
}

int BSTree::FindMin(BSTNode* hunter) const {
    if(hunter->left_child() != NULL) {return FindMin(hunter->left_child());}
    else {
        return hunter->contents();
    }
    
}