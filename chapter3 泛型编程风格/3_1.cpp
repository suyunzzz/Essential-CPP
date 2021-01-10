/*
 * @Author: your name
 * @Date: 2020-11-27 19:32:07
 * @LastEditTime: 2020-11-27 20:29:45
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \chapter3\3_1.cpp
 */
#include"headfile.h"


template <typename T>
T* begin_( vector<T>& vec) {
    return vec.empty() ? nullptr :&vec[0];
}

template <typename T>
T* end_( vector<T>& vec) {
    return vec.empty() ? nullptr :&vec[vec.size()];
}

template <typename T>
T* find( T* start,  T* end,const T& value) {
    if (start ==nullptr ||end ==nullptr)
    {
        return nullptr;
    }

    for(;start != end;start++)
    {
        if(*start == value)
        {
            return start;
        }
    }
}

int main(int argc, char const *argv[])
{
    int int_array[5]={1,2,3,4,5};

    vector<int> vec(int_array,int_array+5);
    int value = 4;

    // 数组
    int* p=find(int_array,int_array+5,value);
    cout<<"p:"<<p<<endl;
    cout<<"array[0]"<<int_array<<endl;
    cout<<"array[3]"<<int_array+3<<endl<<endl;

    // vector
    p=find(&vec[0],&vec[vec.size()],value);
    cout<<"p:"<<*p<<endl;
    cout<<"array[0]"<<&vec[0]<<endl;
    cout<<"array[3]"<<&vec[3]<<endl<<endl;

    // vector 可以避免vector为空的情况
    int *p_vec_begin=begin_(vec);
    int *p_vec_end=end_(vec);

    p=find(p_vec_begin,p_vec_end,value);
    cout<<"p:"<<*p<<endl;
    cout<<"array[0]"<<p_vec_begin<<endl;
    cout<<"array[3]"<<p_vec_begin+3<<endl<<endl;
    
    return 0;
}
