
#include<iostream>
#include<queue>
#include<set>

using namespace std ;


class edge
{
public :
	int node1 ;
	int node2 ;
	int weight ;

	edge(int,int,int) ;

	bool operator<(const edge&) const ;
	bool operator!=(const edge&)  const;

} ;

edge::edge(int n1,int n2,int w) : node1(n1) , node2(n2) , weight(w)
{

}

bool edge::operator<(const edge& e) const 
{
	return ( weight > e.weight) ;
}


bool edge::operator!=( const edge& e) const
{
	return ( node1!=e.node1 || node2!=e.node2) ;
}

bool is_complated(int *map,int N)
{
	if( N>0 )
	{
		for( int i=1 ; i<N ; ++i)
		{
			if( map[i] != map[0] )
				return false ;
		}
		return true ;
	}
	return false ;
}

void union_vertex(int *map,int N,int t1,int t2)
{
	for(int i=0 ; i<N ; ++i)
	{
		if( map[i] == t1 )
			map[i] = t2 ;
	}
}

int MST(int N, priority_queue<edge> tmp_all_edge, set<edge>& sol , edge igon)
{
	int *map ;

	map = new int[N] ;

	for( int i=0 ; i<N ; i++)
	{
		map[i] = i ;
	}

	int cost = 0 ;
	sol.clear() ;
		
	while( !is_complated(map,N) && !tmp_all_edge.empty() )
	{
		edge t = tmp_all_edge.top() ;
		if( map[t.node1-1] != map[t.node2-1] && t != igon)
		{
			cost += t.weight ;
			union_vertex(map,N,map[t.node1-1],map[t.node2-1]) ;
			sol.insert(t) ;
		}
		tmp_all_edge.pop() ;
	}


	if(!is_complated(map,N))
	{
		delete [] map ;
		return 100000000 ;
	}
	else
	{	
		delete [] map ;
		return cost ;
	}
}


int main()
{
	int T,N,M ;
	int i,j ;

	cin >> T ;

	while(true)
	{

		cin >> N ;
		cin >> M ;

		if( cin.eof() )
			break ;

		int cost = 0 ;		

		priority_queue<edge> all_edge ;
		for(i=0 ; i<M ; ++i)
		{
			int a,b,c ;
			cin >> a >> b >> c ;
			edge tmp(a,b,c) ;

			all_edge.push(tmp) ;

		}

		set<edge> mst_set ;
		cout << MST(N,all_edge,mst_set,edge(0,0,0))  << " " ;

		int second_cost = 1000000000 ;

		for( set<edge>::iterator i=mst_set.begin() ; i!=mst_set.end() ; ++i)
		{
			set<edge> s_mst ;
			int s = MST(N,all_edge,s_mst,*i) ;
			
			if( s < second_cost )
			{
				second_cost = s ;
			}
		}

		cout << second_cost << endl ;

	}

	return 0 ;
}