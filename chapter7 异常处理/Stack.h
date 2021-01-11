/*
 * @Author: your name
 * @Date: 2021-01-11 10:49:31
 * @LastEditTime: 2021-01-11 14:31:29
 * @LastEditors: Please set LastEditors
 * @Description: 取自第五章的练习题5.2
 * @FilePath: \chapter7 异常处理\Stack.h
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
    virtual ~Stack(){};			// Stack要做基类，因此需要将析构函数设置为虚函数
     bool pop(elemType&);
     bool push(elemType&) ;
     int size() const ;

     bool empty() const;
     bool full() const ;
    virtual bool peek(int index, elemType&) const ;
     ostream& print(ostream& os=cout) const ;

    int maxsize() const;

protected:
    vector<elemType> _stack;
    int _top;


};  // class Stack

ostream& operator<<(ostream& os, const Stack& s);

