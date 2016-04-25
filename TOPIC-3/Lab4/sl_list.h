#include <cstddef>
#include <sstream>
#include <iostream>
#include "sl_node.h"
using namespace std;

// Put up header guards
#ifndef SLLIST
#define SLLIST

class SLList
{
    public:
        SLList();
        ~SLList();
        void InsertHead(int contents);
        void InsertTail(int contents); // NEW
        void RemoveHead();
        void RemoveTail();
        void Clear();
        int GetHead() const; // NEW
        int GetTail() const; // NEW
        unsigned int size() const;
        string ToString() const;
    private:
        SLNode* head_;
        SLNode* tail_; // NEW
        unsigned int size_;
};

#endif