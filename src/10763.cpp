
#include<iostream>
#include<set>

using namespace std ;

class exchange
{
public:
	int a ;
	int b ;
	exchange(int aa,int bb) : a(aa),b(bb) {}

	inline bool operator==(const exchange &r) const 
	{
		return (a==r.a) && (b==r.b) ;
	}

	inline bool operator<(const exchange &r) const
	{
		return ( a < r.a ) || ( a==r.a && b<r.b) ;
	}

} ;


int main()
{
	while(true)
	{
		int n ;
		cin >> n ;

		if(n==0)
			break ;

		multiset<exchange> data ;

		for( int i=0 ; i<n ; ++i)
		{
			int a,b ;

			cin >> a >> b ;

			multiset<exchange>::iterator idx ;

			idx = data.find( exchange(b,a) ) ;
			
			if( idx != data.end() )
			{
				data.erase( idx ) ;
			}
			else
			{
				data.insert( exchange(a,b) ) ;
			}

		}

		if( data.empty() )
			cout << "YES" << endl ;
		else
			cout << "NO" << endl ;

	}

	return 0 ;
}