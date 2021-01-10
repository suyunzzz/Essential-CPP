/*
 * @Author: your name
 * @Date: 2020-12-01 10:29:37
 * @LastEditTime: 2020-12-01 12:31:32
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \chapter4\test4_1.cpp
 */
#include "Stack.h"

int main(int argc, char const *argv[])
{
    string a[]={"a","b","c","d","g","e","f","g"};

    Stack s1(a,a+8);
    vector<string> a_v(a,a+8);
    Stack s(a_v);

    cout <<s1<<endl;

    if(s1.push("111"))
    {
        cout<<s1.size()<<endl;
        cout <<s1<<endl;
    }


    string pop1;
    s1.pop(pop1);       // 取出最后一个
    cout <<s1<<endl;
    cout<<"pop1: "<<pop1<<endl;

    string pop2;
    s1.peek(pop2);
    cout <<s1<<endl;
    cout<<"pop2: "<<pop2<<endl; 

    cout<<"----find-----"<<endl;
    if(s1.myfind(pop2))
    // cout<<"found"<<endl;

    cout<<"----count-----"<<endl;
    
    int num=s1.mycount(pop2);
    cout<<"num: "<<pop2<<" = "<<num<<endl;


    return 0;
}
