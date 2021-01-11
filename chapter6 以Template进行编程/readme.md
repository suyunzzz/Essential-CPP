<!--
 * @Author: your name
 * @Date: 2021-01-05 10:54:05
 * @LastEditTime: 2021-01-05 11:29:53
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \chapter6\chapter6.md
-->
# 以Template进行编程

## 6.3 Template类型参数的处理

1、在类成员函数传递参数的时候，建议都是将参数看为class类型，使用`by reference`传递。
这个样对于传递class成员时，就避免了因此数据拷贝

2、在constructor函数定义中，我选择在member initialization中对为每个类型参数进行初始化操作：
```cpp
template <typename valType>
inline BTnode<valType>::
BTnode(const valType& val)
:_val(val)
{
    _cnt = 1;
    _lchild = _rchild = 0;
}
```

而不是选择在constructor函数体内部进行：
```cpp
template <typename valType>
inline BTnode<valType>::
BTnode(const valType& val)
{
     // 不建议这样做，因为其可能是class类型
    _val=val; 

     // 可以，因为他们一定是内置类型
    _cnt = 1;
    _lchild = _rchild = 0;
}
```

如果传入了参数是一个class类型，那么在constructor中会有以下两个操作：

1. class的默认**构造函数**会被调用，生成成员变量`_val`，
2. 函数体内部会适应**copy assignment**将val复制给_val。

但是如果我们选择第一种方式，只需要调用一个步骤就能完成：以**copy constructor**将val复制给_val。

综上，我们应该注意：

1. 按引用传递
2. 在constructor中，在初始化列表中就完成对成员变量的初始化工作

---


下面这个例子比较这两种方式：

```cpp
/*
 * @Author: your name
 * @Date: 2021-01-05 10:39:00
 * @LastEditTime: 2021-01-05 11:28:29
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \chapter6\study_6_3.cpp
 */
#include <iostream>
using namespace std;

class BaseA
{

public:
    

    BaseA()
    {
        printf("constructor of BaseA\n");
    }

    BaseA(const BaseA & other)
    {
        printf("copy constructor of BaseA\n");
    }

    ~BaseA() {
        printf("destructor of BaseA\n");
    }
 
    void
    operator=(const BaseA& a)
    {
        // *this = a;
        printf("copy assignment of BaseA\n");

        // return *this;
    }

    

};  // class BaseA

class BaseB
{
public:

    BaseB(){
        printf("defalut constructor of BaseB\n");
    }

    BaseB(const BaseA& Ba):_Ba(Ba)
    {
        // _Ba = Ba;
        printf("constructor of BaseB\n");
    }

    ~BaseB()
    {
        printf("destructor of BaseB\n");
    }



private:
    BaseA _Ba;
};      // class BaseB



int main(int argc, char const *argv[])
{
    BaseA a;
    BaseB b(a);
    return 0;
}

/* 
1 构造函数初始化列表
constructor of BaseA
copy constructor of BaseA
constructor of BaseB
destructor of BaseB
destructor of BaseA
destructor of BaseA
 */

/*
2 不使用构造函数的初始化类别，直接在构造函数体内进行赋值
constructor of BaseA
constructor of BaseA
copy assignment of BaseA
constructor of BaseB
destructor of BaseB
destructor of BaseA
destructor of BaseA
 */

```



## 6.5 一个以Function Template 完成的Output运算符

这里用到了外部函数调用类内的private函数，但是private成员（函数和变量）只能在类内进行调用和访问。对于这个问题，一般我们有两种方案解决；

1、通过调用public，在public函数内部进行调用private函数

2、将该外部函数声明为类的`friend函数`

下面给出这两种情况的例子：

```cpp
/*
 * @Author: your name
 * @Date: 2021-01-05 15:05:39
 * @LastEditTime: 2021-01-05 15:20:51
 * @LastEditors: Please set LastEditors
 * @Description: 测试类的private调用
 * @FilePath: \chapter6\study__6_5.cpp
 */

/* 
在类的外部调用类的private：
    法1：声明为friend
    法2：通过调用public函数调用private
 */


#include <iostream>
class A
{
    // 法1 通过声明友元函数
    friend void print(const A& a);

public:
    void func1() const
    {
        printf("func1\n");
        // func2();                // 法2：通过public函数调用private函数
    }

private:
    void func2() const
    {
        printf("func2\n");
    }

};  // class A

// 友元函数在使用之前需要在类的外部进行声明（不是类内部声明为友元的那一次）
void print(const A& a);

void print(const A& a)  // const 对象只能访问const成员函数
{
    a.func1();
    a.func2();      // 调用类内部的private
}

int main(int argc, char const *argv[])
{
    A a;
    // a.func1();
    // a.func2();

    print(a);
    
    
    return 0;
}
```

