/*
 * @Author: your name
 * @Date: 2020-12-15 22:41:42
 * @LastEditTime: 2020-12-18 22:34:11
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \chapter5\test5_1\stack.h
 */

#pragma once
#include <map>
#include <string>
#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>

using namespace std;
typedef string elemType;

class Stack{


public:
    virtual ~Stack(){};
    virtual bool pop(elemType&) = 0;
    virtual bool push(elemType&) = 0;
    virtual int size() const = 0;

    virtual bool empty() const = 0;
    virtual bool full() const = 0;
    virtual bool peek(int index, elemType&) const = 0;
    virtual ostream& print(ostream& os=cout) const = 0;


};  // class Stack

ostream& operator<<(ostream& os, const Stack& s)
{   
    os<<"\n------cout------\n"<<endl;
    return(s.print(os));
}


class LIFO_Stack:public Stack
{
public:
    LIFO_Stack(int capacity=0):_top(0){
        if (capacity) _stack.resize(capacity);
    }

    int size() const { return _stack.size(); }

    bool empty() const { return _stack.empty(); }
    bool full() const { return size()>=_stack.max_size(); }

    bool peek(int index,elemType& elem) const {
        return false;
    }

    ostream& print(ostream& os) const {     // 默认参数只能出现一次
        cout<<"--LIFO_Stack::print()--";
        
        for(auto iter=_stack.begin();iter!=_stack.end();iter++)
        {
            os<<*iter<<" ";
        }
        cout<<endl;
        return os;
    }
    


    bool pop(elemType& elem){
        if(empty()) return false;
        elem = _stack[_top--];
        _stack.pop_back();
        return true;
    }


    bool push(elemType& elem){
        if(full()) return false;
        _stack.push_back(elem);
        ++_top;
        return true;

        
    }



protected:

    vector<elemType> _stack;
    int _top;

};
