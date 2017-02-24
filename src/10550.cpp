
#include<iostream>

using namespace std ;

int main()
{
	for(;;)
	{
		int d0,d1,d2,d3 ;

		cin >> d0 >> d1 >> d2 >> d3 ;

		if( d0==0 && d1==0 && d2==0 && d3==0 )
			break ;

		int d=120 ;

		if( d0>d1 )
			d += d0-d1 ;
		else
			d += 40 - (d1-d0) ;

		if( d1<d2)
			d += d2-d1 ;
		else
			d += 40 - (d1-d2) ;

		if( d2>d3 )
			d += d2-d3 ;
		else
			d += 40 - (d3-d2) ;

		cout << d*9 << endl ;
	}
	return 0 ;
}