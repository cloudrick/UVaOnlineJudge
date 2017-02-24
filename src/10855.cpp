
#include <iostream>
#include <cstdio>

using namespace std ;

int main()
{
	int n,N ;

	int i,j ;

	while( scanf("%d%d",&N,&n) == 2 )
	{
		if( N==0 && n==0 )
			break ;

		char **MAP,**map ;

		MAP = new char* [N] ;
		for( i=0 ; i<N ; ++i)
		{
			MAP[i] = new char [N+1] ;
			scanf("%s",MAP[i]) ;
		}

		map = new char* [n] ;
		for( i=0 ; i<n ; ++i)
		{
			map[i] = new char[n+1] ;
			scanf("%s",map[i]) ;
		}

		int c1=0,c2=0,c3=0,c4=0 ;

		int a = 0 ;
		for( i=0 ; i<N-n+1 ; ++i)
		{
			for( j=0 ; j<N-n+1 ;++j)
			{
				char flag = 0x0F;

				for(int k=0 ; k<n && flag ;++k)
				{
					for( int m=0 ; m<n && flag ; ++m)
					{
						if( MAP[i+k][j+m] != map[k][m] )
						{
							flag &= 0x0E ;
						}
						if( m==n-1 && k==n-1 && (flag & 1) )
						{
							c1++ ;
						}


						if( MAP[i+k][j+m] != map[n-m-1][k] )
						{
							flag &= 0x0D ;
						}
						if( m==n-1 && k==n-1 && (flag&2) )
						{
							c2++ ;
						}


						if( MAP[i+k][j+m] != map[n-k-1][n-m-1] )
						{
							flag &= 0x0B ;
						}
						if( m==n-1 && k==n-1 && (flag&4) )
						{
							c3++ ;
						}


						if( MAP[i+k][j+m] != map[m][n-k-1] )
						{
							flag &= 0x07 ;
						}
						if( m==n-1 && k==n-1 && (flag&8) )
						{
							c4++ ;
						}
					}
				}
			}
		}

		printf("%d %d %d %d\n",c1,c2,c3,c4) ;

		for( i=0 ; i<N ; ++i)
		{
			delete [] MAP[i]  ;
		}
		delete [] MAP ;

		for( i=0 ; i<n ; ++i)
		{
			delete [] map[i]  ;
		}
		delete [] map ;
	}


	return 0 ;
}