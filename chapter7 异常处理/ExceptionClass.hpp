/*
 * @Author: your name
 * @Date: 2021-01-11 11:01:40
 * @LastEditTime: 2021-01-11 14:55:41
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \chapter7 异常处理\ExceptionClass.cpp
 */
#include<exception>
#include<string>
#include<stdexcept>
using namespace std;

class StackExceptions : public logic_error
{

public:
    StackExceptions(const char* what):logic_error(what)
    { }
    
    // virtual const char* what() const
    // { return _what.c_str();}


protected:
    string _what;



};  // class StackExceptions


class PopOnEmpty : public StackExceptions
{
public:
    PopOnEmpty():StackExceptions("[Exception] Pop on Empty Stack!\n")
    {}
};      // class PopOnEmpty


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