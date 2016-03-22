#include <iostream>
#include <iomanip>
using namespace std;

template <typename Type>
class Box
{
    public:
        Box();
        Box(Type contents){
            contents_ = contents;
            
        }
        void setContents(Type contents){
            contents_ = contents;
            
        }
        Type getContents(){
            return contents_;
            
        }
        friend ostream& operator <<(ostream &out, Box<Type> &contents){
            out << contents.getContents();
            return out;
        }
    private:
        Type contents_;
};

template <typename T>
T Sum(T values[], unsigned int size)
{
    T total = T();
    for(int i = 0;i < size;i++)
    {
        total = total + values[i];
    }
    return total;
};