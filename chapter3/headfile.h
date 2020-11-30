/*
 * @Author: your name
 * @Date: 2020-11-27 19:32:19
 * @LastEditTime: 2020-11-30 21:51:49
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \chapter3\headfile.h
 */
#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <iterator>

#include <cstdlib>      // atoi() 


using namespace std;


// cout<<vector<T> 输出一个vector
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& vec){           // 这里的ostream为什么不能加const ? 加了就报错
    for(auto iter = vec.begin(); iter != vec.end();iter++){
        os<<(*iter)<<" ";
    }
    os<<"\n"<<endl;
    return os;

}