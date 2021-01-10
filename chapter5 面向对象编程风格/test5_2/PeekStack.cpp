/*
 * @Author: your name
 * @Date: 2020-12-19 23:28:43
 * @LastEditTime: 2020-12-19 23:51:23
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \chapter5\test5_2\PeekSatck.cpp
 */

#include"PeekStack.h"

PeekStack::PeekStack(int capacity = 0):Stack(capacity){
    cout<<"PeekStack::PeekStack(int)"<<endl;

    
}

bool 
PeekStack::peek(int index, elemType& elem) const
{
    if(index<0||index>=size()||empty())
        return false;
    
    elem = _stack[index];
    return true;

}