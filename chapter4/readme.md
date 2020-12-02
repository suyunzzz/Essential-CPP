<!--
 * @Author: your name
 * @Date: 2020-12-01 09:51:11
 * @LastEditTime: 2020-12-01 20:10:11
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \chapter4\readme.md
-->
# 基于对象的编程风格

## 4.1 如何实现一个class
>`public member`可以在程序的任何地方被访问，`private member`只能在`member function`或是`class friend`内被访问。

>如果一个成员函数在class内定义，那么会自动被视为inline函数。

> test4_1相关的为P103的练习1和练习2

- **tips**
```cpp
cin.clear();        // 清除end-of-file的设定
```

## 4.2 什么是构造函数和析构函数

1. 对于含有指针成员变量的类，需要重写一个复制构造函数，实现深拷贝
2. 对于基类，要将析构函数设置为虚函数

## 4.3 何谓mutable（可变）和const（不变）

1. const类对象对只能调用const成员函数
2. 对于一些不具有常量熟悉的成员变量（比如类中的iterator机制），可以将其声明为`可变的（如 mutable int _next）`，这样就可以在const成员函数中对其修改。

## 4.4 什么是this指针

## 4.5 静态类成员

- **静态成员函数**没有 this 指针，只能访问静态成员（包括静态成员变量和静态成员函数）。

- 普通成员函数有 this 指针，可以访问类中的任意成员；而静态成员函数没有 this 指针。

  

- 静态成员只有一个，必须在类外部通过`范围解析运算符::`对其进行初始化。

  ```cpp
  type class::name = value;
  ```

  如果在类外部仅仅对静态成员进行定义，而不对静态成员进行初始化，如：

  ```cpp
  string test4_3::_program_name;
  int test4_3::_tests_passed;
  ```

  那么静态成员会被默认设置为0。

  如果不在类外进行定义或者初始化，那么在调用该类的时候会显示`未定义的引用`，*猜测可能是*在类内的仅仅是声明，并不分配内存。

  > 总结一下就是，静态成员需要在类外部进行定义或初始化，如果没有初始化（仅仅是定义），那么其静态成员对应的值为0。

- 只有`const static 成员`才能在类内进行初始化。

  ```cpp
      const   static int _tests_run=9;        // const static 成员
  ```

- **<u>注意：static 成员变量的内存既不是在声明类时分配，也不是在创建对象时分配，而是在（类外）初始化时分配。反过来说，没有在类外初始化的 static 成员变量不能使用。</u>**

#### **几点说明** 

1) 一个类中可以有一个或多个静态成员变量，所有的对象都共享这些静态成员变量，都可以引用它。

2) static 成员变量和普通 static 变量一样，都在内存分区中的全局数据区分配内存，到程序结束时才释放。这就意味着，static 成员变量不随对象的创建而分配内存，也不随对象的销毁而释放内存。而普通成员变量在对象创建时分配内存，在对象销毁时释放内存。

3) **静态成员变量必须初始化，而且只能在类体外进行**。例如：

```cpp
int Student::m_total = 10;
```

**初始化时可以赋初值，也可以不赋值。**如果不赋值，那么会被默认初始化为 0。全局数据区的变量都有默认的初始值 0，而动态数据区（堆区、栈区）变量的默认值是不确定的，一般认为是垃圾值。

4) 静态成员变量既**可以通过对象名访问，也可以通过类名访问**，但要**遵循 private、protected 和 public 关键字的访问权限限制**。当通过对象名访问时，对于不同的对象，**访问的是同一份内存**。

## 4.6 打造一个Iterator Class

## 4.7 合作关系必须建立在友谊的基础上

## 4.8 实现一个copy assignment Operator

## 4.9 实现一个function object

## 4.10 重载iostream运算符

## 4.11 指针，指向Class Member Function

>  声明一个函数指针：
>
> ```cpp
> void (num_sequence::*pm)(int)=0;
> ```
>
> 指向num_sequence的member function，后者的返回类型必须是void，且只接受int参数。pm的初始值为0，表示它目前不指向任何member function



> 在调用Pointer to Class Member Function时，必须通过该类的对象。
>
> ```cpp
> num_sequence ns;			// 类
> num_sequenc* pns=&ns;
> PtrType pm=&num_sequence::fibonacci;	// 指向类成员函数的函数指针
> 
> // 通过ns调用 pm
> (ns.*pm)(pos)
> // 通过pns调用 pm 
> (pns->*pm)(pos)
> ```
>
> 



