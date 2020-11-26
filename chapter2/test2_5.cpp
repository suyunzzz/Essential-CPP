/*
 * @Author: your name
 * @Date: 2020-11-26 20:25:59
 * @LastEditTime: 2020-11-26 20:53:22
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \EssentialCPP\chapter2\test2_5.cpp
 */
#include "headfile.h"

int max(int a,int b){
    return a>b?a:b;
}

double max(double a,double b){
    return a>b?a:b;
}

char* max(char* a,char* b){
    return a>b?a:b;
}

int max(vector<int> vec){
    int tmp=vec[0];
    for(auto iter=vec.begin()+1;iter!=vec.end();iter++){
        if (*iter>tmp)
        {
            tmp=*iter;
        }
    }

    return tmp;

}

double max(vector<double> vec){
    double tmp=vec[0];
    for(auto iter=vec.begin()+1;iter!=vec.end();iter++){
        if (*iter>tmp)
        {
            tmp=*iter;
        }
    }

    return tmp;
}

char* max(vector<char*> vec){
    char* tmp=vec[0];
    for(auto iter=vec.begin()+1;iter!=vec.end();iter++){
        if (*iter>tmp)
        {
            tmp=*iter;
        }
    }

    return tmp;
}

int max(const int* p_array,int array_length)     // 数组做形参
{
    int max=p_array[0];
    for(int i=1;i<array_length;i++)
    {
        if(p_array[i]>max)
        max=p_array[i];
    }

    return max;
}

double max(const double* p_array,int array_length)     // 数组做形参
{
    double max=p_array[0];
    for(int i=1;i<array_length;i++)
    {
        if(p_array[i]>max)
        max=p_array[i];
    }

    return max;
}

char* max( char* (*p_array),int array_length)     // 数组做形参
{
    char* max=p_array[0];
    for(int i=1;i<array_length;i++)
    {
        if(p_array[i]>max)
        max=p_array[i];
    }

    return max;
}


int main(int argc, char const *argv[])
{
    cout<<"(a) max: "<<max(3,5)<<endl;
    cout<<"(b) max: "<<max(3.4,5.2)<<endl;
    cout<<"(c) max: "<<max("a","b")<<endl;

    int a[]={1,2,4,3};
    vector<int> ivec(a,a+4);
    cout<<"(d) max: "<<max(ivec)<<endl;
    
    double b[]={1.1,2.2,4.3,3.1};
    vector<double> dvec(b,b+4);
    cout<<"(e) max: "<<max(dvec)<<endl;

    char* c[]={"hello","world","cpp"};
    vector<char*> cvec(c,c+3);
    cout<<"(f) max: "<<max(cvec)<<endl;

    cout<<"(g) max: "<<max(a,4)<<endl;

    cout<<"(h) max: "<<max(b,4)<<endl;

    cout<<"(i) max: "<<max(c,3)<<endl;


    return 0;
}

