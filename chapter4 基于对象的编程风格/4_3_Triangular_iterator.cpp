/*
 * @Author: your name
 * @Date: 2020-12-07 10:20:42
 * @LastEditTime: 2020-12-07 16:50:28
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \chapter4\4_3_Triangular_iterator.cpp
 */
#include "4_3_Triangular_iterator.h"
#include "4_3_Triangular.h"         // 包含头文件

bool Triangular_iterator::operator==(const Triangular_iterator& rhs) const {
    return this->_index==rhs._index;
}
    
bool Triangular_iterator::operator !=( const Triangular_iterator& rhs) const{
    return(!(_index==rhs._index));
}

int Triangular_iterator::operator*() const{
    check_integrity();
    return Triangular::_elems[_index];
}

void Triangular_iterator::check_integrity() const
{
    if(_index>Triangular::_max_elems)
    {
        throw iterator_overflow();
    }

    if(_index>Triangular::_elems.size())
    {Triangular::gen_elements(_index);}
}

// 前自增
Triangular_iterator&
Triangular_iterator::operator++()
{
    _index++;
    check_integrity();
    return *this;
}

// 后自增
// 关于这里为什么不能像前自增那样，返回一个引用呢？
// 返回引用类型是将变量直接返回，而不是创建一个临时变量再返回这个临时变量，因此返回引用类型的函数是可以作为等号左值被赋值的，而返回值类型的函数（返回的是临时变量）不能被重新赋值
// 因为这个后自增是返回一个临时变量，当函数结束后，临时变量tmp也就消失，如果再返回引用，就会报错，因此只能返回临时变量tmp的一个临时变量
Triangular_iterator 
Triangular_iterator::operator++(int)
{
    
    Triangular_iterator tmp=*this;
    _index++;
    check_integrity();
    return tmp;     // tmp是一个临时变量，因此不能返回引用类型
}
