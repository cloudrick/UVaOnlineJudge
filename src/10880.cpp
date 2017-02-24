
#include<iostream>
#include<cmath>
#include<set>

using namespace std ;

int main()
{
	int N ;
	cin >> N ;

	for(int n=1;n<=N;++n)
	{
		int C,R ;
		cin >> C >> R ;

		if( C==R )
		{
			cout << "Case #" << n << ": 0" << endl ;
			continue ;
		}

		int T = C-R ;
		set<int> Q ;

		for( int i=1 ; i<=sqrt(T) ; ++i)
		{
			if( T%i == 0 )
			{
				Q.insert(T/i) ;
				Q.insert(i) ;
			}
		}

		cout << "Case #" << n << ":" ;
		for( set<int>::iterator j=Q.begin() ; j!=Q.end() ; ++j )
		{
			if( (*j) > R  )
			{
				cout << ' ' << (*j) ;
			}
		}
		cout << endl ;
	}

	return 0 ;
}