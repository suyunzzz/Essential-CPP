/*
 * @Author: your name
 * @Date: 2020-12-20 00:02:48
 * @LastEditTime: 2020-12-20 00:42:06
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \chapter5\test5_3\audio.h
 */
#pragma once
#include "Book.h"


class Audio: public Book
{
public:
    // Audio(){};
    virtual bool borrow() const override {
        cout<<"Audio borrow"<<endl;
        return true;
    }

    virtual bool sent() const override {
        cout<<"Audio sent"<<endl;
        return true;
    }


};      // class Audio