## 6.8 MemberTemplate Function

将member function设置为template形式

```cpp
/*
 * @Author: your name
 * @Date: 2021-01-05 15:53:59
 * @LastEditTime: 2021-01-05 16:44:07
 * @LastEditors: Please set LastEditors
 * @Description: P187 Member function template，将类成员函数设置为函数模板
 * @FilePath: \chapter6\study_6_8.cpp
 */

#include <iostream>
#include <fstream>


using namespace std;

template <typename OutStream>
class PrintIt
{

public:
    PrintIt(OutStream &os):_os(os)
    {
        
    }

    template <typename elemType>
    void print(const elemType & elem,char delimiter = '\n')
    {
        _os<<elem<<delimiter;
    }




private:
    OutStream& _os;

};   //class PrintIt


int main(int argc, char const *argv[])
{
    ofstream of("6-8.txt");          // 创建一个ofstream对象
    PrintIt<ostream> PI(of);                // ofstream继承了ostream，因此可以直接使用
    PI.print(5,'\n');               
    return 0;
}
```

## test 6.2 



### 遇到的问题

按照essential c++第247页声明友元函数（答案是将`.h`文件和`.cpp`文件分开写的，我是写一块了，可能就是这个差异导致了我的错误），发生如下错误

**报错如下：大致就是友元函数是非模板函数**

```bash
PS C:\Users\11604\Desktop\Essential-CPP\chapter6> g++ .\test6_2.cpp -o test6_2 -g
                                                                                            ^
.\test6_2.cpp:19:92: note: (if this is not what you intended, make sure the function template has already been declared and add <> after the function name here)
.\test6_2.cpp:20:92: warning: friend declaration 'Matrix<elemType> operator*(const Matrix<elemType>&, const Matrix<elemType>&)' declares a non-template function [-Wnon-template-friend]
     friend Matrix<elemType> operator*(const Matrix<elemType>& m1,const Matrix<elemType>& m2);
                                                                                            ^
.\test6_2.cpp:21:70: warning: friend declaration 'std::ostream& operator<<(std::ostream&, const Matrix<elemType>&)' declares a non-template 
function [-Wnon-template-friend]
     friend ostream& operator<<(ostream & os,const Matrix<elemType>& m);
```

参考：https://stackoverflow.com/questions/4660123/overloading-friend-operator-for-template-class

作者给出了3种方法，目前只看懂了第一种。。

#### 解决方法1

在声明友元时，将友元的模板符号换一个新的，代表不仅仅能接受class的模板类型，如下：

```cpp
template <typename elemType>
class Matrix
{
    // 声明友元
    // 换一个符号表示
    template <typename U>
    friend Matrix<U> operator+(const Matrix<U>& m1,const Matrix<U>& m2);
    template <typename U>
    friend Matrix<U> operator*(const Matrix<U>& m1,const Matrix<U>& m2);
    template <typename U>
    friend ostream& operator<<(ostream & os,const Matrix<U>& m);
    .
    .
    .
};	// class Matrix
```

### 答案

