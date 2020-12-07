/*
 * @Author: your name
 * @Date: 2020-12-02 14:29:14
 * @LastEditTime: 2020-12-07 16:58:39
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \chapter4\4_3_Triangular.cpp
 */

// TODO 完成程序
#include "4_3_Triangular.h"
// #include "4_3_Triangular_iterator.h"



Triangular::Triangular(int len, int beg_pos)
    :_length(len>0?len:1),_beg_pos(beg_pos>0?beg_pos:1)
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
    trian.next_rest();          // 重设begin

    while(trian.next(val))  
        sum+=val;

    return sum;
}

vector<int> Triangular::_elems;     // 定义static变量

bool Triangular::is_elem(int value)
{
    if(!_elems.size() || _elems[_elems.size()-1]<value)
    {
        gen_elems_to_value(value);
    }

    auto it=find(_elems.begin(), _elems.end(),value);

    return it!=_elems.end();
}

void
Triangular::gen_elements(int length)
{
    if(length<0  || length>_max_elems)
    {
        cerr << "[length>max_elems]"<<endl;
        return;
    }
    if(_elems.size()<length)
    {
        int ix=_elems.size()?_elems.size()+1:1; // f存放的是f(1),f(2),...f(length)
        for(;ix<=length;ix++)
        {
            _elems.push_back(ix*(ix+1)/2);
        }
    }
}

void Triangular::gen_elems_to_value(int value)
{
    int ix = _elems.size();
    if(ix==0){
        _elems.push_back(1);
        ++ix;
    }

    while(ix<_max_elems && _elems[ix-1]<value){
        _elems.push_back(ix*(ix+1)/2);
        ++ix;
    }

    if(ix==_max_elems)
    {
        cerr << "Triangular Sequence: oops: value too large "
            << value << " --  exceeds max size of "
            << _max_elems << endl;
    }
}

// 如果类的成员函数带有默认参数，
// 那么注意一点：默认参数只能出现在申明和定义中的一处。
// （有且只能是一处）
// 我们建议是在类的申明中进行默认参数的说明，而在定义中不再说明。
void Triangular::display(int length,int beg_pos,ostream & os)  {
    if(length<=0 || beg_pos<=0){
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






int
Triangular::elem(int pos) const {
    return _elems[pos-1];
}

bool 
Triangular::next(int& value) const
{
    if(!_next){
        return false;
    }

    if(_next<_beg_pos+_length)
    {
        value = _elems[_next++];
        return true;
    }

    _next=0;

    return false;
    
}
