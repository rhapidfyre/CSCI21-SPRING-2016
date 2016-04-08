/*
 *
 *      Michael Harris
 *      Assignment 4
 *      April 7th 2016
 */
 
// Includes
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <time>
using namespace std;

// Header Guards
#ifndef DLNODE
#define DLNODE
// DLNode Class Declarations
class DLNode {
    public:
        DLNode();
        DLNode(string newContents);
        virtual ~DLNode();
        void setContents(string newContents);
        void setNext(DLNode* newNext);
        void setPrevious(DLNode* newPrevious);
        string getContents() const;
        DLNode* getNext() const;
        DLNode* getPrevious() const;
    private:
        string contents;
        DLNode* previous_node;
        DLNode* next_node;
};

#endif
#ifndef DLLIST
#define DLLIST
// DLList Class Declarations
class DLList {
    public:
        DLList();
        ~DLList();
        unsigned int getSize() const;
        void pushFront(string newContents); // New Node to Front
        void pushBack(string newContents); // New Node to Back
        void insert(string newContents); // New Node in Order
        string getFront() const; // GetHead
        string getBack() const; // GetTail
        bool get(string target) const; // True if Exists
        string getStop(int number); // Return Name
        void popFront(); // Remove Head Node
        void popBack(); // Remove Tail Node
        bool removeFirst(string target); // Remove First Node Instance
        bool removeAll(string target); // Remove Last Node Instance
        void clear();
        friend ostream& operator<<(ostream& out, const DLList& src);
    private:
        int node_count;
        DLList* head_node;
        DLList* tail_node;
};
#endif