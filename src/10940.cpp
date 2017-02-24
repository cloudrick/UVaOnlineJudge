
#include<iostream>
#include<cmath>

using namespace std ;

int main()
{
	for( ;  ; )
	{
		int n ; 

		cin >> n;

		if( n==0 ) 
			break ;
		if( n==1 ) 
			cout << 1 << endl ;
		else if( n==2 )
			cout << 2 << endl ;
		else
		{
			int m = log10(n)/log10(2) ;
			n = n-pow(2,m) ;
			cout <<  n*2 << endl;
		}

	}

	return 0 ;
}