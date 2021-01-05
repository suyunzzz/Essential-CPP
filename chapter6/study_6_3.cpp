/*
 * @Author: your name
 * @Date: 2021-01-05 10:39:00
 * @LastEditTime: 2021-01-05 11:28:29
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \chapter6\study_6_3.cpp
 */
#include <iostream>
using namespace std;

class BaseA
{

public:
    

    BaseA()
    {
        printf("constructor of BaseA\n");
    }

    BaseA(const BaseA & other)
    {
        printf("copy constructor of BaseA\n");
    }

    ~BaseA() {
        printf("destructor of BaseA\n");
    }
 
    void
    operator=(const BaseA& a)
    {
        // *this = a;
        printf("copy assignment of BaseA\n");

        // return *this;
    }

    

};  // class BaseA

class BaseB
{
public:

    BaseB(){
        printf("defalut constructor of BaseB\n");
    }

    BaseB(const BaseA& Ba):_Ba(Ba)
    {
        // _Ba = Ba;
        printf("constructor of BaseB\n");
    }

    ~BaseB()
    {
        printf("destructor of BaseB\n");
    }



private:
    BaseA _Ba;
};      // class BaseB



int main(int argc, char const *argv[])
{
    BaseA a;
    BaseB b(a);
    return 0;
}

/* 
1 构造函数初始化列表
constructor of BaseA
copy constructor of BaseA
constructor of BaseB
destructor of BaseB
destructor of BaseA
destructor of BaseA
 */

/*
2 不使用构造函数的初始化类别，直接在构造函数体内进行赋值
constructor of BaseA
constructor of BaseA
copy assignment of BaseA
constructor of BaseB
destructor of BaseB
destructor of BaseA
destructor of BaseA
 */
