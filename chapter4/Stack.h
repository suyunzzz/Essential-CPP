/*
 * @Author: your name
 * @Date: 2020-12-01 10:29:54
 * @LastEditTime: 2020-12-01 12:33:01
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \chapter4\Stack.h
 */
#pragma once
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

#include "headfile.h"       // 内置输出vector的运算符

using namespace std;

class Stack
{
public:
    Stack(vector<string>& vec );

    Stack(string* a ,string* b);
    
    // 放入
    bool push(const string & elem);

    // 提取
    bool pop( string & elem);      
    bool peek( string & elem);

    bool empty();
    bool full();

    int size(){
        return _stack.size();
    }

    friend ostream& operator<<(ostream & os,Stack& s);        

    bool
    myfind(string& elem);

    int
    mycount(string& elem);
    

    

private:
    vector<string> _stack;

}; // class Stack


