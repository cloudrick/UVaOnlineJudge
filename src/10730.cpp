
#include<iostream>
#include<string>

using namespace std ;

int main()
{
	while(true)
	{
		string tmp ;
		cin >> tmp ;
		int n = 0 ;

		int i ;
		for( i=0 ; tmp[i]!= ':' && i<tmp.size() ; ++i)
		{
			n = n*10 + tmp[i] - '0' ;
		}

		if( n==0 )
			break ;

		int sequence[10000] ;
		int location[10000] ;

		for( i=0 ; i<n ; ++i)
		{
			int m ;
			cin >> m ;
			sequence[i] = m ;
			location[m] = i ;
		}

		bool yes = true ;

		for( i=0 ; i<n && yes ; ++i)
		{
			for( int j=i+1 ; j<n && yes ; ++j)
			{
				int d = sequence[j] - sequence[i] ;
				int k = sequence[j] + d ;

				if( k<0 || k>=n )
					continue ;

				if( location[k]>j )
				{
					yes = false ;
					break ;
				}
			}
		}

		if(yes)
			cout << "yes" << endl ;
		else
			cout << "no"  << endl ;

	}

	return 0 ;
}