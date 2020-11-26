/*
 * @Author: your name
 * @Date: 2020-11-26 17:17:01
 * @LastEditTime: 2020-11-26 19:19:17
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \EssentialCPP\chapter2\test2_3.cpp
 */

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

bool pentagonal_func(vector<int>& vec,const int size){

    // 检验size大小
    if(size>1024||size<1)
    {   
        cerr<<"ERROR:size is too large"<<endl;
        return false;
    }
    for(int i=1;i<=size;i++){
        vec.push_back(i*(3*i-1)/2);

    }
    return true;
}

void display(const vector<int>& vec, const char* num_type)
{
    for(auto i=vec.begin(); i!=vec.end();i++){
        cout<<*i<<" ";
    }
    cout<<endl;
}


int main(int argc, char const *argv[])
{
    vector<int> a;
    if(pentagonal_func(a,5))
    {
        display(a,"int");
    }
    return 0;
}


