/*
 * @Author: your name
 * @Date: 2020-12-18 20:59:19
 * @LastEditTime: 2020-12-19 23:40:11
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \chapter5\test5_2\main.cpp
 */
#include"Stack.h"
#include "PeekStack.h"

int main(int argc, char const *argv[])
{
    Stack s(3);
    s.push(*(new string("jjj")));
    cout<<s<<endl;      // 调用<<重载


    cout<<"\n-----------------------\n";
    PeekStack ps(2);
    ps.push(*(new string("ps_jjj")));
    ps.push(*(new string("ps_kkk")));
    ps.push(*(new string("ps_lll")));
    elemType ans;
    if(ps.peek(1,ans))
        cout<<"ps.peek: "<<ans<<endl;
    cout<<"cout<<ps:\n"
        <<ps<<endl;
    
    
    
    return 0;
}
