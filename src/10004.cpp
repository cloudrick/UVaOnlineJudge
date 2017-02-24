
#include<iostream>
#include<queue>

using namespace std ;

int main()
{
	while(true)
	{
		int i,j ;

		int n ;
		cin >> n ;
		if( n==0 )
			break ;		

		bool adj_matrix[200][200] ;
		bool visited[200] ;
		int color[200] ;

		for(i=0 ; i<n ; ++i)
		{
			visited[i] = false ;
			color[i] = 0 ;
			for( j=0 ; j<n ; ++j)
				adj_matrix[i][j] = false ;
		}

		int m ;
		cin >> m ;

		for(i=0 ; i<m ;++i)
		{
			int p,q ;
			cin >> p >> q ;
			adj_matrix[p][q] = adj_matrix[q][p] = true ;
		}

		queue<int> bfs_q ;
		bfs_q.push(0) ;
		color[0] = 1 ;

		bool isBicolorable = true ;

		while( !bfs_q.empty() && isBicolorable )
		{
			int v = bfs_q.front() ;

			for( i=0 ; i<n ; ++i)
			{
				if( !adj_matrix[v][i] )
					continue ;

				if(visited[i])
				{
					if( color[i] == color[v] )
					{
						isBicolorable = false ;
						break ;
					}
				}
				else
				{
					color[i] = (color[v]==1) ? 2 : 1 ;
					visited[i] = true ;
					bfs_q.push(i) ;
				}
			}

			bfs_q.pop() ;
		}

		if( isBicolorable )
			cout << "BICOLORABLE." << endl ;
		else
			cout << "NOT BICOLORABLE." << endl ;

	}

	return 0 ;
}