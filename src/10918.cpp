
#include<iostream>

using namespace std ;

int main()
{
	int table[31] ;

	table[0] = 1 ;
	table[1] = 0 ;
	table[2] = 3 ;

	for( int i=3 ; i<=30 ; ++i)
	{
		if( i%2 != 0)
		{
			table[i] = 0 ;
		}
		else
		{
			for( int j=2 ; j<=i ; j+=2)
			{
				if( j==2 )
				{
					table[i] = 3*table[i-2] ;
				}
				else
				{
					table[i] += 2*table[i-j] ;
				}
			}
		}
	}

	for(;;)
	{
		int n ;
		cin >> n ;

		if( n==-1)
			break ;
		else
			cout << table[n] << endl ;

	}

	return 0 ;
}

