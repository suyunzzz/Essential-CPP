/*
 * @Author: your name
 * @Date: 2020-11-26 15:18:35
 * @LastEditTime: 2020-11-26 16:00:42
 * @LastEditors: Please set LastEditors
 * @Description: 默认参数值
 * @FilePath: \EssentialCPP\chapter2\2_5_0.cpp
 */

#include <iostream>
#include <vector>
#include <fstream>      // oftream要包含这个头文件
using namespace std;

// 交换两个数，注意要使用引用，不能按值传递
void swap(int& a,int& b,ofstream* ofil)
{
    // (*ofil) <<"[before swap] a="<<a<<", b="<<b<<endl;
    
    int tmp;
    tmp = a;
    a=b;
    b=tmp;
    // (*ofil) <<"[swap] a="<<a<<", b="<<b<<endl;

}

// 升序排列 冒泡排序,时间复杂度O(n^2)
void bubble_sort(vector<int>& vec,ofstream* ofil=nullptr)
{
    for(int i=0; i<vec.size(); i++)
    {
        for (int j=i+1;j<vec.size(); j++)
        {
            if(vec[j]<vec[i]) 
            {
                if(ofil!=nullptr)
                {
                    (*ofil) <<"i="<<vec[i]<<", j="<<vec[j]<<endl;       // 取迭代器的值

                }
                swap(vec[i],vec[j],ofil);
            }
        }
    }
}

// 显示函数，其中ofstream继承自ostream
void display(const vector<int> &vec,ostream & os_=cout)
{
    for(auto iter=vec.begin();iter!=vec.end();++iter)
    {
        os_<<*iter<<",";
    }
    cout<<endl;
}

int main()
{
    int a[8]={2,1,5,3,7,9,7,99};
    vector<int> vec(a,a+8);

    ofstream log_("mylog2.txt");        // 创建一个txt文档，并写入
    bubble_sort(vec,&log_);
    
    display(vec,log_);


    return 0;
}

