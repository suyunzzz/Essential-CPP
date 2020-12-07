/*
 * @Author: your name
 * @Date: 2020-12-07 19:25:03
 * @LastEditTime: 2020-12-07 20:19:49
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \chapter4\test4_4.cpp
 */
#include"test4_4.h"

// static成员 外部定义
// type class::member 
// int UserProfile::_guesses
map<string,UserProfile::uLevel> UserProfile::_level_map;     // static 成员定义

inline double
UserProfile:: guess_average() const
{
    return _guesses?double(_correct_guesses)/double(_guesses)*100:0.0;
}

ostream & operator<<(ostream & os,const UserProfile &rhs)
{
    os<<rhs.login()<<" "
    <<rhs.level()<<" "
    <<rhs.login_count()  << " "
    <<rhs.guess_count()<<" "
    <<rhs.guess_correct<<" "
    <<rhs.guess_correct<<endl;
    
    return os;
}



inline UserProfile::UserProfile(string login,uLevel level)
    :_login(login),_user_level(level),_times_logged(1),_guesses(0),
    _correct_guesses(0)   
{

}

#include <cstdlib>
inline UserProfile::UserProfile()
    :_login("guest"),_user_level(Beginner),
    _times_logged(1),_guesses(0),_correct_guesses(0)
{
    static int id=0;
    char buffer[16];
    _itoa(id++,buffer,10);      // 整数转为对应的ASCII字符形式
    _login+=buffer;
}

inline bool
UserProfile::operator==(const UserProfile& u)
{
    if(_login==i._login && _user_name==u._user_name)
        return true;
    return false;
    
}

inline bool 
UserProfile::operator!=(const UserProfile& u)
{
    return !(*this==u);
}

inline string UserProfile::level() const{ 
    static string _level_table[] = {"Beginner","Intermediate","Advanced","Guructor"}
    return _level_table[_user_level];
}

// static成员函数
void UserProfile::init_level_map()
{
    _level_map["Beginner"] = Beginner;
    _level_map["Intermediate"] = Intermediate;
    _level_map["Advanced"] = Advanced;
    _level_map["Guructor"] = Guructor;
    
}

void UserProfile::reset_level(const string& elem)
{
    map<string,uLevel>::iterator it;
    if(_level_map.empty()){
        init_level_map();
    }

    _user_level=((it= _level_map.find(elem))!=_level_map.end())?it->second:Beginner;
}

istream& operator>>(istream& is,UserProfile& rhs)
{
    string login,level;
    is>>login >>level;

    int count,gcount,gcorrect;
    is>>count >>gcount >>gcorrect;

    rhs.reset_login( login);
    rhs.reset_level(level);
    rhs.reset_count(count);
    rhs.reset_guess_count(gcount);
    rhs.reset_correct_count(gcorrect);

    return is;

}









