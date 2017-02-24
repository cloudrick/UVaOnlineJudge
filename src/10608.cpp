
#include<iostream>

using namespace std ;


int main()
{
	int i ;

	int num ;
	cin >> num ;

	while(num--)
	{
		int N,M ;
		cin >> N >> M ;

		int parent[30000] ;
		int number[30000] ;
		bool count[30000] ;

		for(i=0 ; i<N ; ++i)
		{
			parent[i] = i ;
			number[i] = 0 ;
			count[i] = false ;
		}

		for(i=0 ; i<M ; ++i)
		{
			int a,b ;
			cin >> a >> b ;
			a--;b-- ;
			while( parent[a] != a ) a = parent[a] ;
			while( parent[b] != b ) b = parent[b] ;
			parent[b] = a ;
		}

		int max = 0 ;

		for( i=0 ; i<N ; ++i)
		{
			if( !count[i] )
			{
				count[i] = true ;
				int loc = 1 ;
				int p = i ;
				while( parent[p]!=p )
				{
					p=parent[p] ;
					if( !count[p] )
					{
						count[p] = true ;
						loc++ ;
					}
				}
				number[p] += loc ;

				if( number[p] > max )
					max = number[p] ;
			}
		}

		cout << max << endl ;

	}
	return 0 ;
}