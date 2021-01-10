/*
 * @Author: your name
 * @Date: 2021-01-05 17:16:39
 * @LastEditTime: 2021-01-05 21:52:27
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \chapter6\test6_2.cpp
 */
#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <typename elemType>
class Matrix
{
    // 解决方法1
    // 声明友元
    template <typename U>
    friend Matrix<U> operator+(const Matrix<U>& m1,const Matrix<U>& m2);
    template <typename U>
    friend Matrix<U> operator*(const Matrix<U>& m1,const Matrix<U>& m2);
    template <typename U>
    friend ostream& operator<<(ostream & os,const Matrix<U>& m);



public:
    // 构造函数
    Matrix(int rows,int cols):_rows(rows),_cols(cols)
    {
        _size = rows*cols;
        _pmatrix = new elemType[_size];
        for(int i=0;i<_size;i++)
        {
            _pmatrix[i] = elemType();
        }
    }


    // 析构函数
    ~Matrix()
    {
        delete [] _pmatrix;
    }

    // 拷贝构造函数
    Matrix(const Matrix<elemType>& m)
    {
        _rows = m._rows;
        _cols  = m._cols;
        _size = _rows*_cols;
        _pmatrix = new elemType[_size];
        for(int i = 0; i < _size;i++)
        {
            _pmatrix[i] = m._pmatrix[i];
        }
    }


    // 拷贝赋值函数
    Matrix<elemType> operator=(const Matrix<elemType>& m)
    {
        // 先检验当前对象和参数是否为同一地址
        if(this != &m)
        {
            delete[] _pmatrix;
            _rows = m._rows;
            _cols = m._cols;
            _size = _rows*_cols;
            _pmatrix = new elemType[_size];

            for(int i=0; i<_size; i++)
            {
                _pmatrix[i] = m._pmatrix[i];
            }

        }

        return *this;


    }

    // 查看当前矩阵的信息
    int rows() const
    { return _rows;}

    int cols() const
    { return _cols;}

    int size() const
    { return _size;}

    // 获取矩阵元素
    elemType operator()(int row,int col) const
    { return _pmatrix[row*_rows+col];}

    elemType& operator()( int row, int col)  
    {
        return _pmatrix[row*_rows+col];
    }

    void operator+=( const Matrix& m)
    { 
        if((_rows==m._rows) && (_cols==m._cols))
        {
            for(int i=0; i<_size;i++)
            {
                _pmatrix[i]+=m._pmatrix[i];
            }
        }
        else
        {
            printf("[ERROR] dimension mismatch!\n");
        }

    } 

    ostream& print(ostream& os= cout)
    {
        os<<"----------------\n";
        os<<(*this)<<"\n";
        os<<"----------------\n";
        return os;
    }




private:
    elemType* _pmatrix;
    int _size;
    int _rows;
    int _cols;
    elemType _max;
    elemType _min;

};  // class matrix

template <typename elemType>
ostream& operator<<(ostream & os,const Matrix<elemType>& m);

template <typename elemType>
Matrix<elemType> operator+(const Matrix<elemType>& m1,const Matrix<elemType>& m2);

template <typename elemType>
Matrix<elemType> operator*(const Matrix<elemType>& m1,const Matrix<elemType>& m2);



template <typename elemType>
ostream& operator<<(ostream & os,const Matrix<elemType>& m)
{
    for(int i=0;i<m._rows;i++)
    {
        for(int j = 0;j<m._cols;j++)
        {
            cout<<m._pmatrix[i*m._rows+j];
        }
        cout<<"\n";
    }
    return os;
}

template <typename elemType>
Matrix<elemType> operator+(const Matrix<elemType>& m1,const Matrix<elemType>& m2)
{
    // cout<<"operator+\n"
    //     <<"m1:"<<m1<<"\n---\n"
    //     <<"m2:"<<m2<<"\n";
    
    if((m1._cols==m2._cols) && (m1._rows==m2._rows))
    {
        Matrix<elemType> new_matrix(m1);
        for(int i = 0; i < m1._size; i++)
        {
            new_matrix._pmatrix[i]=m1._pmatrix[i]+m2._pmatrix[i];
            // cout<<"new_matrix._pmatrix[i]: "<<new_matrix._pmatrix[i]<<endl;
        }

        // cout<<"new_matrix:\n"<<new_matrix<<endl;
        return new_matrix;
    }

    printf("[ERROR] dimension mismatch!\n");
    return m1;
}

template <typename elemType>
Matrix<elemType> operator*(const Matrix<elemType>& m1,const Matrix<elemType>& m2)
{
        
    if((m1._cols==m2._cols) && (m1._rows==m2._rows))
    {
        Matrix<elemType> new_matrix(m1);
        for(int i = 0; i < m1._size; i++)
        {
            new_matrix._pmatrix[i]=m1._pmatrix[i]*m2._pmatrix[i];
        }
        return new_matrix;
    }

    printf("[ERROR] dimension mismatch!\n");
    return m1;

}



int main(int argc, char const *argv[])
{
    Matrix<int> max_a(3,5);
    printf("max_a:\n");
    max_a.print();

    max_a(0,0)=1;
    max_a(2,2)=2; 
    printf("max_a:\n");
    cout<<max_a<<endl;

    Matrix<int> mat_b(3,5);
    printf("mat_b:\n");
    mat_b.print();

    mat_b = max_a+max_a;
    printf("mat_b:\n");
    mat_b.print();

    Matrix<int> mat_c(max_a);
    printf("mat_c:\n");
    mat_c.print();
    
    mat_c = mat_b*mat_c;
    printf("mat_c:\n");
    mat_c.print();
    
    Matrix<int> mat_d(3,3);
    mat_c+=mat_c;
    mat_c.print();
    

    // Matrix<double> max__a(3,5);
    // max__a.print();
    return 0;
}
