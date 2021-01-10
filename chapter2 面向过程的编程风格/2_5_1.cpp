/*
 * @Author: your name
 * @Date: 2020-11-26 11:36:40
 * @LastEditTime: 2020-11-26 16:06:33
 * @LastEditors: Please set LastEditors
 * @Description: 使用局部静态对象，在函数内部定义一个static对象
 * @FilePath: \chapter2\2_5.cpp
 */
#include<iostream>
#include<vector>

using namespace std;

// 判断要生成的数列大小是否满足要求
inline bool is_size_ok(int size) {
    const int max_size =1024;
    if (size>max_size || size<0)
    {
        cerr<<"ERROR";
        return false;
    }

    return true;
}

// 返回数列的指针
const vector<int>* 
fibon_seq(int size) {
    const int max_size =1024;
    static vector<int> elems;

    if(!is_size_ok(size)){
        return nullptr;         // nullptr需要支持c++11。命令行： g++ main.cpp -o main -std=c++11即可
    }

    for(int i=elems.size();i<size;i++)
    {
        if(i==1||i==0){
            elems.push_back(1);
        }
        else
            elems.push_back(elems[i-1]+elems[i-2]);
    }

    return &elems;
}

// 返回数列中的一个值
inline bool fibon_elem(int pos,int &elem)
{
    const vector<int>* pseq=fibon_seq(pos);
    if(pseq==nullptr){
        elem=0;
        return false;
    }

    elem=(*pseq)[pos-1];
    return true;
}


int main(int argc,char **argv)
{
    int a;
    if(fibon_elem(6,a))
    {
        cout<<"a= "<<a<<endl;
    }




    return 0;
}
