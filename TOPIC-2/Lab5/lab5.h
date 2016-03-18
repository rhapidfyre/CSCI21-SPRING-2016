#include <iostream>
#include <iomanip>
using namespace std;

class Box
{
    public:
        void setContents(int content);
        int getContents();
        friend Box operator <<(Type content);
    private:
        int contents_;
}