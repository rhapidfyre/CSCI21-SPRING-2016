#include "DLNode.h"

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
        void debugger();
        string getFront() const; // GetHead
        string getBack() const; // GetTail
        bool get(string target) const; // True if Exists
        string getStop(int iterations); // Return Name
        void popFront(); // Remove Head Node
        void popBack(); // Remove Tail Node
        bool removeFirst(string target); // Remove First Node Instance
        bool removeAll(string target); // Remove Last Node Instance
        void clear();
        friend ostream& operator<<(ostream& out, const DLList& src);
    private:
        int node_count;
        DLNode* head_node;
        DLNode* tail_node;
};
#endif