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
        void InsertHead(int contents);
        void RemoveHead();
        void Clear();
        unsigned int size() const;
        string ToString() const;
    private:
        SLNode* head_;
        unsigned int size_;
};

#endif