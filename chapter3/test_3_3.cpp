/*
 * @Author: your name
 * @Date: 2020-11-30 20:43:11
 * @LastEditTime: 2020-11-30 21:48:23
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \chapter3\test_3_3.cpp
 */
#include "headfile.h"
#include <algorithm>
#include <iterator>
#include <set>
#include <map>
#include <fstream>

typedef vector<string> vstring;

// 从文件中读取家庭
void readfile2map(ifstream& namefile,map<string,vstring>& famliys){
    string textline;
    while(getline(namefile,textline))
    {
        string familyname;
        vstring children;
        string::size_type pos=0,prev_pos=0,text_size=textline.size();

        while((pos=textline.find_first_of(' ',pos))!=string::npos)
        {
            string::size_type end_pos=pos-prev_pos;

            if(!prev_pos)
            {
                familyname=textline.substr(prev_pos,end_pos);
            }
            else children.push_back(textline.substr(prev_pos,end_pos));
            prev_pos=++pos;
        }

        // 处理最后一个孩子的名字
        if(prev_pos<text_size)
        {
            children.push_back(textline.substr(prev_pos,pos-prev_pos));
        }

        if(!famliys.count(familyname))          // 还没有这个家庭
        {
            famliys[familyname]=children;       // 添加
        }
        else 
        cerr<<"Ops,we already have a "<<familyname<<" family in our map!"<<endl;
    }
}


ostream& operator<<(ostream& os, map<string,vstring>& family)
{
    int num=1;


    
    for(auto iter=family.begin();iter!=family.end();iter++)
    {   
        os<<"---------family"<< num<<"---------"<<endl;
        os<<"family: "<<iter->first<<endl;
        os<<"name: "<<endl;
        for(auto iter2=iter->second.begin();iter2!=iter->second.end();iter2++)
        {
            os<<*iter2<< " ";
        }
        os<<"\n------"<<"\n\n\n"<<endl;
        num++;
    }

    return os;
}

// 打印family
void display_map(  map<string,vstring>& family,ostream& os=cout)
{   
    
    os<<family<<endl;
    // num++;
}



int main(int argc, char const *argv[])
{
    map<string,vstring> familyMap;
    ifstream ifs("test3_3.txt");
    readfile2map(ifs,familyMap);
    ofstream ofs("test3_3_out.txt");
    display_map(familyMap,ofs);
    // cout<<familyMap<<endl;
    
    return 0;
}
