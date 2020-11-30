/*
 * @Author: your name
 * @Date: 2020-11-30 22:41:32
 * @LastEditTime: 2020-11-30 22:46:02
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \chapter3\test_3_4_.cpp
 */

#include "headfile.h"

int main(int argc, char const *argv[])
{
    
    // 显示两组数
    ifstream of1("num1.txt");
    istream_iterator<int> it1(of1);
    istream_iterator<int> eof1;
    vector<int> vec_out;
    copy(it1,eof1,back_inserter(vec_out));
    cout<<"num1\n"<<vec_out<<endl;
    
    ifstream of2("num2.txt");
    istream_iterator<int> it2(of2);
    vector<int> vec_out2;
    copy(it2,eof1,back_inserter(vec_out2));         // copy接收的形参:(源文件的起点iterator，源文件的终点iterator，目标文件的iterator)
    cout<<"num2\n"<<vec_out2<<endl;
    
    return 0;
}
