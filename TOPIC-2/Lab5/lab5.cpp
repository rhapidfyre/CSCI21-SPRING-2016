#include "lab5.h"

template <class Type> Type Box<Type>::contents(Type contents)
{
    contents_ = contents;
}
template <class Type> Type Box<Type>::getContents()
{
    return contents_;
}