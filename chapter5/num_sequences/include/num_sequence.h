//
// Created by 11604 on 2020/12/15.
//

#ifndef CHAPTER5_NUM_SEQUENCE_H
#define CHAPTER5_NUM_SEQUENCE_H


#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;


class num_sequence {
public:
    typedef vector<unsigned  int >::iterator iterator;

    virtual ~num_sequence(){};
    virtual num_sequence* clone() const =0 ;


    virtual unsigned int ele(int pos) const=0;
    virtual bool is_elem(unsigned int ) const = 0;
    virtual int pos_elem(unsigned int) const =0;

    virtual const char* what_am_i() const = 0;
    static int max_elems() {return _max_elems ;}
    virtual ostream & print(ostream& os=cout) const=0;

    virtual bool operator==(const num_sequence&) const=0;
    virtual bool operator!=(const num_sequence& ) const=0;

    virtual iterator begin() const =0;
    virtual iterator end() const=0;


    virtual int length() const =0;
    virtual int beg_pos() const=0;

    virtual void set_position(int pos) =0;
    virtual void set_length(int pos) = 0;

    virtual const vector<unsigned int >* sequence() const=0;




protected:
    enum { _max_elems = 1024};

    virtual void gen_elems(int pos) const = 0;
    bool check_integrity(int pos,int size) const;


};


//class Pell : public num_sequence;


#endif //CHAPTER5_NUM_SEQUENCE_H
