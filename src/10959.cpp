
#include<iostream>
#include<set>

using namespace std ;

int main()
{
	int n ;
	cin >> n ;

	while(n--)
	{
		int i,j ;

		int P,D ;
		cin >> P >> D ;

		int **dist = new int* [P] ;
		bool *visited = new bool[P] ;

		for( i=0 ; i<P ; ++i)
			dist[i] = new int[P] ;
	

		for( i=0 ; i<P ; ++i)
		{
			for( j=0 ; j<P ; ++j)
				dist[i][j] = -1 ;
			dist[i][i] = 0 ;
			visited[i] = false ;
		}

		while(D--)
		{
			int a,b ;
			cin >> a >> b ;
			dist[a][b] = dist[b][a] = 1 ;
		}

		visited[0] = true ;
		for( int k=2 ; k<P ; ++k)
		{
			int min_v = 1000000000 ;
			int min_i ;
			for( i=1 ; i<P ; ++i)
			{
				if( !visited[i] && dist[0][i]<min_v && dist[0][i] != -1)
				{
					min_v = dist[0][i] ;
					min_i = i ;
				}
			}
			visited[min_i] = true ;

			for( i=1 ; i<P ; ++i)
			{
				if( !visited[i] && dist[min_i][i] != -1 )
				{
					if(  dist[0][min_i] + dist[min_i][i] < dist[0][i] || dist[0][i]==-1)
					{
						dist[0][i] = dist[i][0] = dist[0][min_i]+dist[min_i][i] ;
					}
				}
			}
		}

		for( i=1 ; i<P; ++i)
			cout << dist[0][i] << endl ;

		if( n!=0)
			cout << endl ;

		for( i=0 ; i<P ; ++i)
			delete [] dist[i] ;
		delete [] dist ;
		delete [] visited ;
	}

	return 0 ;
}