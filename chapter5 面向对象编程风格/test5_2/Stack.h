/*
 * @Author: your name
 * @Date: 2020-12-18 20:59:07
 * @LastEditTime: 2020-12-19 00:20:27
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \chapter5\test5_2\Stack.h
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
    Stack(int);
    virtual ~Stack(){};
     bool pop(elemType&);
     bool push(elemType&) ;
     int size() const ;

     bool empty() const;
     bool full() const ;
    virtual bool peek(int index, elemType&) const ;
     ostream& print(ostream& os=cout) const ;

protected:
    vector<elemType> _stack;
    int _top;


};  // class Stack

inline ostream& operator<<(ostream& os, const Stack& s)
{   
    os<<"\n------cout------\n"<<endl;
    return(s.print(os));
}
