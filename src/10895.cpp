
#include<iostream>
#include<vector>
#include<set>

using namespace std ;

int i,j ;

class Entry
{
public :
	int row ;
	int col ;
	int value ;

public :

	bool operator<(const Entry &rhs) const
	{
		return (col < rhs.col) || (col == rhs.col && row<rhs.row) ;
	}

} ;

int main()
{
	for(;;)
	{
		int m,n ;
		cin >> m >> n ;

		if(cin.eof())
			break ;

		set<Entry> entry ;
		int col_size[10010] ;

		for( i=0 ; i<10010 ; ++i)
			col_size[i] = 0 ;

		for( i=1 ; i<=m ; ++i)
		{
			int r ;
			cin >> r ;

			vector<int> buf ;

			for( j=0 ; j<r ; ++j)
			{
				int tmp ;
				cin >> tmp ;
				buf.push_back(tmp) ;
			}

			for( j=0 ; j<r ; ++j)
			{
				int tmp ;
				cin >> tmp ;

				Entry e ;

				e.row = i ;
				e.col = buf[j] ;
				e.value = tmp ;

				col_size[ buf[j] ]++ ;

				entry.insert(e) ;
			}
		}

		cout << n << ' ' << m << endl ;

		int l=1 ;

		for( set<Entry>::iterator k=entry.begin() ; 
		     l<=n ; ++l )
		{
			cout << col_size[l] ;

			vector<int> lay_out ;

			for( i=0 ; i<col_size[l] ; ++i)
			{
				cout << ' ' << (*k).row ;
				lay_out.push_back( (*k).value ) ;
				++k ;
			}
			cout << endl ;

			for( i=0 ; i<col_size[l] ; ++i)
			{
				cout << lay_out[i] ;
				if( i!=col_size[l]-1)
					cout << ' ' ;
			}
			cout << endl ;
		}

	}

	return 0 ;
}