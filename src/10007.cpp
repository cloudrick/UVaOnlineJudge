
#include<iostream>

using namespace std ;

int main()
{
	while(true)
	{
		int i,j ;
		int bnum[800] ;

		for(i=0 ; i<800 ; ++i)
			bnum[i] = 0 ;
		bnum[0] = 1 ;

		int n ; 
		cin >> n ;

		if( n==0 )
			break ;

		for( i=2*n ; i>=n+2 ; --i)
		{
			for( j=0 ; j<800 ; ++j)
				bnum[j] *= i ;
			for( j=0 ; j<799 ; ++j)
			{
				if( bnum[j] > 9)
				{
					bnum[j+1] += bnum[j]/10 ;
					bnum[j] %= 10 ;
				}
			}
		}

		bool printed = false ;

		for( i=799 ; i>=0 ; --i)
		{
			if( printed || bnum[i]!=0 )
			{
				printed = true ;
				cout << bnum[i] ;
			}
		}

		cout << endl ;
	}

	return 0 ;
}