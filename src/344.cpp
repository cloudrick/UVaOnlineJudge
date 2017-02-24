
#include<iostream>

using namespace std ;

int i,j ;

int main()
{
	int table[100][5] ;

	for( int k=1 ; k<=100 ; ++k)
	{
		for( i=0 ; i<5 ; ++i)
			table[k-1][i] = 0 ;

		if( k/10 == 10 )
		{
			table[k][4]++ ;
		}

		int tmp = k ;

		if( tmp%10==4 )
		{
			table[k-1][1]++ ;
			table[k-1][0]++ ;
			tmp-=4 ;
		}

		if( tmp%10==9 )
		{
			table[k-1][2]++ ;
			table[k-1][0]++ ;
			tmp-=9 ;
		}

		if( tmp>=40 && tmp<50 )
		{
			table[k-1][3]++ ;
			table[k-1][2]++ ;
			tmp-=40 ;
		}

 		if( tmp>=90 && tmp<100 )
		{
			table[k-1][4]++ ;
			table[k-1][2]++ ;
			tmp-=90 ;
		}

		while( tmp>=100 )
		{
			table[k-1][4]++ ;
			tmp-=100 ;
		}

		while( tmp>=50 )
		{
			table[k-1][3]++ ;
			tmp-=50 ;
		}

		while( tmp>=10 )
		{
			table[k-1][2]++ ;
			tmp-=10 ;
		}

		while( tmp>=5 )
		{
			table[k-1][1]++ ;
			tmp-=5 ;
		}

		while( tmp>=1 )
		{
			table[k-1][0]++ ;
			tmp-=1 ;
		}

		if( k>1 )
		{
			for( i=0 ; i<5 ; ++i)
				table[k-1][i] += table[k-2][i] ;
		}
	}

	for(;;)
	{
		int n ;
		cin >> n ;

		if( n==0 )
			break ;

		cout << n << ": " ;
		cout << table[n-1][0] << " i, " ;
		cout << table[n-1][1] << " v, " ;
		cout << table[n-1][2] << " x, " ;
		cout << table[n-1][3] << " l, " ;
		cout << table[n-1][4] << " c\n" ;

	}
	return 0 ;
}