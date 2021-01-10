/*
 * @Author: your name
 * @Date: 2020-12-01 12:34:48
 * @LastEditTime: 2020-12-01 13:07:53
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \chapter4\Stack_ref.h
 */

#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iterator>
using namespace std;

class stack{
public:
    bool push(const string& elem);
    bool pop(string & elem);

    bool peek(string & elem);
    bool empty() const {return _stack.empty();}

    bool full() const {return _stack.max_size()==_stack.size();}
    int size() const {return _stack.size();}

    friend ostream& operator<<(ostream & os,const stack& s);

    bool find(const string& elem) const;

    int count(const string& elem) const;
private:
    vector<string> _stack;

}; // class stack