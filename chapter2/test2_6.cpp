/*
 * @Author: your name
 * @Date: 2020-11-26 20:53:53
 * @LastEditTime: 2020-11-26 21:24:51
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \EssentialCPP\chapter2\test2_6.cpp
 */
#include"headfile.h"

template <typename T>
T max(T& a,T& b)        // 这里不加引用会报错
{
    return a > b ? a : b;
}

template <typename T>
T max(vector<T> a)
{
    T max=a[0];
    for (auto iter=a.begin();iter!=a.end();iter++)
    {
        if (*iter > max)
        {
            max=*iter;
        }
    }

    return max;
}

template <typename T>
T max(T* p_T,int length)
{
    T max=p_T[0];
    for (int i=1;i<length;i++)
    {
        if(p_T[i]>max)
        max=p_T[i];
    }

    return max;
}

int main(int argc, char const *argv[])
{   
    int t1=3;
    int t2=5;
    double t3=3.3;
    double t4=4.3;
    char* a__="hello";
    char* b__="world";
    cout<<"(a) max: "<<max(4,3)<<endl;
    cout<<"(b) max: "<<max(3.3,4.3)<<endl;
    cout<<"(c) max: "<<max("a","b")<<endl;

    int a[]={1,2,4,3};
    vector<int> ivec(a,a+4);
    cout<<"(d) max: "<<max(ivec)<<endl;
    
    double b[]={1.1,2.2,4.3,3.1};
    vector<double> dvec(b,b+4);
    cout<<"(e) max: "<<max(dvec)<<endl;

    char* c[]={"hello","world","cpp"};
    vector<char*> cvec(c,c+3);
    cout<<"(f) max: "<<max(cvec)<<endl;

    cout<<"(g) max: "<<max(a,4)<<endl;

    cout<<"(h) max: "<<max(b,4)<<endl;

    cout<<"(i) max: "<<max(c,3)<<endl;
    return 0;
}
