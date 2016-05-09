/*  Michael Harris
    CSCI 21 04/27/2016
    Topic 4, Lab 4
    Recursion Trees
*/
#include "bs_tree.h"

template <class TR>
BSTreeT<TR>::BSTreeT() {
    root_ = NULL;
    size_ = 0;
}

template <class TR>
BSTreeT<TR>::~BSTreeT() {
    Clear();
}

template <class TR>
bool BSTreeT<TR>::Insert(TR newcontents) {
    return Insert(newcontents, root_);
}

template <class TR>
void BSTreeT<TR>::Clear() {
    Clear(root_);
}

template <class TR>
unsigned int BSTreeT<TR>::GetSize() const {
    return size_;
}

template <class TR>
string BSTreeT<TR>::ToStringForwards() {
    return ToStringForwards(root_);
}

template <class TR>
string BSTreeT<TR>::ToStringBackwards() {
    return ToStringBackwards(root_);
}

template <class TR>
bool BSTreeT<TR>::Insert(TR newcontents, BSTNodeT<TR>*& node)
{
    /* I could not figure out for the life of me what the heck I was
    doing wrong, so I referenced Russel's code. I still don't know
    what I did wrong after referencing our codes together, so I ended up
    following what he did and it ran fine. Still don't know to this day
    what I was doing wrong but it works now...
    */
    
    // If our incoming node is NULL, we need a new one.
    if(node == NULL) {
        BSTNodeT<TR>* new_node = new BSTNodeT<TR>(newcontents);
        node = new_node;
        size_ ++;
        // Return true as per directions
        return true;
    }
    
    // If the incoming node is equal to the current node
    if(node->contents() == newcontents) {return false;}
    
    else if(newcontents < node->contents()) {
        // If the left child is not NULL, we need to dig in until it is.
        if(node->GetLeft() != NULL) {
            return Insert(newcontents, node->GetLeft());
        }
        // Once it's NULL< we insert our new one.
        if(node->GetLeft() == NULL)
        {
            BSTNodeT<TR>* new_node = new BSTNodeT<TR>(newcontents);
            node->SetLeft(new_node);
            size_++;
            return true;
        }
    }
    else if(newcontents > node->contents()) {
        if(node->GetRight() != NULL) {
            return Insert(newcontents, node->GetRight());
        }
        if(node->GetRight() == NULL) {
            BSTNodeT<TR>* new_node = new BSTNodeT<TR>(newcontents);
            node->SetRight(new_node);
            size_++;
            return true;
        }
    }
    // This is the catch-all, but it handles if incoming contents is greater
    else
    {
        if(node->GetRight() == NULL) {
            BSTNodeT<TR>* new_node = new BSTNodeT<TR>(newcontents);
            node->SetRight(new_node);
            size_ ++;
            return true;
        }else{
            // If the right is not NULL it will dig until it is NULL and Insert.
            return Insert(newcontents, node->GetRight());
        }
    }
}

template <class TR>
void BSTreeT<TR>::Clear(BSTNodeT<TR>*& node)
{
    // If the root is NULL, there's nothing to clear.
    if (root_ != NULL)
    {    
        // Dig in and clear the last one starting with the lowest number
        if(node->GetLeft() != NULL) return Clear(node->GetLeft());
        if(node->GetRight() != NULL) return Clear(node->GetRight());
        delete node;
        node = NULL;
        
        size_--;
        return Clear(root_);
    }
    
} 

template <class TR>
string BSTreeT<TR>::ToStringForwards(BSTNodeT<TR>*& node) {
    stringstream ss;
    if (node != NULL) {
        if(node->GetLeft() != NULL) {
            ss << ToStringForwards(node->GetLeft());
        }
        
        ss << node->contents() << " ";
        
        if(node->GetRight() != NULL) {
            ss << ToStringForwards(node->GetRight());
        }
        return ss.str();
    } else {
        return "";
        
    }
}

template <class TR>
string BSTreeT<TR>::ToStringBackwards(BSTNodeT<TR>*& node) {
    
}

template <class TR>
bool BSTreeT<TR>::Remove(TR contents) {
    return Remove(contents, root_);
}

template <class TR>
TR BSTreeT<TR>::FindMin() {
    if (root_ == NULL){
        return 0;
    } else {
        return FindMin(root_);
    }
}

template <class TR>
bool Exists(TR query) {
    
}

template <class TR>
bool BSTreeT<TR>::Remove(TR contents, BSTNodeT<TR>*& node) {
    if(node == NULL) {
        return false;
    }
    else if(contents < node->contents()) {
        Remove(contents, node->GetLeft());
    }
    else if(contents > node->contents()) {
        Remove(contents, node->GetRight());
    } else {
        if(node->GetLeft() == NULL && node->GetRight() == NULL) {
            delete node;
            node = NULL;
            size_--;
            return true;
        }
        else if((node->GetLeft() != NULL && node->GetRight() != NULL) || (node->GetLeft() == NULL && node->GetRight() != NULL)) {
            TR keep = FindMin(node->GetRight());
            node->set_contents(keep);
            return Remove(keep, node->GetRight());
        }
        else if(node->GetLeft() != NULL && node->GetRight() == NULL) {
            BSTNodeT<TR>* temp = node;
            node = node->GetLeft();
            delete temp;
            temp = NULL;
            size_--;
            return true;
        } else {
            TR keep = FindMin(node->GetLeft());
            node->set_contents(keep);
            return Remove(keep, node->GetLeft());
        }
    }
}

template <class TR>
TR BSTreeT<TR>::FindMin(BSTNodeT<TR>* hunter) const {
    if(hunter->GetLeft() != NULL) {return FindMin(hunter->GetLeft());}
    else {
        return hunter->contents();
    }
    
}