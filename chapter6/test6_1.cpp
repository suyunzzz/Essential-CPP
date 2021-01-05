/*
 * @Author: your name
 * @Date: 2021-01-05 16:52:40
 * @LastEditTime: 2021-01-05 17:14:24
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \chapter6\test6_1.cpp
 */


/* 
1、找到所有和类型相关的部分，将这些数据里面的类型参数化
2、参数化完以后，要注意elemType可能被用来表现内部类型或者class类，
    因此以传址(by reference)的方式传入比传值(by value)的方式好
 */
#include <iostream>
#include <vector>

template <typename elemType1, typename elemType2>
class example{
public:
    example(elemType1& min, elemType1& max);
    example(const elemType1 *array,elemType2 size);
    elemType1& operator[](elemType2 index);
    bool operator==(const example&) const ;
    bool insert(const elemType1*,elemType2);
    bool insert( elemType1&);
    elemType1 min() const {return _min;}
    elemType1 max() const {return _max;}

    void min(elemType1&);
    void max(elemType1&);

    elemType2 count(elemType1& value) const;
private:
    elemType2 size;
    elemType1 *parray;
    elemType1 _min;
    elemType1 _max;


}; //class example