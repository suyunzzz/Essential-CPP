/*
 * @Author: your name
 * @Date: 2020-12-02 15:22:56
 * @LastEditTime: 2020-12-02 16:42:53
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \chapter4\P113.cpp
 */
#include<iostream>
#include<vector>
#include<string>

using namespace std;


class Triangular{
public:
    Triangular(int len=1,int beg_pos = 1):_length(len),_beg_pos(beg_pos)
    {if(gen_elems()) cout << "gen!"<<endl;}

    int length() const {return _length;}
    int beg_pos() const { return _beg_pos; }
    int elem(int pos) const {return _elems[pos-1];}

    int size() const {return _length;}

    bool next(int& val) const
    { 
        if(_next<_length){
            val=_elems[_next++];
            return true;
        }
        return false;
    }

    void next_reset() const
    // { _next=_beg_pos-1;}
    { _next=0;}


    bool gen_elems() 
    {
        if(_beg_pos<=0 || _length<=0 ||_length>1024)
        {
            return false;
        }

        // 从1开始，且长度至少为1
        for(int ix=_beg_pos;ix<_length+ _beg_pos;ix++){
            _elems.push_back(ix*(ix+1)/2);
        }

        return true;
    }

    // 打印类内数组
    void display(ostream & os) const
    {
        for(auto it=_elems.begin();it != _elems.end();it++)
        {
            os<<*it<<" ";
        }

        cout<<"\n----------"<<endl;
    }
    // 关于友元函数
    /* 一般来讲，运算符<<重载，是不需要加friend的，
        但是对于这种情况，在输出的时候，需要访问到类内的private member，因此要把其设置为友元。
        假如就是不想设置为友元的话，也有办法，可以将访问private的部分，在类中使用函数替代 */
/*     friend ostream& operator<<(ostream & os,const Triangular& triang)       
    {
        os<<"\n------\n"
            <<"begin_pos: "<<triang._beg_pos<<" , length: "<<triang._length<<endl;
        for(auto i=triang._elems.begin();i!=triang._elems.end();i++)
        {
            os<<*i<<" ";
        }

        os<<endl;

        return os;
    }
 */
private:

    int _length;
    int _beg_pos;

    mutable int _next;

    /* static */ vector<int> _elems;


};//class Triangular

// 不设置为友元
/* 这种就是输出类内private成员的第二种方法：将内部的private用成员函数访问，这样就不需要将重载的运算符设置为friend了 */
ostream& operator<<(ostream& os,const Triangular& t)
{
    os<<"\n---no friend---\n"
    <<"begin_pos: "<<t.beg_pos()<<" , length: "<<t.length()<<endl;
    t.display(os);

    cout<<"\n---no friend---\n"<<endl;

    return os;
}


int sum(const Triangular& triangular);


int main(int argc, char const *argv[])
{
    Triangular tri(4);
    cout<<tri<<"-----sum of elements: "<<sum(tri)<<endl;
    // cout<tri<<"-----sum of elements: "<<sum(tri)<<endl;

    Triangular tri2(4,3);
    cout<<tri2<<"-----sum of elements: "<<sum(tri2)<<endl;

    Triangular tri3(4,8);
    cout<<tri3<<"-----sum of elements: "<<sum(tri3)<<endl;
    return 0;
}


int sum(const Triangular& trian){
    if(!trian.size()) return 0;

    int val,sum=0;
    trian.next_reset();
    while(trian.next(val))
    {
        sum +=val;
    }

    return sum;
}