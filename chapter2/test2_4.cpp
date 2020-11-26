/*
 * @Author: your name
 * @Date: 2020-11-26 19:47:28
 * @LastEditTime: 2020-11-26 22:41:14
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \EssentialCPP\chapter2\test2_4.cpp
 */
#include "headfile.h"

inline bool is_size_ok(int size)
{   
    const int max_size =1024;
    if (size<1 || size>max_size)
    {
        cerr << "Error"<<endl;
        return false;
    }
    return true;
}

vector<int>* getPentagonalArray(const int size)
{
    if(!is_size_ok(size)){
        cerr << "Error"<<endl;
        return nullptr;
    }

    static vector<int> vec;
    cout<<"vec size:"<<vec.size()<<endl;
    if(size>vec.size()){
    for(int i=vec.size()+1;i<=size;i++)
    {   
        cout<<"[getPentagonalArray] "<<i<<endl;
        vec.push_back( i*(3*i-1)/2 );
    }}

    return &vec;

}

// 返回确定位置出的元素
int getPosNum(const vector<int>& vec,int pose)
{   
    pose--;     // 第5个元素 应该是下标为4的
    if(pose<=0||pose>=vec.size())
    {
        cerr<<"Error"<<endl;
        return -1;
    }

    int ans=vec[pose];

    return ans;
}

int main(int argc, char const *argv[])
{
    vector<int>* vec=getPentagonalArray(5);
    for(auto iter=vec->begin(); iter!=vec->end();iter++)
    {
        cout<<*iter<<" ";
    }
    cout<<endl;

    int ans=getPosNum(*vec,4);
    cout<<"ans: "<<ans<<endl;

    vector<int>* vec1=getPentagonalArray(10);
    for(auto iter=vec1->begin(); iter!=vec1->end();iter++)
    {
        cout<<*iter<<" ";
    }
    cout<<endl;

    ans=getPosNum(*vec1,10);
    cout<<"ans: "<<ans<<endl;

    // -----------------------------------

    vec1=getPentagonalArray(8);
    for(auto iter=vec1->begin(); iter!=vec1->end();iter++)
    {
        cout<<*iter<<" ";
    }
    cout<<endl;

    ans=getPosNum(*vec1,10);
    cout<<"ans: "<<ans<<endl;

    return 0;
}

// 程序输出：


/* vec size:0
[getPentagonalArray] 1
[getPentagonalArray] 2
[getPentagonalArray] 3
[getPentagonalArray] 4
[getPentagonalArray] 5
1 5 12 22 35
ans: 22
vec size:5
[getPentagonalArray] 6
[getPentagonalArray] 7
[getPentagonalArray] 8
[getPentagonalArray] 9
[getPentagonalArray] 10
1 5 12 22 35 51 70 92 117 145
ans: 145 */
