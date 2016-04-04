/*
 *
 *
 *
 *
 */
 
// Includes
#include <cstdlib>
using namespace std;

// DLNode Class Declarations
class DLNode {
    public:
        DLNode();
        DLNode(int newContents);
        virtual ~DLNode();
        void setContents(int newContents);
        void setNext(DLNode* newNext);
        void setPrevious(DLNode* newPrevious);
        int getContents() const;
        DLNode* getNext() const;
        DLNode* getPrevious() const;
    private:
        int contents_;
        DLNode* previous_node_;
        DLNode* next_node_;
};

// DLList Class Declarations
class DLList {
    public:
        DLList();
        ~DLList();
        unsigned int getSize() const;
        void pushFront(int newContents);
        void pushBack(int newContents);
        void insert(int newContents);
        int getFront() const;
        int getBack() const;
        bool get(int target) const;
        void popFront();
        void popBack();
        bool removeFirst(int target);
        bool removeAll(int target);
        void clear();
        friend ostream& operator<<(ostream& out, const DLLList& src);
    private:
        int node_count_;
        DLList* head_node_;
        DLList* tail_node_;
};