/*
 * @Author: your name
 * @Date: 2020-12-02 14:29:14
 * @LastEditTime: 2020-12-02 21:09:58
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \chapter4\4_3_Triangular.cpp
 */

// TODO 完成程序
#include "4_3_Triangular.h"

ostream& operator<<(ostream & os,const Triangular& t)
{
    os<<" ( "
        <<t.beg_pos()<<" , "
        <<t.length()<<" ) ";

    t.display(t.length(),t.beg_pos(),os);           // 这里应该是 const class object 只能调用const成员函数吧？
    return os;
}

istream& operator>>(istream & is,Triangular& t)
{
    char ch1,ch2;
    int bp,len;

    is>>ch1>>bp>>ch2>>len;
    t.beg_pos(bp);
    t.length(len);
    t.next_rest();

    return is;
}

Triangular::Triangular(int len, int beg_pos, int end_pos)
    :_length(len>0?len:1),_beg_pos(beg_pos_>0?beg_pos:1)
{
    _next=_beg_pos;

    int elem_cnt = _beg_pos+_length;
    if(_elems.size()<elem_cnt)
        gen_elements(elem_cnt);
}

Triangular::Triangular(const Triangular& rhs)
    :_length(rhs._length),_beg_pos(rhs._beg_pos),_next(rhs._next)
{

}

int sum(const Triangular& trian)
{
    if(!trian.length())
        return 0;

    int val,sum=0;
    trian.next_rest();

    while(trian.next(val))  
        sum+=val;

    return sum;
}

vector<int> Triangular::_elems;
bool Triangular::is_elem(int value)
{
    if(!_elems.size() || _elems[_elems.size()-1]<value)
        gen_elems_to_value(value);

    vector<int>::iterator found_it;
    vector<int>::iterator end_it = _elems.end();

    found_it = find(_elems.begin(), end_it,value);
    return found_it!=end_it;
}

bool Triangular::is_elem(int value)
{
    if(!_elems.size() || _elems[_elems.size()-1]<value)
    {
        gen_elems_to_value(value);
    }

    auto it=find(_elems.begin(), _elems.end(),value);

    return found_it!=end();
}

void
Triangular::gen_elements(int length)
{
    if(length<0  || length>max_elems)
    {
        cerr << "[length>max_elems]"<<endl;
        return;
    }
    if(_elems.size()<length)
    {
        int ix=_elems.size()?elems.size()+1:1;
        for(;ix<=length;ix++)
        {
            _elems.push_back(ix*(ix+1)/2);
        }
    }
}

void Triangular::gen_elems_to_value(int value)
{
    int ix = elems.size();
    if(ix==0){
        _elems.push_back(1);
        ++ix;
    }

    while(ix<max_elems && _elems[ix-1]<value){
        _elems.push_back(ix*(ix+1)/2);
        ++ix;
    }

    if(ix==max_elems)
    {
        cerr << "Triangular Sequence: oops: value too large "
            << value << " --  exceeds max size of "
            << _max_elems << endl;
    }
}

void Triangular::display(int length,int beg_pos,ostream & os=cout){
    if(_length<=0 || beg_pos<=0){
         cerr << "invalid parameters -- unable to fulfill request: "
			  << length << ", " << beg_pos << endl;
		 return;
    }

    int elems=beg_pos+length-1;

    if(_elems.size()<elems){
        gen_elements(elems);
    }

    for(int ix=beg_pos-1;ix<elems;ix++){
        os<<_elems[ix]<<" ";
    }
}

inline bool 
Trianguar_iterator::operator==(const Trianguar_iterator& rhs) const {
    return _index ==rhs._index;
}

inline bool
Trianguar_iterator::operator!=(const Trianguar_iterator& rhs) const {
    return !(*this == rhs);
}




Triangular::Triangular(int len=1,int beg_pos = 1)
    :_length(len>0?len:1),_beg_pos(beg_pos>0?beg_pos:1)
{
    _next=_beg_pos;
    int elem_cnt=_beg_pos+_length;
    if(_elems.size()<elem_cnt)
        gen_elem
}

Triangular::elem(int pos) const {
    return _elems[pos-1];
}
