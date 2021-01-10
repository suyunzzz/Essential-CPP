/*
 * @Author: your name
 * @Date: 2020-12-18 20:46:41
 * @LastEditTime: 2020-12-18 20:54:40
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \chapter5\resize_reserve.cpp
 */
#include <iostream>
#include <vector>
using namespace std;


int main(int argc, char const *argv[])
{
    vector<int> a;
    // a.set_capacity(50)
    
    a.reserve(100);
    a.resize(101);
    return 0;
}
