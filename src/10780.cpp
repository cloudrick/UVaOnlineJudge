

#include<iostream>

using namespace std ;

int main()
{
	int t ;
	cin >> t ;

	for( int tt=1 ; tt<=t ; ++tt )
	{
		int i,j ;

		int m,n ;
		cin >> m >> n ;

		int m_factor[1000] ;
		int pow_m_factor[1000] ;
		int num_m_factor = 0 ;

		j=m ;
		for( i=2 ; j!=1 ; ++i)
		{
			if( j%i==0)
			{
				m_factor[num_m_factor] = i ;
				pow_m_factor[num_m_factor] = 0 ;
				while( j%i==0)
				{
					j/=i ;
					pow_m_factor[num_m_factor]++ ;
				}
				num_m_factor++ ;
			}
		}

		int n_factor[1000] ;

		for( i=0 ; i<num_m_factor ; ++i) 
			n_factor[i] = 0 ;

		for( i=2 ; i<=n ; ++i)
		{
			int k=i ;
			for( j=0 ; j<num_m_factor ; ++j)
			{
				int c=0 ;
				while( k%m_factor[j] == 0 )
				{
					c++ ;
					k/= m_factor[j] ;
				}
				n_factor[j] += c ;
			}
		}

		int min = 10000 ;

		for( i=0 ; i<num_m_factor ; ++i)
		{
			n_factor[i] /= pow_m_factor[i] ;

			if( n_factor[i] < min )
				min = n_factor[i] ;
		}

		cout << "Case " << tt << ":" << endl ;

		if( min==10000 || min==0)
			cout << "Impossible to divide" << endl ;
		else
			cout << min << endl ;
	}

	return 0 ;
}