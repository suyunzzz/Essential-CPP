/*
 * @Author: your name
 * @Date: 2020-12-18 19:51:03
 * @LastEditTime: 2020-12-18 20:35:26
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \chapter5\test5_1\Peekback.h
 */
#pragma once

#include "stack.h"

class Peekback_Stack:public Stack{
public:

    Peekback_Stack(int capacity=0):_top(0){
        if(capacity) _stack.reserve(capacity);
    }

    virtual int size() const { return _stack.size(); }

    virtual bool empty() const {return _stack.empty();}

    virtual bool full() const {return size()>=_stack.max_size();}

    virtual bool pop(elemType& elem)
    {
        if(empty()) return false;
        elem=_stack[_top--];
        _stack.pop_back();
        return true;
    }

    virtual bool push(elemType& elem)
    {
        if(full()) return false;

        // _stack[size()-1]=elem;
        _stack.push_back(elem);
        ++_top;
        return true;
    }

    virtual ostream& print( ostream &os = cout ) const{ 

        cout<<"\n--Peekback_Stack::print()--\n";
        for (auto& elem : _stack)
        {
            cout<<" "<<elem;
        }
        cout<<endl;


        return os;
    }

    virtual bool peek(int index,elemType& elem) const
    { 
        if(empty()) return false;

        if(index>=size()||index<0)
        {
            return false;
        }

        elem = _stack[index];

        return true;

    
    
    }


protected:
    vector<elemType> _stack;
    int _top;

};  // class Peekback_Stack