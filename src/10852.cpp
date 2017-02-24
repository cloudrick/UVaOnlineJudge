
#include<iostream>

using namespace std ;

int main()
{
	bool prime[10001] ;
	int i ;

	for( i=0 ; i<10001 ; ++i)
		prime[i] = true ;

	prime[0] = prime[1] = false ;

	for( i=2 ; i<10001 ; ++i)
	{
		if( prime[i] )
		{
			for( int j=2 ; i*j < 10001 ; j++)
			{
				prime[i*j] = false ;
			}
		}
	}

	int M ;

	cin >> M ;

	while(M--)
	{
		int N ;
		cin >> N ;

		for( i=(N/2)+1 ; i<=N ; ++i)
		{
			if( prime[i] )
			{
				cout << i << endl ;
				break ;
			}
		}
	}

	return 0 ;
}