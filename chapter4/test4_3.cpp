/*
 * @Author: your name
 * @Date: 2020-12-02 21:10:16
 * @LastEditTime: 2020-12-07 18:53:42
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \chapter4\test4_3.cpp
 */
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class test4_3
{
public:
    static string program_name()  { return _program_name;}
    static string version_stamp()  { return _version_stamp;}
    static int version_number()  { return _version_number;}
    static int tests_run() { return _tests_run;}
    static int tests_passed() { return _tests_passed;}

    static void program_name(const string & elem){_program_name=elem;}
    static void version_stamp(const string & elem){_version_stamp=elem;}
    static void version_number(int & elem){_version_number=elem;}
    // static void tests_run(int elem) {_tests_run=elem;} 
    static void test_passed(int elem){_tests_passed=elem;}
    
private:
    static string _program_name;
    static string _version_stamp;
    static int _version_number;
    const   static int _tests_run=9;        // const static 成员
    static int _tests_passed;

}; // class test4_3

string test4_3::_program_name;
int test4_3::_tests_passed;

int main(int argc, char const *argv[])
{
    
    test4_3 a;
    a.program_name("a");
    a.test_passed(1);
    string res=a.program_name();
    cout<<"res a : "<<res<<endl;
    cout<<"a._tests_passed: "<<a.tests_passed()<<endl;

    test4_3 b;
    string resb=b.program_name();
    cout<<"res b : "<<resb<<endl;

    cout<<" test4_3::program_name() : "<< test4_3::program_name();  


    cout<<"\nconst   static int _tests_run: "<<b.tests_run()<<endl;
    return 0;
}
