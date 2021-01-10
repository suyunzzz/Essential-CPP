/*
 * @Author: your name
 * @Date: 2020-12-01 11:17:30
 * @LastEditTime: 2020-12-01 11:20:17
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \chapter4\headfile.h
 */
#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <typename T>
ostream& operator<<(ostream& os,vector<T>& vec){
    for(auto iter =vec.begin();iter !=vec.end();iter++)
    {
        os<<*iter<<" ";

    }

    os<<endl;

    return os;
}