/*
 * @Author: your name
 * @Date: 2020-12-18 20:59:32
 * @LastEditTime: 2020-12-19 23:49:51
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \chapter5\test5_2\PeekStack.h
 */
#pragma once
#include "Stack.h"

class PeekStack : public Stack
{
public:

/*     构造方法用来初始化类的对象，与父类的其它成员不同，
    它不能被子类继承（子类可以继承父类所有的成员变量和成员方法，但不继承父类的构造方法）。
    因此，在创建子类对象时，为了初始化从父类继承来的数据成员，系统需要调用其父类的构造方法。 */

    PeekStack(int);         // 继承后要记得写构造函数
    virtual bool peek(int index, elemType&) const ;







};  // class PeekStack