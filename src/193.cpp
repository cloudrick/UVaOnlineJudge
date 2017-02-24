
#include<iostream>
#include<set>
#include<queue>

using namespace std ;

int i,j ;

class Node
{
public :
	int num ;
	int deg ;

	Node(int n,int d) : num(n) , deg(d) { }

	bool operator<( const Node &rhs) const
	{
		return deg < rhs.deg ;
	}

} ;

int main()
{
	int N ;
	cin >> N ;

	while( --N )
	{
		int n,k ;

		cin >> n >> k ;

		int *node_degree = new int[n] ;
		bool **map = new bool* [n] ;

		for( i=0 ; i<n ; ++i)
			map[i] = new bool[n] ;

		for( i=0 ; i<n ; ++i)
		{
			node_degree[i] = 0 ;
			for( j=0 ; j<n ; ++j)
				map[i][j] = false ;
		}

		while(--k)
		{
			int a,b ;
			cin >> a >> b ;
			node_degree[a]++ ;
			node_degree[b]++ ;
			map[a][b] = map[b][a] = true ;
		}

		priority_queue<Node> q ;

		for( i=0 ; i<n ; ++i)
		{
			q.push( Node(i,node_degree[i]) ) ;
		}

		set<int> S[2] ;
		int index = 0 ;

		bool *marked = new bool[n] ;
		for( )

		while( !q.empty() )
		{
			Node t = q.top() ;
			q.pop() ;

			if( S[0].find( t.num ) != S[0].end() )
			{

				continue ;
			}
			if( S[1].find( t.num ) != S[1].end() )
				continue ;

		}
		
		for( i=0 ; i<n ; ++i)
			delete [] map[i] ;
		delete [] map ;
		delete [] node_degree ;

	}

	return 0 ;
}