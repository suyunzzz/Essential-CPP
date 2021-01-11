/*
 * @Author: your name
 * @Date: 2021-01-11 10:49:22
 * @LastEditTime: 2021-01-11 14:52:56
 * @LastEditors: Please set LastEditors
 * @Description: 取自第五章的练习题5.2
 * @FilePath: \chapter7 异常处理\Stack.cpp
 */

#include"Stack.h"
#include "ExceptionClass.hpp"

Stack::Stack(int capacity = 0):_top(0)
{   
    cout<<"[Consturctor] Stack::Stack(int)"<<endl;
    if(capacity)
    {
        _stack.reserve(capacity);
        // _stack.resize(capacity);
    }
}

bool
Stack::full() const
{
    if(_stack.size()>=_stack.capacity())
        return true;
    return false;

}


bool 
Stack::empty() const
{
    if(_stack.empty()) return true;
    return false;
}

bool
Stack::pop(elemType& elem)
{
    if(empty()) 
    throw PopOnEmpty();         // 丢出一个异常


    elem = _stack[_top--];
    _stack.pop_back();
    return true;
}

bool 
Stack::push(elemType& elem)
{   
    if(full()) throw PushOnFull();          // 丢出一个异常
    _stack.push_back(elem);     
    _top++;
    return true;

}

int 
Stack::size() const
{ return _stack.size(); }


ostream& 
Stack::print(ostream& os) const
{
    for (auto& elem : _stack)
    {
        os<<" "<<elem;
    }

    os<<endl;
    return os;
}

bool
Stack::peek( int index,elemType& elem ) const
{ return false;}


int
Stack::maxsize() const
{ return _stack.capacity(); }

ostream& operator<<(ostream& os, const Stack& s)
{   
    os<<"------cout------\n";
    return(s.print(os));
}
