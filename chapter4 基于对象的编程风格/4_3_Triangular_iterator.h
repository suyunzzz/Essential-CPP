/*
 * @Author: your name
 * @Date: 2020-12-07 10:19:01
 * @LastEditTime: 2020-12-07 19:02:08
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \chapter4\4_3_Triangular_iterator.h
 */

#pragma once
#include<iostream>
#include<vector>
#include<string>
// #include<iterator>
#include<algorithm>

using namespace std;

class Triangular;               // 声明

class iterator_overflow{};

class Triangular_iterator{
public:
    Triangular_iterator(int index):_index(index-1){

    }

    bool operator ==( const Triangular_iterator&) const;

    bool operator !=( const Triangular_iterator&) const;
    int operator*() const;
    Triangular_iterator& operator++();          // 前自增
    Triangular_iterator operator++(int) ;       // 后自增

private:
    void check_integrity() const;
    int _index;
};  //class Trianguar_iterator


