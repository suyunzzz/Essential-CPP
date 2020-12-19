<!--
 * @Author: your name
 * @Date: 2020-12-18 22:49:49
 * @LastEditTime: 2020-12-19 00:19:37
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \chapter5\test5_2\一个常见的问题.md
-->
essential c++中P166第二题中，开始的时候是这样写的：

```cpp
// Stack.h
/*
 * @Author: your name
 * @Date: 2020-12-18 20:59:07
 * @LastEditTime: 2020-12-18 22:40:58
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \chapter5\test5_2\Stack.h
 */
#pragma once
#include <map>
#include <string>
#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>

using namespace std;
typedef string elemType;

class Stack{


public:
    Stack(int);
    virtual ~Stack(){};
     bool pop(elemType&);
     bool push(elemType&) ;
     int size() const ;

     bool empty() const;
     bool full() const ;
    virtual bool peek(int index, elemType&) const ;
     ostream& print(ostream& os=cout) const ;

protected:
    vector<elemType> _stack;
    int _top;


};  // class Stack

ostream& operator<<(ostream& os, const Stack& s)
{   
    os<<"\n------cout------\n"<<endl;
    return(s.print(os));
}
```

```cpp
// Stack.cpp
/*
 * @Author: your name
 * @Date: 2020-12-18 20:59:15
 * @LastEditTime: 2020-12-18 22:53:17
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \chapter5\test5_2\Stack.cpp
 */
#include"Stack.h"

Stack::Stack(int capacity = 0):_top(0)
{
    if(capacity)
    {
        _stack.reserve(capacity);
    }
}

bool
Stack::full() const
{
    if(_stack.size()>=_stack.max_size())
        return true;
    return false;

}


bool 
Stack::empty() const
{
    if(_stack.empty()) return true;
    return false;
}

bool
Stack::pop(elemType& elem)
{
    if(empty()) return false;
    elem = _stack[_top--];
    _stack.pop_back();
    return true;
}

bool 
Stack::push(elemType& elem)
{   
    if(full()) return false;
    _stack.push_back(elem); 
    _top++;
    return true;

}

int 
Stack::size() const
{ return _stack.size(); }


ostream& 
Stack::print(ostream& os) const
{
    for (auto& elem : _stack)
    {
        os<<" "<<elem;
    }

    os<<endl;
    return os;
}

bool
Stack::peek( int index,elemType& elem ) const
{ return false;}


```

```cpp
// main.cpp
/*
 * @Author: your name
 * @Date: 2020-12-18 20:59:19
 * @LastEditTime: 2020-12-18 22:53:54
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \chapter5\test5_2\main.cpp
 */
#include"Stack.h"

int main(int argc, char const *argv[])
{
    Stack s(3);
    s.push(*(new string("jjj")));
    cout<<s<<endl;      // 调用<<重载
    return 0;
}
```
但是在编译的时候，出现错误：
>multiple definition of `operator<<(std::ostream&, Stack const&)'

经过参考：https://stackoverflow.com/questions/12802536/c-multiple-definitions-of-operator

发现原来是因为把函数的定义放在了`.h`头文件中，解决这个问题的方法大致有两个：
>1、将重载函数的声明放在`.h`文件中，把定义放在`.cpp`文件中。

>2、将该重载函数声明为`inline`类型，因为只要所有内联函数的定义相同，`inline`函数可以被多次定义。


