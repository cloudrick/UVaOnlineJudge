
#include<iostream>
#include<list>
#include<cstdio>

using namespace std ;

int gcd(int a,int b)
{
	while(b)
		b^=a^=b^=a%=b ;
	return a ;
}

int main()
{
	for(;;)
	{
		int n,k ;
		cin >> n >> k ;

		if( n==0 && k==0)
			break ;

		if( n==0 )
		{
			cout << 1 << endl ;
			continue ;
		}
		if( k==0 )
		{
			cout << 1 << endl ;
			continue ;
		}

		list<int> factor ;

		for( int i=2 ; i<=n ; ++i)
			factor.push_back(i) ;

		int p = 1 ;

		for( int j=k+n-1 ; j>k-1 ; --j)
		{
			int t=j ;

			for( list<int>::iterator l=factor.begin() ; l!=factor.end() ; )
			{
				int g1 = gcd( *l , t ) ;

				if( g1 > 1)
				{
					t /= g1 ;
					(*l) /= g1 ;
				}

				int g2 = gcd( *l , p ) ;

				if( g2 > 1)
				{
					p /= g2 ;
					(*l) /= g2 ;
				}

				if( *l == 1 )
				{
					list<int>::iterator d=l ;
					++l ;
					factor.erase(d) ;
					continue ;
				}
				l++ ;
			}
			p *= t ;
			p%=1000000 ;
		}

		for( list<int>::iterator l=factor.begin() ; l!=factor.end() ; ++l)
		{
			p /= (*l) ;
		}
		

		cout << p << endl ;

	}

	return 0 ;
}