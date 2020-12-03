/*
 * @Author: your name
 * @Date: 2020-12-03 10:00:26
 * @LastEditTime: 2020-12-03 11:30:57
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit  
 * @FilePath: \chapter4\pointer_to_function.cpp
 */


// 参考：https://www.runoob.com/w3cnote/cpp-func-pointer.html

#include <iostream>

using namespace std;
/* typedef int(*pf)(int);  


int test(int a)
{
    return a;
}

int test2(pf p,int c)
{   
    cout<<"\ntest2(pf p,int c)\n"<<endl;
    return p(c);
}



int main(int argc, char const *argv[])
{
    // typedef int(*pf)(int);  
    // pf p=test;
    auto b = test2(test,77);       // 接收两个参数，一个是函数指针，一个是int变量
    cout << b << endl;
    return 0;
}
 */

/* 
void t1() { cout<<"t1"<<endl;}
void t2() { cout<<"t2"<<endl;}
void t3() { cout<<"t3"<<endl;}


typedef void(*pfunc)(void);         // 定义一个函数指针类型

int main(int argc, char const *argv[])
{
    pfunc a[]={t1,t2,t3};       // 构造一个数组a[]，数组内部的成员放的是函数指针

    a[0]();                        // 下标调用函数
    a[1]();    
    a[2]();
    
    return 0;
}
 */


// ----------------------------------------------------------
// 类成员函数指针指向类中的静态成员函数

class A{
public:
    void(A::*p1)(void);     // p1指向类成员函数  非static
    void(*p2)(void);        // p2指向类成员函数  static，定义方式和函数指针相同

    A() {
        p1=&A::funa;            // 指向non-static
        p2=&A::funb;            // 指向static
    }

    void funa()
    {
        printf("\na\n");
    }

    static void funb(){printf("\nb\n");}

private:
}; // class A

int main(int argc, char const *argv[])
{
    A a,c;
    void(A::*p)(void);      // 指向non-static

    printf("--c.*(a.p1/* 函数指针 */))()--");
    (c.*(a.p1/* 函数指针 */))();     // "a"

    printf("--(a.*(a.p1))()--");
    (a.*(a.p1))();     // "a"


    p=a.p1;             // 给外部的函数指针赋值，然后调用
    (a.*p)();          // "a"       

    A* pa=&a;               // 通过类内部的函数指针调用
    (pa->*(pa->p1))() ;      // "a"


    
    // 通过外部的函数指针调用

    void(*pp)(void);                // 定义函数指针，static成员函数指针
    // pp=a.p2;
    cout<<"\n---"<<endl;            
    pp=&A::funb;                    // 取地址，
    pp();                           // static成员函数是可以直接运行的，不需要指定object

    void(A::*ppp)(void);            // 成员函数指针ppp,non-static
    ppp=&A::funa;                   // 取地址
    (a.*ppp)(); // "a"              // non-static成员函数，调用必须要有对象
    (pa->*ppp)(); // "a"


    return 0;
}
