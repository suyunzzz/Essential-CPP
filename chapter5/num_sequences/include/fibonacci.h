//
// Created by 11604 on 2020/12/15.
//

#ifndef CH5_FIBONACCI_H
#define CH5_FIBONACCI_H

#include "num_sequence.h"

class Fibonacci : public num_sequence {
public:
    Fibonacci( int beg_pos = 1, int len = 1 )
    {  set_position( beg_pos ); set_length( len ); }

    virtual num_sequence *clone() const
    { return new Fibonacci( *this ); }

    virtual unsigned int elem( int pos ) const;
    virtual bool        is_elem(  unsigned int elem ) const;
    virtual int         pos_elem( unsigned int elem ) const;

    virtual const char* what_am_i() const { return "Fibonacci"; }
    virtual ostream&    print( ostream &os = cout ) const;

    virtual bool operator==( const num_sequence &rhs ) const;
    virtual bool operator!=( const num_sequence &rhs ) const;

    virtual int length()  const { return _length;  }
    virtual int beg_pos() const { return _beg_pos; }

    virtual void set_position( int pos );
    virtual void set_length( int pos );

    virtual iterator begin() const
    { return _elems.begin()+_beg_pos-1; }

    virtual iterator end() const
    { return _elems.begin() + _beg_pos + _length; }

    virtual const vector<unsigned int>*
    sequence() const { return & _elems; }

protected:
    virtual void gen_elems( int pos ) const;
    static vector< unsigned int > _elems;

    int _length;
    int _beg_pos;

private:
    int _calc_pos( unsigned int elem ) const;
};


#endif //CH5_FIBONACCI_H
