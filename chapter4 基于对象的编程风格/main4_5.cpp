/*
 * @Author: your name
 * @Date: 2020-12-07 20:33:11
 * @LastEditTime: 2020-12-07 22:17:58
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \chapter4\main4_5.cpp
 */

#include "test4_5.h"

int main(int argc, char const *argv[])
{
    Matrix m;
    cout << "m:\n"<< m << endl;

    elemType ar[16]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    Matrix m2(ar);
    cout << "m2:\n"<<m2<<endl;


    elemType ar3[]={0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1.0,1.1,1.2,1.3,1.4,1.5,1.6};
    Matrix m3(ar3);
    cout << "m3:\n"<<m3<<endl;

    Matrix m4=m2*m3;cout << "m4:\n"<<m4<<endl;

    Matrix m5;
    m5=m2+m3;cout << "m5:\n"<<m5<<endl;
    
    m2+=m3; cout << "m2:\n"<<m2<<endl;
    return 0;
}

