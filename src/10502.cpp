
#include<cstdio>

int count_up(int map[102][102],int x,int y)
{
	int tmp=0 ;
	for(int i=x-1 ; i>0 ; i--)
	{
		if(map[i][y]==1)
			tmp++ ;
		else
			break ;
	}
	return tmp ;
}

int count_left(int map[102][102],int x,int y)
{
	int tmp=0 ;
	for(int j=y-1 ; j>0 ; j--)
	{
		if(map[x][j]==1)
			tmp++ ;
		else
			break ;
	}
	return tmp ;
}

bool is_rect(int map[102][102],int x1,int y1,int x2,int y2)
{
	for(int i=x1 ; i<=x2 ; i++)
	{
		for(int j=y1 ; j<=y2 ; j++)
		{
			if(map[i][j]==0)
				return false ;
		}
	}
	return true ;
}

int count_up_left(int map[102][102],int x,int y)
{
	int tmp=0 ;

	for(int i=x-1 ; i>0 && map[i][y]==1 ; i--)
	{
		for(int j=y-1 ; j>0 ; j--)
		{
			if(is_rect(map,i,j,x,y))
				tmp++ ;
			else
				break ;
		}
	}
	return tmp ;
}

int main()
{
	int n,m ;
	int i,j ;
	char tmp[102] ;
	int map[102][102] ;
	long int ans ;

	while( scanf("%d",&n) == 1 )
	{
		if(!n) break ;
		scanf("%d",&m) ;

		for( i=0 ; i<102 ; i++)
		{
			for( j=0 ; j<102 ; j++)
				map[i][j] = 0 ; 
		}

		for(i=1 ; i<=n ; i++)
		{
			scanf("%s",tmp) ;
			for(j=1 ; j<=m ; j++)
				map[i][j] = tmp[j-1] - '0' ;
		}

		ans = 0 ;

		for(i=1 ; i<=n ; i++)
		{
			for(j=1 ; j<=m ; j++)
			{
				if(map[i][j]==1)
				{
					ans++ ;
					ans += count_up(map,i,j) ;
					ans += count_left(map,i,j) ;
					ans += count_up_left(map,i,j) ;
				}
			}
		}
		printf("%ld\n",ans) ;
	}

	return 0 ;
}