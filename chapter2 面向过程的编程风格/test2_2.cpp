/*
 * @Author: your name
 * @Date: 2020-11-26 17:17:01
 * @LastEditTime: 2020-11-26 22:29:20
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
    for(int i=vec.size()+1;i<=size;i++){

        cout<<"[pentagonal_func] "<<i<<endl;
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

    if(pentagonal_func(a,10))
    {
        display(a,"int");
    }

    if(pentagonal_func(a,20))
    {
        display(a,"int");
    }

    return 0;
}


