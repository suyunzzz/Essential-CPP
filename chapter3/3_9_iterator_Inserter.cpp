/*
 * @Author: your name
 * @Date: 2020-11-30 16:39:13
 * @LastEditTime: 2020-11-30 17:09:34
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \chapter3\3_9_iterator_Inserter.cpp
 */

#include"headfile.h"
#include <iterator>

// P88 对filter制作为函数模板
template<typename InputIterator,typename OutputIterator,
        typename ElementType,typename Comp>
// OutputIterator
void
filter_temp(InputIterator firstIter,InputIterator lastIter,OutputIterator outIter,ElementType val,Comp comp){
    for(auto iter = firstIter;iter!=lastIter;){
        if((iter=find_if(iter,lastIter,bind2nd(comp,val)))!=lastIter){
            cout<<"Find value: "<<*iter<<endl;
            (*outIter) =( *iter);
            outIter++;
            iter++;
        }
        // else
        // return;
    }
}

// P93 对filter制作为函数模板,使用Iterator Inserter

/* 使用inserter adapter作为参数传入，不需要考虑目的容器的大小
param:
firstIter 原容器的开始指针，
lastIter 原容器的结束指针
outIter 目标容器的开始指针
val 需要比较的值
comp 比较方式（大于、小于等）
 */
template<typename InputIterator,typename OutputIterator,
        typename ElementType,typename Comp>
void
filter_temp_iterator_inserter(InputIterator firstIter,InputIterator lastIter,OutputIterator outIter,ElementType val,Comp comp){
    for(auto iter = firstIter;iter!=lastIter;){
        if((iter=find_if(iter,lastIter,bind2nd(comp,val)))!=lastIter){
            // cout<<"Find value: "<<*iter<<endl;
            (*outIter) =( *iter);
            // outIter++;
            iter++;
        }
        // else
        // return;
    }
}

int main(int argc, char const *argv[])
{
    int a[]={1,1,2,3,5,8,13,21};
    vector<int> vec(a,a+sizeof(a)/sizeof(a[0]));
    vector<int> res;     

    // back_inserter(res);
    // filter_temp(vec.begin(),vec.end(),res.begin(),10,less<int>());      
    filter_temp_iterator_inserter(vec.begin(),vec.end(),back_inserter(res),10,less<int>());
    cout<<res<<endl;
    return 0;
}
