/*
 * @Author: your name
 * @Date: 2021-01-05 15:53:59
 * @LastEditTime: 2021-01-05 16:44:07
 * @LastEditors: Please set LastEditors
 * @Description: P187 Member function template，将类成员函数设置为函数模板
 * @FilePath: \chapter6\study_6_8.cpp
 */

#include <iostream>
#include <fstream>


using namespace std;

template <typename OutStream>
class PrintIt
{

public:
    PrintIt(OutStream &os):_os(os)
    {
        
    }

    template <typename elemType>
    void print(const elemType & elem,char delimiter = '\n')
    {
        _os<<elem<<delimiter;
    }




private:
    OutStream& _os;

};   //class PrintIt


int main(int argc, char const *argv[])
{
    ofstream of("6-8.txt");          // 创建一个ofstream对象
    PrintIt<ostream> PI(of);                // ofstream继承了ostream，因此可以直接使用
    PI.print(5,'\n');               
    return 0;
}

