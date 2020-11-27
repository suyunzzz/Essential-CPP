/*
 * @Author: your name
 * @Date: 2020-11-27 20:49:37
 * @LastEditTime: 2020-11-27 21:20:11
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \chapter3\.vscode\3_2.cpp
 */

#include "headfile.h"


template <typename T>
void display(const vector<T>& vec,ostream& os=cout)
{
    for(auto iterator=vec.begin();iterator!=vec.end();++iterator)
    {
        os<<*iterator<<" ";
    }

    os<<"\n";
    
}



template <typename IterT,typename elemT>
IterT
find(IterT first, IterT last,const elemT& value)
{
    for(;first != last;first++)
    {
        if(*first == value)
        {
            cout<<"find!"<<endl;
            return first;

        }
    }
    cout<<"not found"<<endl;
    return last;
}

int main(int argc, char const *argv[])
{
    const int asize=8;
    int ia[asize]={1,1,2,3,5,8,13,21};

    vector<int> ivec(ia,ia+asize);
    list<int> ilist(ia,ia+asize);

    int* pia=find(ia,ia+asize,5);
    if (pia!=(ia+asize))
    {
        cout<<"*pia: "<<*pia<<endl;
    }

    vector<int>::iterator it;
    it=find(ivec.begin(),ivec.end(),5);
    if(it!=ivec.end())
    {
        cout<<"*it: "<<*it<<endl;
    }
    

    list<int>::iterator iter;
    iter=find(ilist.begin(),ilist.end(),5);
    if(iter!=ilist.end())
    {
        cout<<"*[list]iter: "<<*iter<<endl;
    }

    ofstream ofs("3_2_display.txt");
    display(ivec,ofs);
    return 0;
}
    