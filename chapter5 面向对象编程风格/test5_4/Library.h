/*
 * @Author: your name
 * @Date: 2020-12-19 23:55:02
 * @LastEditTime: 2020-12-20 00:47:29
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \chapter5\test5_3\Library.h
 */

#pragma once
#include <map>
#include <string>
#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>
using namespace std;


class Library 
{
public:

    virtual ~Library(){};        // 基类 的析构函数为虚函数

    virtual bool borrow() const = 0;        // 纯虚函数，抽象类

    virtual bool sent() const = 0; //   纯虚函数
}; // class Library


