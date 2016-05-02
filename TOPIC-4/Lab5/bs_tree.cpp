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
        if(node->left_child() != NULL)return Insert(newcontents, node->left_child());
        // Once it's NULL< we insert our new one.
        if(node->left_child() == NULL)
        {
            BSTNode* new_node = new BSTNode(newcontents);
            node->set_left_child(new_node);
            size_ ++;
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

bool BSTree::Remove(int item, BSTNode*& n) {
	// Find the item 
	bool found = false;
	BSTNode* predecessor = NULL;
	BSTNode* current = n;
	if(current==NULL) {
	    return false;
	}
	while(current!=NULL)
	{
		if(current->contents()==item)
		{
			found = true;
			break;
		}
		else
		{
			predecessor = current;
			if(item > (current->contents()))
				current=current->right_child();
			else
				current=current->left_child();
		}
	}
	if(!found)
	{
		return found;
	}
	// CASE 1: Removing a node with a single child
	if((current->left_child()==NULL && current->right_child() != NULL) || (current->left_child() != NULL && current->right_child()==NULL))
	{
		// Right Leaf Present, No Left Leaf
		if(current->left_child()==NULL && current->right_child() != NULL)
		{
			// If predecessor's left tree equals Node n
			if(predecessor->left_child()==current)
			{
				// then predecessor's left tree becomes n's right tree
				// and delete n
				predecessor->left_child()=current->right_child();
				delete current;
				current=NULL;
			}
			// If predecessor's right tree equals Node n
			else
			{
				// then predecessor's right tree becomes n's right tree
				// and delete n
				predecessor->right_child()=current->right_child();
				delete current;
				current=NULL;
			}
		}
		else // Left Leaf Present, No Right Leaf Present
		{
			if(predecessor->left_child()==current)
			{
				predecessor->left_child()=current->left_child();
				delete current;
				current=NULL;
			}
			else
			{
				predecessor->right_child()=current->left_child();
				delete current;
				current=NULL;
			}
		}
		return found;
	}
	// CASE 2: Removing a Leaf Node
	if(current->left_child()==NULL && current->right_child()==NULL)
	{
		if(predecessor->left_child()==current)
			predecessor->left_child()=NULL;
		else
			predecessor->right_child()=NULL;
		delete current;
		return found;
	}
	// CASE 3: Node has two children
	// Replace Node with smallest value in right subtree
	if(current->left_child() != NULL && current->right_child() != NULL)
	{
		BSTNode* check=current->right_child();
		if((current->left_child()==NULL)&&(current->right_child()==NULL))
		{
			current=check;
			delete check;
			current->set_right_child(NULL);
		}
		else // Right child has children
		{
			// If the node's right child has a left child
			// Move all the way down left to locate smallest element
			if((current->right_child())->left_child()!=NULL)
			{
				BSTNode* leftCurrent;
				BSTNode* leftCurrentPred;
				leftCurrentPred=current->right_child();
				leftCurrent=(current->right_child())->left_child();
				while(leftCurrent->left_child() != NULL)
				{
					leftCurrentPred=leftCurrent;
					leftCurrent=leftCurrent->left_child();
				}
				current->contents()=leftCurrent->contents();
				delete leftCurrent;
				leftCurrentPred->set_left_child(NULL);
			}
			else
			{
				BSTNode* temp=current->right_child();
				current->contents()=temp->contents();
				current->right_child()=temp->right_child();
				delete temp;
			}
		}
		return found;
	}
}

int BSTree::FindMin(BSTNode* hunter) const {
    if (hunter == NULL) {
        return 0;
    }
    if (hunter->left_child() != NULL) {
        return FindMin(hunter->left_child());
    }
    if (hunter->right_child() != NULL) {
        return FindMin(hunter->right_child());
    } else {
        return hunter->contents();
    }
}

/*

bool BSTree::Remove(int contents, BSTNode*& node) {
    
    BSTNode*& previous = NULL;
    BSTNode*& temp = node;
    
    if(node == NULL) {
        return false;
    }
    else if(contents < node->contents()) {
        return Remove(contents, node->left_child());
    }
    else if(contents > node->contents()) {
        return Remove(contents, node->right_child());
    } else {
        // Case 1 = No Branches, Single Node
        if(node->left_child() == NULL && node->right_child() == NULL) {
            delete node;
            size_--;
        }
        else if(node->left_child() != NULL) {
            node->set_contents(FindMin(node->left_child()));
        }
        else if (node->right_child() != NULL) {
            FindMin(node->right_child());
            node->set_contents(FindMin(node->right_child()));
        } else {
            delete node;
        }
        return true;
    }
}
*/