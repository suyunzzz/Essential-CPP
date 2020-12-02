/*
 * @Author: your name
 * @Date: 2020-12-02 14:14:24
 * @LastEditTime: 2020-12-02 14:46:02
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \chapter4\4_3_Triangular.h
 */
#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>

using namespace std;

class Triangular_iterator{
public:
    Triangular_iterator(int index):_index(index-1){

    }

    bool operator ==( const Triangular_iterator&) const;

    bool operator !=( const Triangular_iterator&) const;
    int operator*() const;
    Triangular_iterator& operator++();
    Triangular_iterator operator++(int) ;

private:
    void check_integrity() const;
    int _index;
};  //class Trianguar_iterator


class Triangular{
    friend class Triangular_iterator;
public:
    Triangular(int len=1,int beg_pos = 1);
    // Triangular(const Triangular &);

    int length()  const { return _length;  }
    int beg_pos() const { return _beg_pos; }
    int elem(int pos) const;

    bool next(int& value) const;
    void next_rest() const;

    static bool is_elem(  int);
    static void gen_elements(int length);
    static void gen_elems_to_value(int value);
    static void display(int length,int beg_pos,ostream& os=cout);

    typedef Triangular_iterator iterator;

    iterator begin() const
    { return iterator(_beg_pos);}

    iterator end() const { return iterator(_beg_pos+_length);}
    

private:
    int _length;
    int _beg_pos;
    mutable int _next;

    static vector<int > _elems;
    enum {_max_elems = 1024};
}; // class Triangular