/*
 * @Author: your name
 * @Date: 2020-11-30 21:48:59
 * @LastEditTime: 2020-11-30 22:41:23
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \chapter3\test3_4.cpp
 */

#include "headfile.h"
#include <iterator>
#include <algorithm>

// 定义一个function object，传递给泛型算法partition()
// 偶数返回true
class even_element{
public:
    bool operator() (int elem) {
        return elem % 2 == 0?true:false;
    }
}; // class even_element

int main(int argc, char const *argv[])
{
    ifstream ifs("test3_4.txt");
    istream_iterator<int> it(ifs);
    istream_iterator<int> eof;
    vector<int> vec;
    
    // 为了保持原有的顺序，先使用sort，再使用stable_partition()
    // sort(vec.begin(), vec.end());

    copy(it, eof,back_inserter(vec));   // 读取文件到vec
    cout<<vec<<endl;

    vector<int> num1,num2;      // 用来保存奇数和偶数

    vector<int>::iterator div=stable_partition(vec.begin(),vec.end(),even_element());

    // 将奇偶数分别保存
    ofstream ofs1("num1.txt");
    ofstream ofs2("num2.txt");
    ostream_iterator<int> num1it(ofs1," ");
    ostream_iterator<int> num2it(ofs2," ");

    copy(vec.begin(),div,num1it);
    copy(div,vec.end(),num2it);




    // cout<<vec<<endl;

    cout<<"-----"<<endl;

    // 显示两组数
    ifstream of1("num1.txt");
    istream_iterator<int> it1(of1);
    istream_iterator<int> eof1;
    vector<int> vec_out;
    copy(it1,eof1,back_inserter(vec_out));
    cout<<vec_out<<endl;
    
    ifstream of2("num1.txt");
    istream_iterator<int> it2(of2);
    // vector<int> vec_out;
    copy(it2,eof,back_inserter(vec_out));
    cout<<"num2\n"<<vec_out<<endl;
    

    return 0;
}
