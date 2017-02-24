
#include<iostream>
#include<set>

using namespace std ;

int i,j ;
int dist[1001][1001] ;

int main()
{
	for(;;)
	{
		int n ;

		cin >> n ;
		if(n==0)
			break ;

		int m ;
		cin >> m ;

		bool map[1001] ;
		int way[1001] ;

		for(i=0 ; i<=n ; ++i)
		{
			for( j=0 ; j<=n ; ++j)
			{
				dist[i][j] = -1 ;
			}
			dist[i][i] = 0 ;
			way[i] = 0 ;
			map[i] = true ;
		}

		while(m--)
		{
			int a,b,d ;
			cin >> a >> b >> d ;
			dist[a][b] = dist[b][a] = d ;

			if( a==1 || b==1 )
			{
				way[a] = way[b] = 1 ;
			}
		}

		for(int k=0 ; k<n-2 ; ++k)
		{
			int min_v=1000000 ;
			int min_i ;

			for(i=2 ; i<=n ; ++i )
			{
				if( !map[i] )
					continue ;

				if( dist[1][i] != -1 && dist[1][i] < min_v )
				{
					min_v = dist[1][i] ;
					min_i = i ;
				}
			}

			map[min_i] = false ;

			for(i=2 ; i<=n ; ++i)
			{
				if( map[i] == true )
				{
					if( dist[min_i][i] != -1 && dist[1][min_i] != -1 &&
						( dist[1][min_i]+dist[min_i][i]<=dist[1][i] || dist[1][i]==-1 ))
					{
						if( dist[1][min_i]+dist[min_i][i] == dist[1][i] )
						{
							way[i] += way[min_i] ;
						}
						else
						{
							way[i] = way[min_i] ;
						}
						
						dist[1][i] = dist[i][1] = dist[1][min_i]+dist[min_i][i] ;
						
					}
				}
			}
		}
		
		cout << way[2] << endl ;
	}

	return 0 ;
}
