/*
 * @Author: your name
 * @Date: 2020-12-07 20:32:54
 * @LastEditTime: 2020-12-07 22:24:46
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \chapter4\.vscode\test4_5.h
 */

#pragma once

#include <iostream>
#include <vector>

using namespace std;
typedef float elemType;
class Matrix{
    // 友元函数，不含默认的this
    friend Matrix operator+(const Matrix& m1, const Matrix& m);   
    friend Matrix operator*(const Matrix& m1,const Matrix& m);
    friend ostream& operator<<(ostream & os,const Matrix& m);
    // friend Matrix& operator+=(Matrix& m,const Matrix& m1);

public:
        // friend void operator+=( const Matrix& m);


    Matrix(const elemType* P_m);            // 构造函数，接受16个数
    Matrix(elemType=0.,elemType=0.,elemType=0.,elemType=0.,
            elemType=0.,elemType=0.,elemType=0.,elemType=0.,
            elemType=0.,elemType=0.,elemType=0.,elemType=0.,
            elemType=0.,elemType=0.,elemType=0.,elemType=0.);

    int rows() const { return 4;}
    int cols() const { return 4;}

    ostream& print(ostream& os=cout) const;

    void operator+=( const Matrix& );

    elemType operator()(int row, int col) const     // 返回一个临时变量，后续不会改变_matrix内部的，因此可以加定义为const函数
    { 
        return _matrix[row][col];
    }

    elemType& operator()(int row, int col)          // 返回时不生成临时变量，可以做左值，可能会改变_matrix，因此不能定义为const函数
    {
        return _matrix[row][col];
    }

    



private:
    // int row;
    // int column;
    elemType _matrix[4][4];



}; // class Matrix