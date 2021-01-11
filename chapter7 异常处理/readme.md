# 异常处理

*c++的异常处理机制就是完成**通知任务***

## 7.1 抛出异常

何谓抛出异常，所谓异常（exception）是某种对象。最简单的异常对象可以设计为整数或者字符串：

> throw 42;
>
> throw "panic: no buffer!"

大部分时候，抛出的异常都属于一个特定的异常类（也许形成一个继承体系）

## 7.2 捕获异常

我们可以利用一连串的`catch`子句来捕获被抛出的异常对象。`catch`子句由三部分组成：关键字catch、小括号内的一个类型或对象、大括号内的一组语句（用以处理异常）。

异常对象的类型会被拿过来逐一地和每个catch子句比对，如果类型符合，那么该catch子句的内容便会被执行。

在通过所有catch子句以后，由正常程序重新接手。

- 重新抛出异常

  重新抛出异常时，只需写下关键字throw即可。**它只能出现在catch子句中**。它会将捕获的异常对象再一次抛出，并由另一个类型吻合的catch子句接手处理。

  ```cpp
  catch(iterator_overflow &iof)
  {
      log_message(iof.what_happend());
      
    	// 重新抛出异常，令另一个catch子句接手处理
      throw;
  }
  ```

  

- 捕获任何异常

  如果我们想要捕获任何类型的异常，可以使用一网打尽（catch-all）的方式。只需在异常声明部分指定省略号（...）即可，像这样：

  ```cpp
  catch(...)
  {
      log_message("ecxception of unknow type");
    	// 清理（clean up）然后退出......
  }
  ```


## 7.3 提炼异常

catch子句应该和try子句相应而生。try块以关键字try作为开始，然后是大括号内的一连串程序语句。catch子句放在try块的末尾，这表示如果try块内有任何异常发生，便由接下来的catch子句加以处理。



在try块内该放置哪些语句，在try该放置哪些语句，这些都是程序员的职责。**如果某一语句有可能引发异常，而他不位于try块内，那么该异常保证不会在此函数内被捕获处理。**---并不是每一个函数都必须处理每一个可能发生的异常。

> 初学者常犯的错误是，将C++异常和segmentation或是bus error这类硬件异常混淆在一起。面对任何一个被抛出的C++异常，你都可以在程序某处找到一个相应的throw表达式（有些深藏在标准库中）

## 7.4 局部资源管理

**动机**

不管发生不发生异常，都会对申请的内存进行释放

**方法**

使用一个类



auto_ptr将deference运算符和arrow运算予以重载，其方式就像4.6节的iterator class 那样。这使得我们得以像使用一般指针一样地使用auto_ptr对象。例如：

```cpp
auto_ptr<string> aps(new string("vermeer"));
string* ps = new string("vermeer");
```



## 7.5 标准异常

如果new表达式无法从程序的空闲空间（free store）分配足够多的内存，它会抛出bad_alloc异常对象，例如：

```cpp
vector<string>* 
    init_text_vector(ifsream& infile)
{
    vector<string>* ptext = 0;
    try{
        ptext = new vector<string>;
    }
    
    catch(bad_alloc)
    {
        cerr<<"ouch. heap memory exhausted!\n";
        // 清理（clean up）并退出
    }
    return ptext;
}
```





标准库定义了一套异常类体系（exception class hierarchy），其根部是名为`exception`的抽象基类。`exception`声明有一个`what()`虚函数，会返回一个`const char*`，用以表示被抛出异常的文字描述。

`bad_alloc`派生自`exception`基类，他有自己的`what()`，Visual C++所提供的的bad_alloc，其`what()`函数会产生"bad alloction"这样的信息。

我们也可以将自己编写的`iterator_overflow`继承于`exception`基类之下。首先必须包含标准头文件`exception`，而且必须提供自己的`what()`:

```cpp
#include <exception>

class iterator_overflow:public exception{
public:
    iterator_overflow(int index,int max):_index(index),_max(max)
    {
        
    }
    
    int index(){return _index;}
    int max(){return _max;}
    
    // 重写exception::what()函数
    const char* what() const override;
    
private:
    int _index;
    int _max;
    
}
```

将iterator_overflow融入标准的exception类体系的好处就是，他可以被任何“打算捕获抽象基类exception”的程序代码所捕获，包括先前我介绍的iterator_overflow时所写的代码。这意味着我们不必修改原有程序的代码，就可以让那些程序认识这个class。我们也不必再用一网打尽（*catch-all*）的方式来捕获异常了。

下面这个catch子句：

```cpp
catch(const exception& ex)
{
    cerr<<ex.what()<<endl;
}
```

会捕获exception的所有派生类。

> 简单理解就是多态，基类引用指向派生类对象





**字符串转换函数**

- 将int等转换为相对应的字符串

  > 通过ostringstream.str()先转为string，再通过string.c_str()将string转换为C风格的字符串

```cpp
#include<sstream>
#include<string>


ostringstream ex_msg;
string msg;

ex_msg<<"Internal error:current index "
      <<_index<<"exceeds maximum bound: "
      <<_max;

// 萃取出string对象
msg = ex_msg.str()
   
// 萃取出const char对象
return msg.c_str();
```

- 将非字符串数据（例如，整数值或内存地址）的字符串表示转换为其实际类型

  > 简单来讲就是将字符串中的int类型的字符串表示转换为其实际类型（int类型）

  > 使用istringstream



## 练习 7.3

代码结构

- test7_3.cpp
- Stack.h
- Stack.cpp
- ExceptionClass.cpp

### 1、异常类的创建

主要就是写两个异常类，继承自`exception`类，

`exception`类如下所示：

```cpp
  class exception
  {
  public:
    exception() _GLIBCXX_USE_NOEXCEPT { }
    virtual ~exception() _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_USE_NOEXCEPT;

    /** Returns a C-style character string describing the general cause
     *  of the current error.  */
    virtual const char*
    what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_USE_NOEXCEPT;
  };
```

我们主要工作就是在继承类中重写`what()`虚函数，如下：

>这里还是利用了`exception`这个类的`what`虚函数实现了多态

```cpp
class PushOnFull: public exception
{
public:
    PushOnFull():_what("[Exception] Push on Full Stack!\n")
    {}


    virtual const char* what() const  _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_USE_NOEXCEPT
    {
        return _what.c_str();
    }

private:
    string _what;
};      // class PushOnFull
```

---

### 2、异常的使用

在Stack.cpp中的pop和push 函数中，丢出异常，如下：

```cpp
bool
Stack::pop(elemType& elem)
{
    if(empty()) 
    throw PopOnEmpty();         // 丢出一个异常


    elem = _stack[_top--];
    _stack.pop_back();
    return true;
}

bool 
Stack::push(elemType& elem)
{   
    if(full()) throw PushOnFull();          // 丢出一个异常
    _stack.push_back(elem);     
    _top++;
    return true;

}
```

在test7_3.cpp中，捕获异常，如下：

> 这里就是使用基类引用指向派生类对象

```cpp
    elemType elem;
    try{
        s.pop(elem);
    }
    catch(const exception& ex)
    {
        printf("%s\n",ex.what());
        // return 0;
    }
```





