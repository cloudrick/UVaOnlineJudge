
#include<iostream>
#include<set>

using namespace std ;

int i ;

int main()
{
	for(;;)
	{
		int n ;
		cin >> n ;
		if( n==0 )
			break ;

		set<int> d[101] ;

		for( i=0 ; i<n ; ++i)
		{
			int t ;
			cin >> t ;
			while(t--)
			{
				int dd ;
				cin >> dd ;
				d[i].insert(dd) ;
			}
		}

		for( i=0 ; i<n ; ++i)
		{
			bool i_done = false ;

			while( !i_done )
			{
				i_done = true ;

				for( set<int>::iterator j=d[i].begin() ;
					 j!=d[i].end() ; ++j )
				{
					int pre_size = d[i].size() ;
					for( set<int>::iterator jj=d[(*j)-1].begin() ;
					      jj != d[(*j)-1].end() ; ++jj)
					{
						d[i].insert(*jj) ;	
					}
					if( pre_size != d[i].size() )
					{
						i_done = false ;
						break ;
					}
				}
			}
		}

		int max_v = 0 ;
		int max_i = 0 ;

		for( i=0 ; i<n ; ++i)
		{
			if( d[i].size() > max_v)
			{
				max_i = i ;
				max_v = d[i].size() ;
			}
		}

		cout << max_i+1 << endl ;

	}
	return 0 ;
}
