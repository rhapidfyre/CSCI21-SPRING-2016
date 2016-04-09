#include "DLList.h"
#include "DLNode.h"

// DLNode Definitions
DLNode::DLNode() {
    contents = "None";
    previous_node = NULL;
    next_node = NULL;
}

DLNode::DLNode(string newContents) {
    contents = newContents;
}

DLNode::~DLNode() {
    // Do nothing
}

void DLNode::setContents(string newContents) {
    contents = newContents;
}

void DLNode::setNext(DLNode* newNext) {
    next_node = newNext;
}

void DLNode::setPrevious(DLNode* newPrevious) {
    previous_node = newPrevious;
}

string DLNode::getContents() const {
    return contents;
}

DLNode* DLNode::getNext() const {
    return next_node;
}

DLNode* DLNode::getPrevious() const {
    return previous_node;
}

// DLList Class Definitions
DLList::DLList() {
    node_count = 0;
    head_node = NULL;
    tail_node = NULL;
}

DLList::~DLList() {
    // Come back to this (CLEAR FUNCTION)
}

unsigned int DLList::getSize() const {
    return node_count;
}

void DLList::pushFront(string newContents) {
    // Create new DLNode with newContents and attach at the head
    string debug = newContents;
    DLNode *new_node = new DLNode(newContents);
    if(head_node != NULL) {
        new_node->setNext(head_node);
    }
    if(tail_node == NULL) {
        tail_node = new_node;
        }else{
        tail_node->setNext(new_node);  
        new_node->setPrevious(tail_node);  
    }
    head_node = new_node;
    node_count++;
}

void DLList::pushBack(string newContents) {
    // Create new DLNode with newContents and attach at the tail
    string debug = newContents;
    DLNode *new_node = new DLNode(newContents);
    new_node->setPrevious(tail_node);
    new_node->setNext(head_node);
    tail_node->setNext(new_node);
    tail_node = new_node;
    if(head_node == NULL) {
        head_node = new_node;
    }
    node_count++;
}

void DLList::insert(string newContents) {
    // Inserts New Node with newContents and attach in order
    string placeholder = newContents;
    char check_place = newContents[0];
    char check_head;
    char check_tail;
    if(head_node != NULL) {
        string head_contents = head_node->getContents();
        check_head = head_contents[0];
        string tail_contents = tail_node->getContents();
        check_tail = tail_contents[0];
    }
    
    if(head_node == NULL || ((check_place <= check_head) && (head_node != NULL))) {
        cout <<  "    Creating new head node:" << newContents << endl;
        pushFront(newContents);
    }
    else if(tail_node == NULL || ((check_place >= check_tail) && (tail_node != NULL))) {
        cout <<  "    Creating new tail node:" << newContents << endl;
        pushBack(newContents);
    }
    else
    {
        DLNode* temp = head_node;
        DLNode* previous = temp;
        
        while(temp->getContents() < newContents) {
            previous = temp;
            temp = temp->getNext();
        }
        
        DLNode* new_node = new DLNode(newContents);
        new_node->setNext(temp);
        previous->setNext(new_node);
        node_count = node_count + 1;
    }
}

void DLList::debugger() {
    DLNode* temp = head_node;
    for(int i=0;i<node_count;i++) {
        cout << "        Node #" << i << " returns as " << temp->getContents() << endl;
        temp = temp->getNext();
    }
}

string DLList::getFront() const {
    // Return content of head node
    string contentz;
    contentz = head_node->getContents();
    return contentz;
}

string DLList::getBack() const {
    // Return content of tail node
    string contentz;
    contentz = tail_node->getContents();
    return contentz;
}

bool DLList::get(string target) const {
    // Return true if target is in list, else return false
    return false;
}

string DLList::getStop(int iterator) {
    // getStop will loop through the linked list until ITERATIONS is met.
    // It will stop and return where it stopped and do nothing.
    
    // Create TEMP pointer at HEAD
    DLNode* temp = head_node;
    cout << "ITERATOR STARTING; Count = " << iterator << endl;
    for(int i=1;i<iterator;i++) {
        sleep(1);
        temp = temp->getNext();
    }
    cout << "Stopped on: " << temp->getContents() << endl;
    sleep(2);
    return temp->getContents();
}

