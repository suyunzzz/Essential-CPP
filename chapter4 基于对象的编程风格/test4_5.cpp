/*
 * @Author: your name
 * @Date: 2020-12-07 20:33:04
 * @LastEditTime: 2020-12-07 22:27:24
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \chapter4\test4_5.cpp
 */
#include "test4_5.h"




Matrix::Matrix(const elemType* P_m)
{
    int index = 0;
    for (int i = 0; i <4 ;i++)
    {
        for(int j = 0; j <4 ;j++)
        {
            _matrix[i][j]=*(P_m+index);
            index++;
        }
    }
}

Matrix::Matrix(
    elemType a11,elemType a12,elemType a13,elemType a14,
    elemType a21,elemType a22,elemType a23,elemType a24,
    elemType a31,elemType a32,elemType a33,elemType a34,
    elemType a41,elemType a42,elemType a43,elemType a44)
{
    _matrix[0][0]=a11;_matrix[0][1]=a12;_matrix[0][2]=a13;_matrix[0][3]=a14;
    _matrix[1][0]=a21;_matrix[1][1]=a22;_matrix[1][2]=a23;_matrix[1][3]=a24;
    _matrix[2][0]=a31;_matrix[2][1]=a32;_matrix[2][2]=a33;_matrix[2][3]=a34;
    _matrix[3][0]=a41;_matrix[3][1]=a42;_matrix[3][2]=a43;_matrix[3][3]=a44;

}

Matrix operator+(const Matrix& m1,const Matrix& m)   // 返回临时变量，因此不能返回引用
{
    Matrix result;      // 临时变量
    result+=m1;          // 借用+=运算符重载
    result+=m;
    return result;
}

Matrix operator*(const Matrix& m1,const Matrix& m)
{
    Matrix result;
    // int index = 0;
    for(int i=0;i<4 ;i++)
    {
        for(int j=0;j<4 ;j++)
        {
            result(i,j)=m1._matrix[i][j]*m._matrix[i][j];
        }
    }
    return result;

}

// operator+=的第一种写法
void Matrix::operator+=(const Matrix& m){       // 访问了对象的私有成员
    for(int i=0;i<4 ;i++)
    {
        for(int j=0;j<4 ;j++)
        {
            _matrix[i][j]+=m._matrix[i][j];
        }
    }
}


ostream& Matrix::print(ostream& os) const
{
    for(int i=0;i<4 ;i++)
    {
        for(int j=0;j<4 ;j++)
        {
            os << _matrix[i][j]<<" ";
        }
        os<<"\n";
    }
    return os;
}


ostream& operator<<(ostream& os,const Matrix& mat){

    return mat.print(os);   // 访问了私有成员
    // return os;
}

// operator+=的第二种写法
// 访问了私有成员，friend!
// Matrix& operator+=( Matrix& m,const Matrix& m1)
// {
//     for(int i=0;i<4 ;i++)
//     {
//         for(int j=0;j<4 ;j++)
//         {
//             m._matrix[i][j]+=m1._matrix[i][j];
//         }
//     }
//     return m;
// }   
