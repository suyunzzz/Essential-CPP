/*
 * @Author: your name
 * @Date: 2020-12-01 12:33:48
 * @LastEditTime: 2020-12-01 20:43:59
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \chapter4\test4_1_ref.cpp
 */
#include "Stack_ref.h"

int main(int argc, char const *argv[])
{
    stack st;
    string str;
    while(cin >> str && !st.full()){
        st.push(str);

    }

    if(st.empty()){
        cerr << "Empty"<<endl;
        return 0;    
    }

    st.peek(str);
    
    cout <<st<<endl;

    // while(!st.empty()){
    //     if(st.pop(str))
    //     {
    //         cout<<st<<endl;
    //     }
    // }

    cout<<"size: "<<st.size()<<endl;
    
    cin.clear();        // 清除end-of-file的设定
    
    while(1)
    {
        cout<<"\n\nPlease enter a string: ";
        cin>>str;
        if(str=="q" || str=="Q")
        {
            // break;
            return 0;
        }
        if( st.find(str))
        {
            cout<<"Found "<<str<<endl;
            cout<<st.count(str)<<" times"<<endl;
        }
        else cout<<"No found "<<str<<endl;


    }

    return 0;
}
