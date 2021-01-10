/*
 * @Author: your name
 * @Date: 2020-12-20 00:05:21
 * @LastEditTime: 2020-12-20 00:48:39
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \chapter5\test5_3\main.cpp
 */
#include "audio.h"
#include "Book.h"

int main(int argc, char const *argv[])
{
    
    // Book book1;
    // book1.

    Audio a1;
    a1.borrow();
    a1.sent();
    cout<<"\n---------------------\n";

    Book* bp=new Audio();
    bp->borrow();
    bp->sent();
    cout<<"\n---------------------\n";


    Library* bl=new Book();
    bl->borrow();
    bl->sent();
    cout<<"\n---------------------\n";


    bl = bp;
    bl->borrow();
    bl->sent();
    cout<<"\n---------------------\n";


    // Library l;       // 抽象类不能创建对象

    return 0;
}
