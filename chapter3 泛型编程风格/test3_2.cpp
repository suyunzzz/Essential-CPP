/*
 * @Author: your name
 * @Date: 2020-11-30 19:35:22
 * @LastEditTime: 2020-11-30 20:42:47
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \chapter3\test_3_1.cpp
 */
#include "headfile.h"
#include <iterator>
#include <set>
#include <map>
#include <string>
#include <fstream>
#include <algorithm>



// 将文件中的字母读入到vector
void read_file(string filename,vector<string>& text)
{
    ifstream ifs(filename);

    istream_iterator<string> is(ifs);
    istream_iterator<string> eof;
    copy(is,eof,back_inserter(text));
}

// 将vector读入到map
void vector2map(vector<string>& text,map<string,int>& dict,const set<string>& except_words)
{
    for(auto it = text.begin();it != text.end();it++){
        if(except_words.count(*it))         // 包含在set中
        {
            continue;
        }

        else                                // 不屏蔽
        {
            dict[*it]++;
        }
    }
}

ostream& operator<<(ostream& os,map<string,int>& dict)
{
    os<<"-----------------"<<endl;

    for(auto it = dict.begin();it != dict.end();it++){
        os<<it->first<<", "<<it->second<<endl;
    }

    os<<"-----------------"<<endl;

    return os;
}

bool is_exists(const vector<string>& vec,string val)
{
    if(find(vec.begin(),vec.end(),val)!=vec.end())
    {
        return true;
    }
    return false;
}

// 定义一个function object，实际上就是定义一个class，内部仅仅有一个运算符重载，返回bool如：less<int>()
class shortThan
{
public:
    bool operator()(const string& a,const string& b)
    {
        return a.size()<b.size()?true:false;
    }
};  // class shortThan


int main(int argc, char const *argv[])
{
    vector<string> text;
    string a[]={"a","an","or","the","and","but"};
    set<string> except_words(a,a+6);
    // vector<string> text;
    map<string,int> mydict;
    
    // 读取文件到vector
    read_file("3_10.txt",text);

    // 同样长度，按照字母先后顺序排序
    sort(text.begin(),text.end());
    stable_sort(text.begin(),text.end(),shortThan());   // a d g h i j l m y cs fd or cccb ksss eedaaa

    // // 直接按照字母长度排序
    // sort(text.begin(),text.end(),shortThan());       // a d g h i y j l m cs or fd cccb ksss eedaaa

    cout<<text<<endl;

/*     // 判断某个字母是否出现在vector中
    cout<<"Please enter a word:   ";
    string test_word;
    cin>>test_word;
    if(is_exists(text,test_word))
    {
        cout<<test_word<<" exist"<<endl;
    }
    else
    {
        cout<<test_word<<" not exist"<<endl;
    }

    vector2map(text,mydict,except_words);

    cout<<mydict<<endl;

    // 统计输入的在map中出现的次数
    while(1) {
        cout<<"Press Q to Exit! "<<endl;
        cout<<"Please enter a word: ";
        cin>>test_word;
        if(test_word!="Q" && test_word!="q")
        {
            if(mydict[test_word])
            {
                cout<<"Found "<<test_word<<" "<<mydict[test_word]<<" times"<<endl;
            }
            else
            {
                cout<<"Not Found "<<test_word<<endl;
            }
        }
        else            // Q exit
        {
            return 0;
        }

    }

 */
    return 0;
}
