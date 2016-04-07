#include <cstddef>
#include <sstream>
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
        void Clear();
        void Insert(int content); // NEW
        bool RemoveFirstOccurence(int content); // NEW
        int GetHead() const;
        int GetTail() const;
        unsigned int size() const;
        string ToString() const;
    private:
        void InsertHead(int contents); // NEW
        void InsertTail(int contents); // NEW
        void RemoveHead(); // NEW
        void RemoveTail(); // NEW
        SLNode* head_;
        SLNode* tail_; // NEW
        unsigned int size_;
};

#endif