
#include<iostream>

using namespace std ;

int main()
{
	bool prime[46350] ;
	int i,j ;

	for( i=0 ; i<46350 ; ++i)
		prime[i] = true ;

	for(i=2 ; i<46350 ; ++i)
	{
		if( prime[i] )
		{
			for( j=2 ; i*j<46350 ; ++j)
			{
				prime[i*j] = false ;
			}
		}
	}

	while(true)
	{
		int n ;
		bool signed_flag = false ;

		cin >> n ;

		if( n==0 )
			break ;

		if( n<0 )
		{
			signed_flag = true ;
			n = -n ;
		}

		int map[46350] ;

		for( i=0 ; i<46350 ; ++i)
			map[i] = 0 ;

		

		int min = 0 ;

		for( i=2 ; i<46350 ; ++i)
		{
			if( prime[i] )
			{
				while( n%i==0 )
				{
					n/=i ;
					map[i]++ ;
					if(map[i]>min)
						min = map[i] ;
				}
			}
		}

		for( i=2 ; i<46350 ; ++i)
		{
			if( map[i] < min && map[i]!=0)
				min = map[i] ;
		}

		if( min==0 )
			min = 1 ;

		if( signed_flag )
		{
			while(min%2==0 )
				min/=2 ;
		}

		cout << min << endl ;
	}

	return 0 ;
}