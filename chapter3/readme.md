<!--
 * @Author: your name
 * @Date: 2020-11-27 19:27:31
 * @LastEditTime: 2020-11-30 22:48:20
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \chapter3\readme.md
-->

# 第三章 泛型编程风格

## 3.1 指针的算术运算
## 3.2 了解Iterator（泛型指针）
> 指针也是一种迭代器
## 3.3 所有容器的共通操作
> begin()返回一个iterator，指向容器的第一个元素

> end()返回一个iterator，指向容器的最后一个元素的下一个位置
## 3.4 使用顺序性容器
## 3.5 使用泛型算法
> `3_5.cpp`内包含了debug包含命令行参数下的launch.json文件的编写
## 3.6 如何设计一个泛型算法
> 泛型算法：与元素类型无关、与容器类型无关、与比较操作无关

- function object
```cpp
// 定义一个function object，实际上就是定义一个class，内部仅仅有一个运算符重载，返回bool如：less<int>()
class shortThan
{
public:
    bool operator()(const string& a,const string& b)
    {
        return a.size()<b.size()?true:false;
    }
};  // class shortThan
```
## 3.7 使用Map
- first（取key）、second（取value）
- 检测map中是否含有某个key，提供三种方法
```cpp
// 直接取value值
int count=0;
if(!count= words["vwemeer"])
// vermeer不在words map中
```

```cpp
// map.find()函数，返回一个迭代器
int count=0;
map<string,int>::iterator it;
it = words.find("vwemeer");     // 返回一个iterator
if(it!= words.end())
    count=it->second;
```

```cpp
// map.count()函数，返回计数
int count=0;
string search_word("vwemeer");

if(words.count(search_word))
{
    count=words[search_word];
}
```


## 3.8 使用Set
- set.insert(value)
- set.insert(vec.begin(),vec.end())


## 3.9 如何使用Iterator Inserter
> black_inserter
## 3.10 使用iostream Iterator

> 泛型算法`copy()`接收的形参:(源文件的起点iterator，源文件的终点iterator，目标文件的iterator)
