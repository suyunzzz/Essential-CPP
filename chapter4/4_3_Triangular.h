/*
 * @Author: your name
 * @Date: 2020-12-02 14:14:24
 * @LastEditTime: 2020-12-07 17:06:03
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \chapter4\4_3_Triangular.h
 */

#pragma once
#include <iostream>
#include <vector>
#include <string>
// #include <iterator>
#include <algorithm>

#include "Stack.h"

#include "4_3_Triangular_iterator.h"

using namespace std;



class Triangular{
    // 默认的访问属性为private，保证了数据的安全性
    friend class Triangular_iterator;       // friend class 

public:
    Triangular(int len=1,int beg_pos = 1);
    Triangular(const Triangular &);
    Triangular& operator=(const Triangular&);

    int length()  const { return _length;  }
    int beg_pos() const { return _beg_pos; }
    int elem(int pos) const;

    void length(int nlen){_length = nlen;}
    void beg_pos(int npos){_beg_pos = npos;}

    

    bool next(int& value) const;
    void next_rest() const {_next =1;}

    static bool is_elem(  int);
    static void gen_elements(int length);
    static void gen_elems_to_value(int value);
    static void display(int length,int beg_pos,ostream& os =cout) ;        // 默认参数只能存在一处
    typedef  Triangular_iterator iterator;      // 


    iterator begin() const      // 返会的是临时变量，因此不加引用
    {
        return iterator(_beg_pos);
    }

    Triangular_iterator end() const { return Triangular_iterator(_beg_pos+_length);}
    

private:
    int _length;
    int _beg_pos;
    mutable int _next;

    static vector<int > _elems;     // static成员
    enum {_max_elems = 1024};
}; // class Triangular


