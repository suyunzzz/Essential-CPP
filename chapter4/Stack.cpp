/*
 * @Author: your name
 * @Date: 2020-12-01 10:30:02
 * @LastEditTime: 2020-12-01 12:30:18
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \chapter4\Stack.cpp
 */
#include "Stack.h"

Stack::Stack(vector<string>& vstring){
    _stack = vstring;
    
}

Stack::Stack(string* a,string* b){
    vector<string> tmp(a,b);
    _stack=tmp;
    
}

bool
Stack::push(const std::string & elem){
    if(full())
    {
        cout<<"Error"<<endl;
        return false;
    }
    _stack.push_back(elem);
    return true;

}

bool
Stack::pop(string & elem)
{
    if(empty())
    {
        cout<<"Error"<<endl;
        return false;
    }

    elem = _stack.back();
    _stack.pop_back();
    return true;
}

bool
Stack::peek(string & elem)
{
    if(empty())
    {
        cout<<"Error"<<endl;
        return false;
    }

    elem = _stack.back();
    return true;
}

inline bool 
Stack::empty()
{
    return _stack.empty();
}

inline bool
Stack::full()
{
    return _stack.size() == _stack.max_size();
}


ostream & operator<<(ostream & os,Stack& s)
{
    os<<"---------"<<endl;
    os<<s.size()<<endl;
    os<<s._stack<<endl;
    return os;
}

bool 
Stack::myfind(string & elem)
{
    vector<string>::iterator start=_stack.begin();
    auto iter=find(start,_stack.end(),elem);
    if(iter!=_stack.end())
    {
        cout<<"Found "<<elem<<endl;
        return true;
    }
    return false;
}

int 
Stack::mycount(string & elem)
{
    int count=0;
    auto iter=_stack.begin();
    while((iter=find(iter,_stack.end(),elem))!=_stack.end())
    {
        count++;
        iter++;
    }
    return count;
}
