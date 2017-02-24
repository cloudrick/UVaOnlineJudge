
#include<iostream>
#include<cmath>

using namespace std ;

int main()
{

	for(;;)
	{
		int y ; 
		cin >> y ;

		if( y==0 )
			break ;

		y = (y-1960)/10 ;

		int p=4 ;

		while(y--)
			p<<=1 ;

		double r = 0 ;
		int i ;

		for( i=2 ; r<= p*log10(2.0) ; ++i )
		{
			r += log10(i) ;
		}

		cout << i-2 << endl ;

	}

	return 0 ;
}