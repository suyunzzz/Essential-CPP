/*
 * @Author: your name
 * @Date: 2020-12-01 12:35:00
 * @LastEditTime: 2020-12-01 12:52:45
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \chapter4\Stack_ref.cpp
 */

#include "Stack_ref.h"

bool stack::pop(string& elem)
{
    if(empty())
    return false;
    elem = _stack.back();
    _stack.pop_back();
    return true;
}

bool stack::push(const string& elem)
{
    if(full()) return false;
    _stack.push_back(elem);
    return true;
}

bool stack::peek(string& elem)
{
    if(empty()) return false;
    elem = _stack.back();
    return true;
}


ostream& operator<<(ostream & os,const stack& s)
{
    os<<"---------"<<endl;
    for(auto iter =s._stack.begin();iter!=s._stack.end();iter++)
    {
        os<<*iter<<" ";
    }
    os<<endl;

    return os;
}

bool
stack::find(const string& elem) const
{
    for(auto iter =_stack.begin();iter!=_stack.end();iter++)
    {
        if(*iter==elem)
        {
            return true;
        }
    }
    return false;
}

int 
stack::count(const string& elem) const 
{
    int num=0;
    for(auto iter =_stack.begin();iter!=_stack.end();iter++)
    {
        if(elem==*iter)
        {
            num++;
        }
    }
    return num;
}