void DLList::popFront() {
    // Remove current head node; do nothing if list is empty
    if (head_node != NULL){
        // Create Temp
        DLNode* temp;
        // Point Temp to Head
        temp = head_node;
        // Head to Next
        head_node = temp->getNext();
        // Tail to new Head
        tail_node->setNext(head_node);
        // Delete
        delete temp;
        // NULL
        temp = NULL;
        node_count--;
    }
}

void DLList::popBack() {
    // Remove current head node; do nothing if list is empty
    if (tail_node != NULL) {
        DLNode* temp = head_node;
        DLNode* previous = temp;
        while(temp->getNext() != tail_node) {
            previous = temp;
            temp = temp->getNext();
        }
        previous->setNext(head_node);
        head_node->setPrevious(previous);
        delete tail_node;
        tail_node = previous;
        temp = NULL;
        node_count--;
    }
}

bool DLList::removeFirst(string target) {
    if(head_node == NULL) {
        return false;
    }
    
    DLNode* temp = head_node;
    DLNode* previous = temp;
    if(head_node->getContents() == target) {
        cout << "Eliminated " << target << endl;
        popFront();
        return true;
    }
    if(tail_node->getContents() == target) {
        cout << "Eliminated " << target << endl;
        popBack();
        return true;
    }
    // There is no reason why this loop would be endless, so there won't be a catch.
    // The incoming TARGET string is only called when getStop finishes.
    while(temp->getContents() != target) {
        // Get next node and continue, and keep previous 1 behind.
        previous = temp;
        temp = temp->getNext();
    }
    
    if(temp->getContents() == target) {
        cout << "Eliminated " << target << endl;
        // Delete Node
        // Setting previous' node to the next node of temp
        previous->setNext(temp->getNext());
        // Setting temp's next node's PREVIOUS to temp's previous NODE
        temp->setPrevious(temp->getPrevious());
        delete temp;
        temp = NULL;
        node_count--;
        return true;
    } else {
        cout << "RemoveFirst returned false entirely (bad?)"<<endl;return false;}
}

bool DLList::removeAll(string target) {
    if(head_node == NULL) {
        return false;
    }
    
    DLNode* temp = head_node;
    DLNode* previous = temp;
    if(head_node->getContents() == target) {
        popFront();
        return true;
    }
    if(tail_node->getContents() == target) {
        popBack();
        return true;
    }
    // There is no reason why this loop would be endless, so there won't be a catch.
    // The incoming TARGET string is only called when getStop finishes.
    while(temp->getContents() != target) {
        // Get next node and continue, and keep previous 1 behind.
        previous = temp;
        temp = temp->getNext();
    }
    
    if(temp->getContents() == target) {
        // Delete Node
        // Setting previous' node to the next node of temp
        previous->setNext(temp->getNext());
        // Setting temp's next node's PREVIOUS to temp's previous NODE
        temp->setPrevious(temp->getPrevious());
        delete temp;
        temp = NULL;
        node_count--;
        return true;
    } else {
        cout << "RemoveFirst returned false entirely (bad?)"<<endl;return false;}
}

void DLList::clear() {
    // Clear ALL nodes, reset count to zero, set head and tail to NULL
    while(head_node != NULL) {
        DLNode* temp = head_node;
        head_node = temp->getNext();
        delete temp;
        temp = NULL;
        node_count--;
    }
    tail_node = NULL;
    head_node = NULL;
    if(node_count != 0) {
        cout << "LINK LIST CLEAR FUNCTION FAILED!!" << endl;
    }else{
    cout << "LINKED LIST CLEARED." << endl;}
}

ostream& operator<<(ostream& out, const DLList& src) {
/*
 *
 *  display the contents of each node in the list
 *  formatted per the program specification
 *  ("NUM1,NUM2,NUM3,...,NUMX")
 *  to the output stream out
 *
 */
}