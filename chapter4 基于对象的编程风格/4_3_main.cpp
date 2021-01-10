/*
 * @Author: your name
 * @Date: 2020-12-07 14:27:42
 * @LastEditTime: 2020-12-07 17:06:54
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \chapter4\4_3_main.cpp
 */

#include "4_3_Triangular.h"
#include "4_3_Triangular_iterator.h"

ostream &operator<<(ostream & os, const Triangular& rhs)
{
    os << "( "
    << rhs.beg_pos() << " , "
    << rhs.length()  << " ) ";

    rhs.display( rhs.length(), rhs.beg_pos(), os );
    return os;
}

istream&
operator>>( istream &is, Triangular &rhs )
{
	char ch1, ch2;
	int bp, len;

   // given the input: ( 3 , 6 ) 6, 10, 15, 21, 28, 36 
   // ch1 == �(�, bp == 3, ch2 == �,�, len == 6
	is >> ch1 >> bp >> ch2 >> len;

   rhs.beg_pos( bp ); 
   rhs.length( len ); 
   rhs.next_rest();

	return is;
}

void prog1()
{
	char ch;
	bool more = true;

	while ( more )
	{
	    cout << "Enter value: ";
	    int ival;
	    cin >> ival;

     	bool is_elem = Triangular::is_elem( ival );

        cout << ival 
             << ( is_elem ? " is " : " is not " )
		     << "an element in the Triangular series.\n"
			 << "Another value? (y/n) ";

		cin >> ch;
		if ( ch == 'n' || ch == 'N')
			 more = false;
	}
}


void prog4()
{
    Triangular tri( 6, 3 );
    cout << tri << '\n';

	Triangular tri2;
	cin >> tri2;
	cout << tri2;
}

void prog2()
{
	Triangular tri( 20, 12 );
	Triangular::iterator it = tri.begin();
	Triangular::iterator end_it = tri.end();

	cout << "Triangular Series of " << tri.length() << " elements\n";
	// cout << tri << endl;
	while ( it != end_it ){
		cout << *it << ' ';
		++it;
	}
	cout << endl;
}


int main(int argc, char const *argv[])
{
    prog4();
    cout<<"\n-----------------\n";
    prog2();
    return 0;
}
