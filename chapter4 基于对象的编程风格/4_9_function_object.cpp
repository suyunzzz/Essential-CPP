/*
 * @Author: your name
 * @Date: 2020-12-02 19:28:24
 * @LastEditTime: 2020-12-02 19:51:48
 * @LastEditors: Please set LastEditors
 * @Description: P126
 * @FilePath: \chapter4\4_9_function_object.cpp
 */
#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>

using namespace std;

// 创建一个class object
class lessThan
{
public:
    lessThan(int val):_val(val){}
    int comp_val() const { return _val;}

    void comp_val(int val){_val = val;}

    bool operator()(int comp_val)const {return comp_val<_val;}


private:
    int _val;

}; // class lessThan

// 统计小于val的元素的个数
int count_less_than(const std::vector<int>& vec,int val)
{   
    lessThan lt(val);
    int count = 0;
    for(auto it=vec.begin();it!=vec.end();it++)
    {
        if(lt(*it)) 
        {
            count++;
        }
    }

    return count;
    
}

// 打印小于val的元素
void print_less_than(const std::vector<int >& vce,int val,ostream& os=cout){
    // create function object
    lessThan lt(val);

    vector<int>::const_iterator iter=vce.begin();
    while(( iter= find_if(iter,vce.end(),lt))!=vce.end() )
    {
        os<<" "<<*iter<<" ";
        iter++;
    }

    cout<<"\n\nend iter--> "<<*iter<<" , "<<"iter: "<<&(*iter)<<endl;
    cout <<"vce.end()--> "<<*vce.end()<<" , "<<"vee.end(): "<<&(*vce.end())<<endl;

    os<<endl;

}


int main(int argc, char const *argv[])
{
    int a[]={1,2,3,4,5,6,7};
    vector<int> vec(a,a+sizeof(a)/sizeof(a[0]));
    int num=count_less_than(vec,5);

    cout <<"num :"<<num<<endl;
    print_less_than(vec,5);
    return 0;
}
