
#include<cstdio>

int map[105][105] ;

bool isAllZero( int x1,int y1,int x2,int y2)
{
	for( int i=x1 ; i<=x2 ; i++)
	{
		for( int j=y1 ; j<=y2 ; j++)
		{
			if( map[i][j]==1 )
				return false ;
		}
	}
	return true ;
}

int count_area(int x,int y)
{
	int r = 0 ;
	for( int i=0 ; ; i++)
	{
		if( map[x-i][y]==1 )
			break ;
		for( int j=0 ; ; j++)
		{
			if( map[x-i][y-j]==1 )
				break ;
			if( isAllZero(x-i,y-j,x,y) )
			{
				if( (i+1)*(j+1) > r )
					r = (i+1)*(j+1) ;
			}
		}
	}
	return r ;
}

int main()
{
	int n,m ;
	int i,j ;

	int max_area ;

	while( scanf("%d%d",&n,&m)==2 )
	{
		if( n==0 && m==0)
			break ;

		for( i=0 ; i<105 ; i++)
		{
			for( j=0 ; j<105 ; j++)
			{
				map[i][j] = 1 ;
			}
		}

		max_area = 0 ;

		for( i=1 ; i<=n ; i++)
		{
			for( j=1 ; j<=m ; j++)
				scanf("%d",&map[i][j]) ;
		}

		for( i=1 ; i<=n ; i++)
		{
			for( j=1 ; j<=m ; j++)
			{
				int tmp = count_area(i,j) ;
				if( tmp > max_area )
					max_area = tmp ;
			}
		}

		printf("%d\n",max_area) ;

	}

	return 0 ;
}