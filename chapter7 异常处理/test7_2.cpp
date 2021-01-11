/*
 * @Author: your name
 * @Date: 2021-01-11 10:00:43
 * @LastEditTime: 2021-01-11 10:41:44
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \chapter7 异常处理\test7_2.cpp
 */


#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

int* allocate_array(const int elem_cnt)
{
    int* pi = new int[elem_cnt];
    return pi;
}

int* alloc_and_init(string filename) {
    ifstream infile(filename.c_str());      // 打开文件
    if(!infile) return 0;           // 打开失败

    int elem_cnt;
    infile >> elem_cnt;
    if(! infile) return 0;      // 读取数量失败

/*     try
    { */
        int* pi = allocate_array(elem_cnt);     // 分配空间,可能报错 nomem

        int elem=0;
        int _index = 0;
        while(infile>>elem && _index < elem_cnt)
        {
            *(pi+_index) = elem;
            _index++;
        }

        // sort_array(pi, elem_cnt);
        // register_data(pi);
/*     } */

/*     catch(const noMem& memFail)
    {
        cerr<<"alloc_and_init():allocate_array failure!\n"
            <<memFail.what()<<endl;
        return 0;
    }
    catch(const int& sortFail)
    {
        cerr<<"alloc_and_init(): sort_array failure!\n"
            <<"thrown interger value: "<<sortFail<<endl;
        return 0;
    }
    catch(const string& registerFail)
    {
        cerr<<"alloc_and_init(): register_data failure!\n"
            <<"thrown string value: "<<registerFail<<endl;
        return 0;
    } */

    // 无异常
    return pi;

}

int main(int argc, char const *argv[])
{
    int* pi;
    pi = alloc_and_init("test.txt");
    vector<int> vec(pi,pi+5);
    for(auto i = vec.begin();i!=vec.end();i++)
    {
        cout<<" "<< *i<<" ";
    }
    return 0;
}
