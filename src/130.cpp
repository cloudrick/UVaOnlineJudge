
#include<iostream>

using namespace std ;

int main()
{
	for(;;)
	{
		int n,k ;
		cin >> n >> k ;

		if( n==0 && k==0 )
			break ;

		int i ;
		int table[100] ;


		for( i=0 ; i<n ; ++i)
		{
			table[i] = i+1 ;
		}

		int j1=-1 ;
		int j2=0 ;
		int count ;
		int np = n ;
		bool flag = true ;

		for(; np>1 ;)
		{	
			count = 0 ;
			do
			{
				j1=(j1+1)%n ;
				while( table[j1] == -1)
				{
					j1 = (j1+1)%n ;
				}
				count++ ;
			}while(count<k) ;

			table[j1] = -1 ;

			np-- ;

			count = 0 ;
			j2=j1 ;
			do
			{
				j2=(j2+1)%n ;
				while( table[j2] == -1)
				{
					j2 = (j2+1)%n ;	
				}
				count++ ;
			}while(count<k) ;

			table[j1] = table[j2] ;
			table[j2] = -1 ;
		}

		if( j1<0 ) j1=0 ;

		int d = (n-table[j1]+2)%n ;

		if( d==0 )
			cout << n << endl ;
		else
			cout << d << endl ;
	}

	return 0 ;
}