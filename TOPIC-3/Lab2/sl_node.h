#include <cstddef>
using namespace std;

// Put up header guards
#ifndef SLNODE
#define SLNODE

class SLNode
{
    public:
        // Constructors/Destructor
        SLNode();
        SLNode(int contents);
        ~SLNode();
        // Mutators
        void set_contents(int contents);
        void set_next_node(SLNode* next_node);
        //Accessors
        int contents() const;
        SLNode* next_node() const;
    private:
        // Data type = Pointer to other object
        SLNode* next_node_;
        int contents_;
};

#endif