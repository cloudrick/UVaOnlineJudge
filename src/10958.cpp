
#include <iostream>
#include <list>

using namespace std ;

int i,j,k ;

int main()
{
	list<int> Prime ;

	bool *ptmp = new bool[1100] ;

	for( i=0 ; i<1100 ; ++i)
		ptmp[i] = true ;

	for( i=2 ; i<1100 ; ++i)
	{
		if( ptmp[i] == true )
		{
			Prime.push_back(i) ;

			for( j=2 ; i*j<1100 ; ++j)
			{
				ptmp[i*j] = false ;
			}
		}
	}

	delete [] ptmp ;

	for(int c=1 ;; ++c )
	{
		int m,n,p ;

		cin >> m >> n >> p ;

		if( m==0 && n==0 && p==0 )
			break ;

		m*=p ;
		n*=p ;

		int total = 1 ;

		for( list<int>::iterator ii=Prime.begin() ;ii!=Prime.end() ; ++ii)
		{
			int tmp = 0 ;

			if( m%(*ii) == 0 )
			{
				while( m%(*ii) == 0 )
				{
					++tmp ;
					m /= (*ii) ;
				}
			}
			if( n%(*ii) == 0 )
			{
				while( n%(*ii) == 0 )
				{
					++tmp ;
					n /= (*ii) ;
				}
			}
			total *= tmp+1 ;
		}

		cout << "Case " << c << ": " << 2*total - 1 << endl ;
	}

	return 0 ;
}