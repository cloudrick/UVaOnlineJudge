

#include<iostream>
#include<list>

using namespace std ;

int main()
{
	int t = 1 ;

	while(true)
	{
		int n ;
		cin >> n ;
		if(n==0)
			break ;

		int s ;
		cin >> s ;

		int adj_matrix[110][110] ;

		for( int i=0 ; i<=n ; ++i)
		{
			for( int j=0 ; j<=n ; ++j)
				adj_matrix[i][j] = -1 ;
		}

		int max_distance = 0 ;
		int finish_node = 0 ;

		while(true)
		{
			int p,q ;
			cin >> p >> q ;
			if( p==0 && q==0 )
				break ;
			adj_matrix[p][q] = 1 ;

			if( p==s )
			{
				max_distance = 1 ;
				if( finish_node==0 || q<finish_node)
					finish_node = q ;
			}
		}

		if( finish_node == 0 )
			finish_node = s ;

		for( int k=1 ; k<=n ; ++k)
		{
			for( int i=1 ; i<=n ;++i)
			{
				if( i==k ) continue ;
				for( int j=1 ; j<=n ; ++j)
				{
					if( j==i || j==k ) continue ;
					if( adj_matrix[i][k] < 0 || adj_matrix[k][j] < 0 ) continue ;

					if( adj_matrix[i][k]+adj_matrix[k][j] > adj_matrix[i][j] || adj_matrix[i][j]<0)
					{
						adj_matrix[i][j] = adj_matrix[i][k]+adj_matrix[k][j] ;
						if( i==s &&  adj_matrix[i][j]>=max_distance )
						{
							if( adj_matrix[i][j] == max_distance && j>finish_node)
								continue ;

							max_distance = adj_matrix[i][j] ;
							finish_node = j ;
						}
					}
				}
			}
		}

		cout << "Case " << t++ << ": " ;
		cout << "The longest path from " << s 
			 << " has length " << max_distance 
			 << ", finishing at " << finish_node << "." << endl << endl  ;

	}
	return 0 ;
}