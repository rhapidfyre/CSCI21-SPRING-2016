#include <cstddef>
using namespace std;

#ifndef SLNODE
#define SLNODE

class SLNode
{
    public:
        SLNode();
        SLNode(int contents);
        ~SLNode();
        void set_contents(int contents);
        void set_next_node(SLNode* next_node);
        int contents() const;
        SLNode* next_node() const;
    private:
        SLNode* next_node_;
        int contents_;
};

#endif