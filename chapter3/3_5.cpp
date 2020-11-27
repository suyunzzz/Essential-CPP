/*
 * @Author: your name
 * @Date: 2020-11-27 21:58:51
 * @LastEditTime: 2020-11-27 22:55:05
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \chapter3\3_5.cpp
 */
#include "headfile.h"

// 将vec增长至 value大小
bool grow_vec(vector<int>& vec,int value)
{   
    // int max_value=*max_element(vec.begin(),vec.end());          // max_element() 返回迭代器，应对其dereference
    int max_value=vec[vec.size()-1];          // 因为vec是有序排列的，因此其最大值可以直接取得

    while(max_value < value){
        vec.push_back(vec[vec.size()-1]+vec[vec.size()-2]);
        // max_value = *max_element(vec.begin(),vec.end());     // updata max_value
        max_value = vec[vec.size()-1];     // updata max_value  通过取最后一个元素，获取最大值

        if( max_value == value){
            return true;
        }
        else if(max_value > value){
            return false;
    }
}

    return true;
}

// 判断一个元素是否在vector中
bool is_elem(vector<int> &vec,int elem)
{
    // int max_value = *max_element(vec.begin(),vec.end());
    int max_value = vec[vec.size()-1];      // 判断最大值是否达到elem

    if (max_value < elem)                   // 数列长度太短
    {
        return grow_vec(vec,elem);          
    }

    if (max_value > elem)                   
    {
        return binary_search(vec.begin(),vec.end(),elem);
    }

    return true;
}

int main(int argc, char const *argv[])
{   
    int a[]={1,1,2,3,5,8,13,21};
    vector<int> vec_a(a,a+sizeof(a)/sizeof(a[0]));
    if(is_elem(vec_a,atoi(argv[1])))            // debug怎么？答：在launch.json中的args[]添加，具体的launch.json文件见最后
    {
        cout<<"Found"<<endl;
    }

    else
    {
        cout<<"Not found"<<endl;
    }
    return 0;
}



// launch.json文件，如何debug
/* {
    // 使用 IntelliSense 了解相关属性。 
    // 悬停以查看现有属性的描述。
    // 欲了解更多信息，请访问: https://go.microsoft.com/fwlink/?linkid=830387
    "version": "0.2.0",
    "configurations": [
        {
            "name": "g++.exe - 生成和调试活动文件",
            "type": "cppdbg",
            "request": "launch",
            "program": "${fileDirname}\\${fileBasenameNoExtension}.exe",
            "args": ["55"],                     // 在这里添加命令行参数
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "environment": [],
            "externalConsole": false,
            "MIMode": "gdb",
            "miDebuggerPath": "C:\\Program Files\\mingw64\\bin\\gdb.exe",
            "setupCommands": [
                {
                    "description": "为 gdb 启用整齐打印",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ],
            "preLaunchTask": "C/C++: g++.exe build active file"
        }
    ]
} */