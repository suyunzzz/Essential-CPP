/*
 * @Author: your name
 * @Date: 2020-11-30 11:23:56
 * @LastEditTime: 2020-11-30 11:32:55
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \chapter3\3_6_2.cpp
 */

#include "headfile.h"
#include <functional>

int main(int argc, char const *argv[])
{
    int a[]={1,1,2,3,5,8,13,21};
    int b[]={33,33,33,33,33,33,33,33};
    vector<int> vec_a(a,a+sizeof(a)/sizeof(a[0]));
    vector<int> vec_b(b,b+sizeof(b)/sizeof(b[0]));

    vector<int> result;
    transform(vec_a.begin(),vec_a.end(),
                vec_b.begin(),
                result.begin(),
                plus<int>());

    
    cout<<result<<endl;
    return 0;
}
