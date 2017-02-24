
#include <iostream>

using namespace std ;

int table[2001][1010] ;
int count[1010] ;

int main()
{

	int n ;

	int i,j ;

	for( i=0 ; i<1001 ; ++i)
	{
		table[1][i] = 0 ;
		count[i] = 0 ;
	}

	
	table[0][0] = 1 ;

	for( i=1 ; i<1010 ; ++i)
		table[0][i] = 0 ;


	for( i=1 ; i<2001 ; ++i)
	{
		for( j=0 ; j<1010 ; ++j)
		{
			if(i>1)
				table[i][j] = 2*table[i-1][j] ;
			else
				table[i][j] = table[i-1][j] ;

			table[i][j] += count[j] ;

			count[j] += table[i-1][j] ;
		}

		for( j=0 ; j<1009 ; ++j)
		{
			if( table[i][j] > 9 )
			{
				table[i][j+1] += table[i][j] /10 ;
				table[i][j] %= 10 ;
			}
			if( count[i] > 9 )
			{
				count[j+1] += count[j] /10 ;
				count[j] %= 10 ;
			}
		}
	}
	
	while(true)
	{
		cin >> n ;
		if( n==0 )
			break ;

		bool flag = false ;
		for( j=1009 ; j>=0 ; --j)
		{
			if( flag || table[n][j]!=0 )
			{
				cout << table[n][j] ;
				flag = true ;
			}
		}
		cout << endl ;
	}

	return 0 ;
}