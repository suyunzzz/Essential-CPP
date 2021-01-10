/*
 * @Author: your name
 * @Date: 2020-11-26 21:47:08
 * @LastEditTime: 2020-11-26 22:19:05
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \chapter2\test2_1.cpp
 */
#include "headfile.h"

inline bool is_size_ok(int size){
    const int max_size =1024;
    if (size > max_size || size<=0)
    {
        cerr << "Error"<<endl;

        return false;
    }

    return true;
}


inline const vector<int>* fibon_seq(int size){
    const int max_size =1024;
    static vector<int> elems;

    if(!is_size_ok(size))
    {
        return nullptr;
    }

    for(int i = elems.size(); i < size;i++)
    {
        if(i==0 || i==1)
        {
            elems.push_back(1);
        }
        else
        elems.push_back(elems[i-1]+elems[i-2]);
    }

    return &elems;
}

bool filbon_elem(int pos,int& elem)
{
    const vector<int>* pvec=fibon_seq(pos);
    if(pvec!=nullptr)
    {
        // elem = *((*pvec).end());
        elem = (*pvec)[pos-1];
        return true;
    }
    elem=0;
    return false;

}



int main(int argc, char const *argv[])
{
    int pos,elem;
    char ch;
    bool more=true;

    while(more)
    {
        cout<<"Please enter a pos: ";
        cin>>pos;

        filbon_elem(pos,elem);

        cout<<"pos: #"<<pos<<" is ["<<elem<<"]\n";

        cout<<"continue? ";
        cin>>ch;
        if(ch=='N')
        {
            // more=false;
            break;
        }
        
    }
    // filbon_elem(4,elem);

    return 0;
}

