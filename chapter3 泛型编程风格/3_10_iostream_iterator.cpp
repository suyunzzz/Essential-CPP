/*
 * @Author: your name
 * @Date: 2020-11-30 19:18:50
 * @LastEditTime: 2020-11-30 19:33:47
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \chapter3\3_10_iostream_iterator.cpp
 */
#include "headfile.h"
#include <iterator>
#include <vector>
#include <string>

int main(int argc, char const *argv[])
{   

    ifstream file1("3_10.txt");
    istream_iterator<string> is(file1);
    istream_iterator<string> eof;
    vector<string> text;
    copy(is, eof,back_inserter(text));

    sort(text.begin(),text.end());

    ofstream ofile("3_10_out.txt");
    ostream_iterator<string> os(/* ofile */cout," ");
    copy(text.begin(), text.end(), os);
    // return 0;
}
