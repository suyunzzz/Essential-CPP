/*
 * @Author: your name
 * @Date: 2020-11-26 16:14:35
 * @LastEditTime: 2020-11-26 16:32:26
 * @LastEditors: Please set LastEditors
 * @Description: 函数模板
 * @FilePath: \EssentialCPP\chapter2\2_7.cpp
 */
#include "headfile.h"

// 函数模板 其中T可以任意指定
template <typename T>
void display_message(const string& msg,const vector<T>& vec,  ostream& os=cout)
{
    os<<msg;
    for(auto iter=vec.begin();iter!=vec.end();iter++){
        os<<*iter<<" ";
    }

    os<<"\n-----------------\n"<<endl;
}

// void display_message(const string& msg,const list<T>& vec,const ostream& os=cout)
// {

// }

int main(int argc, char const *argv[])
{
    int a[3]={1,2,3};
    double b[4]={2,3,8.7,6};
    vector<int> vec_t(a,a+3);
    vector<double> vec_d(b,b+4);
    
    ofstream file("2_5.txt");


    display_message("Hello World\n",vec_t,file);

    // cout <<"------------"<<endl;

    display_message("hello,world\n",vec_d,file);
    return 0;
}

