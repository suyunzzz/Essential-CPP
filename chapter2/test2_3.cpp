/*
 * @Author: your name
 * @Date: 2020-11-26 19:17:48
 * @LastEditTime: 2020-11-26 19:45:49
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \EssentialCPP\chapter2\test2_3.cpp
 */
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

inline bool is_size_ok(int size)
{   
    const int max_size =1024;
    if (size<1 || size>max_size)
    {
        cerr << "Error"<<endl;
        return false;
    }
    return true;
}

bool pentagonal_func(vector<int>& vec,const int size){
    if (is_size_ok(size))
    {
        for(int i=1;i<=size;i++){
            // vec[i-1]= i*(3*i-1)/2;
            vec.push_back( i*(3*i-1)/2 );

        }

        return true;
    }

    return false;

}

void display(const vector<int>& vec,ostream* p_os=&cout)        
{
    *p_os <<"---[display by pointer]---\n";
    for(auto i=vec.begin();i!=vec.end();i++){
        *p_os<<*i<<" ";
    }

    *p_os <<endl;
}

void display(const vector<int>& vec,ostream& p_os=cout)        
{
    p_os <<"---[display by reference]---\n";
    for(auto i=vec.begin();i!=vec.end();i++){
        p_os<<*i<<" ";
    }

    p_os <<endl;
}


int main(int argc, char const *argv[])
{
    /* code */
    vector<int> vec;
    pentagonal_func(vec,5);
    // display(vec);       // 打印到终端

    ofstream ofs("test2.txt");
    display(vec,&ofs);      // 打印到文件   ，指针传递

    ofstream ofs1("test2_.txt");       // reference传递
    display(vec,ofs1);      // 打印到文件
    return 0;
}
