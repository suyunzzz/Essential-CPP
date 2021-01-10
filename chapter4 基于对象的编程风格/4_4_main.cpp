/*
 * @Author: your name
 * @Date: 2020-12-07 20:20:01
 * @LastEditTime: 2020-12-07 20:26:30
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \chapter4\4_4_main.cpp
 */
#include "test4_4.h"

int main(int argc, char const *argv[])
{
    UserProfile anon;
    cout<<"anon: \n"<<anon<<endl;

    UserProfile anon_too;
    cout<<"anon_too:\n"<<anon_too<<endl;

    UserProfile anna("AnnaL",UserProfile::Guructor);
    cout<<"anna:\n"<<anna<<endl;
    anna.bump_login_count();
    anna.bump_correct_count(10);
    anna.bump_guess_count(12);
    cout<<"anna:\n"<<anna<<endl;

    cout<<"\n-------------\n"<<endl;
    cin>>anna;
    cout<<"anna:\n"<<anna<<endl;
    return 0;
}
