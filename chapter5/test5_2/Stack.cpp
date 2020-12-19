/*
 * @Author: your name
 * @Date: 2020-12-18 20:59:15
 * @LastEditTime: 2020-12-19 23:50:31
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \chapter5\test5_2\Stack.cpp
 */
#include"Stack.h"

Stack::Stack(int capacity = 0):_top(0)
{   
    cout<<"Stack::Stack(int)"<<endl;
    if(capacity)
    {
        _stack.reserve(capacity);
    }
}

bool
Stack::full() const
{
    if(_stack.size()>=_stack.max_size())
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
    if(empty()) return false;
    elem = _stack[_top--];
    _stack.pop_back();
    return true;
}

bool 
Stack::push(elemType& elem)
{   
    if(full()) return false;
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


