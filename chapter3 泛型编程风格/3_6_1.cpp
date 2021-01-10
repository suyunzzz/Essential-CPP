/*
 * @Author: your name
 * @Date: 2020-11-30 10:43:58
 * @LastEditTime: 2020-11-30 15:51:37
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \chapter3\.vscode\3_6_1.cpp
 */

#include "headfile.h"

// P83
vector<int> less_than_val(const vector<int>& vec,int val){
    vector<int> res;
    for(auto iter =vec.begin();iter!=vec.end();iter++){
        if(*iter<val){
            res.push_back(*iter);
        }
    }

    return res;
}

// 作为函数指针传入函数filter_val()
bool less_than_val(int a,int b){
    return a<b?true:false;
}

bool greater_than_val(int a,int b){
    return a>b?true:false;
}

// 找到vector中小于val的元素，返回一个vector
vector<int> filter_val(const vector<int>& vec,int val,bool (*p_f)(int,int)){
    vector<int> result;
    for(auto iter =vec.begin();iter!=vec.end();iter++){
        if(p_f(*iter,val)){
            result.push_back(*iter);
        }
        
    }

    return result;
}



// 统计val在vector出现的次数
int count_occurs(const vector<int> &vec,int val){
    int count=0;
    auto iter = vec.begin();
    while((iter=find(iter,vec.end(),val))!=vec.end()){      // find函数，如果查到指定的值，那么指向检索值，否则直接指向end()，vec.end()实际上指向的是容器的最后一个元素的下一个位置
        iter++;
        count++;
    }

    return count;
}

// P87 filter函数
// function object、adapter
vector<int> filter(const vector<int>& vec,int val,less<int> lt)        // less<int>& lt 代表function object 在functional头文件中
{
    vector<int> result;
    for(auto iter=vec.begin();iter!=vec.end();)
    {
        iter=find_if(iter,vec.end(),bind2nd(lt,val));             // 传入一个范围[start,end)，还有一个条件，这里选择的是less_than。为了方便使用binder adapter绑定第二个参数
        if(iter!=vec.end())
        {
            result.push_back(*iter);
            iter++;                     
            
        }
        // else
        // {
        //     break;
        // }
    }
    return result;
}

// P88 对filter制作为函数模板
template<typename InputIterator,typename OutputIterator,
        typename ElementType,typename Comp>
// OutputIterator
void
filter_temp(InputIterator firstIter,InputIterator lastIter,OutputIterator outIter,ElementType val,Comp comp){
    for(auto iter = firstIter;iter!=lastIter;){
        if((iter=find_if(iter,lastIter,bind2nd(comp,val)))!=lastIter){
            cout<<"Find value: "<<*iter<<endl;
            (*outIter) =( *iter);
            outIter++;
            iter++;
        }
        // else
        // return;
    }
}

// 找到小于val的数字
vector<int> sub_vec(const vector<int>& vec,int val)
{
    vector<int> local_vec(vec);
    sort(local_vec.begin(),local_vec.end());

    auto iter=find_if(local_vec.begin(),local_vec.end(),not1(bind2nd(less<int>(),val)));        
    
    local_vec.erase(iter,local_vec.end()); 

    return local_vec;
}

// 将sub_vec模板化
template<typename T>
vector<T>
sub_vec_temp(const vector<T>& vec,T val){
    // copy 
    vector<int> local_vec(vec);
    sort(local_vec.begin(),local_vec.end());

    auto iter=find_if(local_vec.begin(),local_vec.end(),bind2nd(greater<T>(),val));

    local_vec.erase(iter,local_vec.end());
    
    return local_vec;
}

int main(int argc, char const *argv[])
{
    int a[]={1,1,2,3,5,8,13,21};
    vector<int> vec(a,a+sizeof(a)/sizeof(a[0]));
    vector<int> res=less_than_val(vec,10);      // P83

    cout<<res<<endl;

    cout<<"-------------------------"<<endl;
    res=filter_val(vec,10,greater_than_val);    // 接收函数指针
    cout<<res<<endl;

    cout<<"------------------------------"<<endl;
    int count=count_occurs(vec,1);              // 统计出现的次数
    cout<<count<<endl;


    cout<<"------function object---------"<<endl;   // function object P87
    res=filter(vec,10,less<int>());
    cout<<res<<endl;

    cout<<"------function object+template,vector---------"<<endl;   // function object P87
    vector<int> res2(6);
    filter_temp(vec.begin(),vec.end(),res2.begin(),10,less<int>());
    cout<<res2<<endl;

    cout<<"------function object+template,array---------"<<endl;   // function object P87
    int b[8];
    filter_temp(a,a+sizeof(a)/sizeof(a[0]),b,10,greater<int>());
    for(int i=0;i<8;i++)
    {
        cout<<b[i]<<" ";
    }


    cout<<"\n==============sub_vec_temp=================="<<endl;
    res=sub_vec_temp(vec,10);
    cout<<res<<endl;
    return 0;
}
