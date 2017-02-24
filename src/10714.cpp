
#include<iostream>
#include<algorithm>

using namespace std ;

int main()
{
	int m ;

	cin >> m ;

	while(m--)
	{
		int i ;

		int L,n ;
		cin >> L >> n ;

		int *ants = new int[n] ;

		int max=0,min=0 ;

		for(i=0 ; i<n ; ++i)
		{
			cin >> ants[i] ;
			
			if( L-ants[i] > ants[i])
			{
				if( ants[i]>min )
					min = ants[i] ;
			}
			else
			{
				if( L-ants[i] > min)
					min = L-ants[i] ;
			}
		}

		sort(ants,ants+n) ;

		for(i=1;i<n;++i)
			max += ants[i]-ants[i-1] ;

		if( L-ants[n-1] > ants[0] )
			max += L-ants[n-1] ;
		else
			max += ants[0] ;

		cout << min << ' ' << max << endl ;

		delete [] ants ;
	}

	return 0 ;
}