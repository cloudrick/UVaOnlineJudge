
#include<iostream>
#include<string>

using namespace std ;

int main()
{
	int case_num ;

	cin >> case_num ;

	while( case_num-- )
	{
		int i,j ;
		int map[60][60] ;
		int n,m ;

		cin >> m >> n ;

		for( i=0 ; i<m ; ++i)
		{
			string tmp ;
			cin >> tmp ;
			for( j=0 ; j<n ; ++j)
			{
				if( tmp[j] >= 'A' && tmp[j]<='Z' )
					map[i][j] = tmp[j] - 'A' + 'a' ;
				else
					map[i][j] = tmp[j] ;

			}
		}
	
		int k ;
		cin >> k ;

		while(k--)
		{
			string tmp ;
			cin >> tmp ;

			for( i=0 ; i<tmp.size() ; ++i)
			{
				if( tmp[i] >='A' && tmp[i] <= 'Z')
					tmp[i] = tmp[i] - 'A' + 'a' ;
			}

			bool done = false ;

			for( i=0 ; i<m && !done; ++i)
			{
				for( j=0 ; j<n && !done ; ++j)
				{
					bool R,L,U,D,LU,LD,RU,RD ;
					R=L=U=D=LU=LD=RU=RD=true ;

					for( int t=0 ; t<tmp.size() ; ++t)
					{
						// right
						if( j+t < n && R )
						{
							if( map[i][j+t] != tmp[t] )
								R = false ;
						}
						else
						{
							R = false ;
						}
						// left
						if( j-t >= 0 && L )
						{
							if( map[i][j-t] != tmp[t] )
								L = false ;
						}
						else
						{
							L = false ;
						}

						// up
						if( i-t >=0  && U )
						{
							if( map[i-t][j] != tmp[t] )
								U = false ;
						}
						else
						{
							U = false ;
						}
						// down
						if( i+t < m  && D )
						{
							if( map[i+t][j] != tmp[t] )
								D = false ;
						}
						else
						{
							D = false ;
						}

						// LU
						if( i-t>=0 && j-t>=0  && LU )
						{
							if( map[i-t][j-t] != tmp[t] )
								LU = false ;
						}
						else
						{
							LU = false ;
						}
						// LD
						if( i+t<m && j-t>=0  && LD  )
						{
							if( map[i+t][j-t] != tmp[t] )
								LD = false ;
						}
						else
						{
							LD = false ;
						}
						// RU
						if( i-t>=0 && j+t<n  && RU  )
						{
							if( map[i-t][j+t] != tmp[t] )
								RU = false ;
						}
						else
						{
							RU = false ;
						}
						// RD
						if( i+t<m && j+t<n  && RD  )
						{
							if( map[i+t][j+t] != tmp[t] )
								RD = false ;
						}
						else
						{
							RD = false ;
						}
					}

					if( R||L||U||D||LU||LD||RU||RD)
					{
						cout << i+1 << ' ' << j+1 << endl ;
						done = true ;
						break ;
					}
				}
			}
		}

		if( case_num !=0 )
			cout << endl ;

	}

	return 0 ;	
}