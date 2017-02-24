
#include<iostream>

using namespace std ;

bool map_table[1000001] ;
int  prime_table[78498] ;
int pritab_len = 0 ;

int main()
{
	for(int i=0 ; i<1000001 ; i++)
	{
		map_table[i] = false ;
	}

	for( int j=2 ; j<=500000 ; j++)
	{
		if( map_table[j] )
			continue ;
		for( int k=2 ; j*k<1000001 ; k++)
		{
			map_table[k*j] = true ;
		}
	}

	for( int a=2 ; a<1000001 ; a++)
	{
		if( !map_table[a] )
			prime_table[pritab_len++] = a ;
	}


	while(true)
	{
		int n ;
		cin >> n ;

		if( n==0 )
			break ;
		int sum = 0 ;

		for(int ii=0 ; ii<pritab_len  ; ii++)
		{
			if( prime_table[ii] > n )
				break ;
			if( n%prime_table[ii] == 0 )
				sum++ ;
		}

		cout << n << " : " << sum << endl ;
	}

	return 0 ;
}
