/*
 * @Author: your name
 * @Date: 2020-12-07 19:10:01
 * @LastEditTime: 2020-12-07 19:35:42
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \chapter4\test4_4.h
 */
#pragma once

#include <iostream>
#include <map>
#include <string>

using namespace std;

class UserProfile{

public:
    enum uLevel{ Beginner,Intermdiate,Advanced,Guructor };
    UserProfile(string login,uLevel = Beginner);
    UserProfile();


    bool operator==(const UserProfile& user);
    bool operator!=(const UserProfile& user);

    // 以下函数用来读取数据
    string login() const{return _login;}
    string user_name() const{return _user_name;}
    int login_count() const{return _times_logged;}
    int guess_count() const{return _guesses;}
    int guess_correct() const{return _correct_guesses;}
    double guess_average() const;
    string level() const;


    // 写入数据
    void reset_login(const string& elem){_login = elem;}
    void user_name(const string& elem){_user_name = elem;} 

    void reset_level(const string& elem);
    void reset_level(const uLevel& elem){_user_level = elem;}

    void reset_login_count(int val){_times_logged = val;}
    void reset_guess_count(int val){_guesses = val;}
    void reset_correct_count(int val){_correct_guesses = val;}

    void bump_login_count(int val=1){_times_logged+=val;}
    void bump_guess_count(int val=1){_guesses+=val;}
    void bump_correct_count(int val=1){_correct_guesses+=val;}


private:
    string _login;
    string _user_name;
    int  _times_logged;
    int _guesses;
    int _correct_guesses;
    uLevel _user_level;

    static map<string,uLevel> _level_map;
    static void init_level_map();
    static string guest_login();

}; // class UserProfile