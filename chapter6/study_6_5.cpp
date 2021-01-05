/*
 * @Author: your name
 * @Date: 2021-01-05 15:05:39
 * @LastEditTime: 2021-01-05 15:20:51
 * @LastEditors: Please set LastEditors
 * @Description: 测试类的private调用
 * @FilePath: \chapter6\study__6_5.cpp
 */

/* 
在类的外部调用类的private：
    法1：声明为friend
    法2：通过调用public函数调用private
 */


#include <iostream>
class A
{
    // 法1 通过声明友元函数
    friend void print(const A& a);

public:
    void func1() const
    {
        printf("func1\n");
        // func2();                // 法2：通过public函数调用private函数
    }

private:
    void func2() const
    {
        printf("func2\n");
    }

};  // class A

// 友元函数在使用之前需要在类的外部进行声明（不是类内部声明为友元的那一次）
void print(const A& a);

void print(const A& a)  // const 对象只能访问const成员函数
{
    a.func1();
    a.func2();      // 调用类内部的private
}

int main(int argc, char const *argv[])
{
    A a;
    // a.func1();
    // a.func2();

    print(a);
    
    
    return 0;
}

