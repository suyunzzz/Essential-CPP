/*
 * @Author: your name
 * @Date: 2021-01-11 10:49:09
 * @LastEditTime: 2021-01-11 14:42:18
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \chapter7 异常处理\test7_3.cpp
 */
#include"Stack.h"

int main(int argc, char const *argv[])
{
    Stack s(1);
    printf("max size:%d\n",s.maxsize());
    
    elemType elem;
    try{
        s.pop(elem);

    }
    catch(const exception& ex)
    {
        printf("%s\n",ex.what());
        // return 0;
    }

    printf("_stack.size:%d, max size:%d\n",s.size(),s.maxsize());


    s.push(*(new string("jjj")));

    printf("_stack.size:%d, max size:%d\n",s.size(),s.maxsize());


    try{
        s.push(*(new string("III")));
    }
    catch(const exception& ex)
    {
        printf("%s\n",ex.what());
    }
    cout<<s<<endl;
    return 0;
}
