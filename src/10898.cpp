
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std ;

int Price[6] ;
int min_cost ;
int i,j ;

class M
{
public :
	vector<int> item_num ;
	int price ;

	bool operator<(const M &m) const
	{
		for( int i=0 ; i<item_num.size() ; ++i)
		{
			if( item_num[i] > m.item_num[i] )
				return false ;
		}
		return true ;
	}

	bool empty()
	{
		for( int i=0 ; i<item_num.size() ; ++i)
		{
			if( item_num[i] != 0 )
				return false ;
		}
		return true ;
	}

	void del( const M &m)
	{
		for( int i=0 ; i<item_num.size() ; ++i)
		{
			item_num[i] -= m.item_num[i] ;
		}
	}

	void add( const M &m)
	{
		for( int i=0 ; i<item_num.size() ; ++i)
		{
			item_num[i] += m.item_num[i] ;
		}
	}

} ;


void compute(const vector<M> &comb_price , M &m ,int cur_cost,int index)
{
	if( m.empty() )
	{
		if( cur_cost < min_cost )
		{
			min_cost = cur_cost ;
			return ;
		}
	}

	bool use_comb = false ;

	for( int i=index ; i<comb_price.size() ; ++i)
	{
		if( comb_price[i] < m )
		{
			use_comb = true ;
			m.del(comb_price[i]) ;
			compute(comb_price,m,cur_cost+comb_price[i].price,i) ;
			m.add(comb_price[i]) ;
		}
	}

	if( !use_comb )
	{
		for( int i=0 ; i<m.item_num.size() ; ++i)
		{
			cur_cost += (m.item_num[i]*Price[i]) ;
		}
		if(cur_cost < min_cost)
		{
			min_cost = cur_cost ;
		}
	}
}

int main()
{
	for(;;)
	{
		int I ;
		cin >> I ;

		if(cin.eof())
			break ;

		for( i=0 ; i<I ; ++i)
		{
			cin >> Price[i] ;
		}

		int comb_num ;
		cin >> comb_num ;

		vector<M> comb_price ;

		for( i=0 ; i<comb_num ; ++i)
		{
			M m ;
			for( j=0 ; j<I ; ++j)
			{
				int tmp ;
				cin >> tmp ;
				m.item_num.push_back(tmp) ;
			}
			cin >> m.price ;
			comb_price.push_back(m) ;
		}

		int order_num ;
		cin >> order_num ;

		for( i=0 ; i<order_num ; ++i)
		{
			M m ;
			for( j=0 ; j<I ; ++j)
			{
				int tmp ;
				cin >> tmp ;
				m.item_num.push_back(tmp) ;
			}

			min_cost = 100000000 ;
			compute(comb_price,m,0,0) ;

			cout << min_cost << endl ;
		}

	}

	return 0 ;
}