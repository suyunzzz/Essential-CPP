/*
 * @Author: your name
 * @Date: 2020-12-15 23:09:54
 * @LastEditTime: 2020-12-18 20:39:34
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \chapter5\test5_1\main.cpp
 */
#include"stack.h"
#include "Peekback.h"


int main(int argc, char const *argv[])
{
    LIFO_Stack lifo(5);
    cout<<"lifo.size(): "<<lifo.size()<<endl;


    Peekback_Stack PS(2);
    string a("hello");
    PS.push(a);
    PS.push(*(new string("world")));
    PS.push(*(new string("Suyunzzz")));

    PS.push(*(new string("jjj")));

    cout<<PS<<endl;

    return 0;
}
