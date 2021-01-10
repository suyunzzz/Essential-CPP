/*
 * @Author: your name
 * @Date: 2020-12-19 23:58:48
 * @LastEditTime: 2020-12-20 00:41:25
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \chapter5\test5_3\Book.h
 */
#pragma once

#include "Library.h"

class Book: public Library
{
public:
    virtual ~Book(){};

    virtual bool borrow() const{
        cout<<"Book borrow"<<endl;
        return true;
    }

    virtual bool sent() const
    {
        cout<<"Book sent"<<endl;
        return true;
    }

}; // class Book