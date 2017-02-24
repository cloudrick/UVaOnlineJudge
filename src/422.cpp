
#include<cstdio>
#include<cstring>

const int LEFT = 1 , RIGHT = 2 , UP = 3 , DOWN = 4 ;

int x,y ;
bool find ;
char tmp[105] ;
int n,map[105][105] ;

void match( const int d , const int step , const int xx , const int yy )
{
	if ( step == int(strlen(tmp)) )
	{
		x = xx ; 
		y = yy ;
		find = true ;
		return ;
	}

	switch( d )
	{
	case LEFT :
		if( yy<=1) break ;
		if( map[xx][yy-1] == tmp[step] )
			match( LEFT , step+1 , xx , yy-1) ;
		break ;
	case RIGHT :
		if( yy>=n ) break ;
		if( map[xx][yy+1] == tmp[step] )
			match( RIGHT , step+1 , xx , yy+1) ;
		break ;
	case UP :
		if( xx<=1) break ;
		if( map[xx-1][yy] == tmp[step] )
			match( UP , step+1 , xx-1 , yy) ;
		break ;
	case DOWN :
		if( xx>=n ) break ;
		if( map[xx+1][yy] == tmp[step] )
			match( DOWN , step+1 , xx+1 , yy) ;
		break ;
	}
}

int main()
{
	int i,j ;
	int beginx , beginy ;

	scanf("%d",&n) ;

	for(i=0 ; i<105 ; i++)
	{
		for( j=0 ; j<105 ; j++)
			map[i][j] = -1 ;
	}

	for( i=1 ; i<=n ; i++)
	{
		scanf("%s",tmp) ;
		for( j=1 ; j<=n ; j++)
			map[i][j] = tmp[j-1] ;
	}

	while( scanf("%s",tmp) == 1 )
	{
		find = false ;
		if( tmp[0] == '0')
			break ;
		
		for( i=1 ; i<=n ; i++ )
		{
			for( j=1 ; j<=n ; j++)
			{
				if( map[i][j] == tmp[0] && find == false)
				{
					if( !find ) match( LEFT , 1 , i , j ) ;
					if( !find ) match( RIGHT , 1 , i , j ) ;
					if( !find ) match( UP , 1 , i , j ) ;
					if( !find ) match( DOWN , 1 , i , j ) ;
					if( find)
					{
						beginx = i ;
						beginy = j ;
					}
				}
			}
		}

		if( find )
		{
			printf("%d,%d %d,%d\n",beginx,beginy,x,y) ;
		}
		else
			printf("Not found\n") ;

	}
	

	return 0 ;
}