```cpp
/*
 * @Author: your name
 * @Date: 2021-01-05 17:16:39
 * @LastEditTime: 2021-01-05 21:45:22
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \chapter6\test6_2.cpp
 */
#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <typename elemType>
class Matrix
{
    // 解决方法1
    // 声明友元
    template <typename U>
    friend Matrix<U> operator+(const Matrix<U>& m1,const Matrix<U>& m2);
    template <typename U>
    friend Matrix<U> operator*(const Matrix<U>& m1,const Matrix<U>& m2);
    template <typename U>
    friend ostream& operator<<(ostream & os,const Matrix<U>& m);



public:
    // 构造函数
    Matrix(int rows,int cols):_rows(rows),_cols(cols)
    {
        _size = rows*cols;
        _pmatrix = new elemType[_size];
        for(int i=0;i<_size;i++)
        {
            _pmatrix[i] = elemType();
        }
    }


    // 析构函数
    ~Matrix()
    {
        delete [] _pmatrix;
    }

    // 拷贝构造函数
    Matrix(const Matrix<elemType>& m)
    {
        _rows = m._rows;
        _cols  = m._cols;
        _size = _rows*_cols;
        _pmatrix = new elemType[_size];
        for(int i = 0; i < _size;i++)
        {
            _pmatrix[i] = m._pmatrix[i];
        }
    }


    // 拷贝赋值函数
    Matrix<elemType> operator=(const Matrix<elemType>& m)
    {
        // 先检验当前对象和参数是否为同一地址
        if(this != &m)
        {
            delete[] _pmatrix;
            _rows = m._rows;
            _cols = m._cols;
            _size = _rows*_cols;
            _pmatrix = new elemType[_size];

            for(int i=0; i<_size; i++)
            {
                _pmatrix[i] = m._pmatrix[i];
            }

        }

        return *this;


    }

    // 查看当前矩阵的信息
    int rows() const
    { return _rows;}

    int cols() const
    { return _cols;}

    int size() const
    { return _size;}

    // 获取矩阵元素
    elemType operator()(int row,int col) const
    { return _pmatrix[row*_rows+col];}

    elemType& operator()( int row, int col)  
    {
        return _pmatrix[row*_rows+col];
    }

    void operator+=( const Matrix& m)
    { 
        if((_rows==m.rows) && (_cols==m.cols))
        {
            for(int i=0; i<_size;i++)
            {
                _pmatrix[i]+=m._pmatrix[i];
            }
        }
    } 

    ostream& print(ostream& os= cout)
    {
        os<<"----------------\n";
        os<<(*this)<<"\n";
        os<<"----------------\n";
        return os;
    }




private:
    elemType* _pmatrix;
    int _size;
    int _rows;
    int _cols;
    elemType _max;
    elemType _min;

};  // class matrix

template <typename elemType>
ostream& operator<<(ostream & os,const Matrix<elemType>& m);

template <typename elemType>
Matrix<elemType> operator+(const Matrix<elemType>& m1,const Matrix<elemType>& m2);

template <typename elemType>
Matrix<elemType> operator*(const Matrix<elemType>& m1,const Matrix<elemType>& m2);



template <typename elemType>
ostream& operator<<(ostream & os,const Matrix<elemType>& m)
{
    for(int i=0;i<m._rows;i++)
    {
        for(int j = 0;j<m._cols;j++)
        {
            cout<<m._pmatrix[i*m._rows+j];
        }
        cout<<"\n";
    }
    return os;
}

template <typename elemType>
Matrix<elemType> operator+(const Matrix<elemType>& m1,const Matrix<elemType>& m2)
{
    // cout<<"operator+\n"
    //     <<"m1:"<<m1<<"\n---\n"
    //     <<"m2:"<<m2<<"\n";
    
    if((m1._cols==m2._cols) && (m1._rows==m2._rows))
    {
        Matrix<elemType> new_matrix(m1);
        for(int i = 0; i < m1._size; i++)
        {
            new_matrix._pmatrix[i]=m1._pmatrix[i]+m2._pmatrix[i];
            // cout<<"new_matrix._pmatrix[i]: "<<new_matrix._pmatrix[i]<<endl;
        }

        // cout<<"new_matrix:\n"<<new_matrix<<endl;
        return new_matrix;
    }

    printf("[ERROR] dimension mismatch!\n");
    return m1;
}

template <typename elemType>
Matrix<elemType> operator*(const Matrix<elemType>& m1,const Matrix<elemType>& m2)
{
        
    if((m1._cols==m2._cols) && (m1._rows==m2._rows))
    {
        Matrix<elemType> new_matrix(m1);
        for(int i = 0; i < m1._size; i++)
        {
            new_matrix._pmatrix[i]=m1._pmatrix[i]*m2._pmatrix[i];
        }
        return new_matrix;
    }

    printf("[ERROR] dimension mismatch!\n");
    return m1;

}



int main(int argc, char const *argv[])
{
    Matrix<int> max_a(3,5);
    printf("max_a:\n");
    max_a.print();

    max_a(0,0)=1;
    max_a(2,2)=2; 
    printf("max_a:\n");
    cout<<max_a<<endl;

    Matrix<int> mat_b(3,5);
    printf("mat_b:\n");
    mat_b.print();

    mat_b = max_a+max_a;
    printf("mat_b:\n");
    mat_b.print();

    Matrix<int> mat_c(max_a);
    printf("mat_c:\n");
    mat_c.print();
    
    mat_c = mat_b*mat_c;
    printf("mat_c:\n");
    mat_c.print();
    
    
    

    // Matrix<double> max__a(3,5);
    // max__a.print();
    return 0;
}
```



