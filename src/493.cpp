
#include <cstdio>

struct num
{
	long int y ;
	long int x ;
} data[200000] ;

long int data_len ;

const int MAX_DEPTH = 400 ;

bool judged[MAX_DEPTH][MAX_DEPTH] ;



inline long int gcd(long int a,long int b)
{
	while(b)
		b^=a^=b^=a%=b ;
	return a ;
}

inline bool exist(long int x,long int y)
{
	for( long int i=0 ; i<data_len ; i++)
	{
		if( data[i].x == x && data[i].y == y)
			return true ;
	}
	return false ;
}

inline void handle(long int x,long int y)
{
	bool flag = false ;
	long int g ;
	int i ;

	if( x==0 )
		return ;
	if( y==0)
	{
		x=1 ;
		if( exist(x,y) == false )
		{
			data[data_len].x = x ;
			data[data_len++].y = y ;
			for(  i=1 ; x*i<MAX_DEPTH ; i++)
				judged[x*i][0] = true ;
		}
		return ;
	}

	if( (y<0 && x>0)||( y>0 && x<0 ))
	{
		flag = true ;
	}

	x = x>0 ? x:-x ;
	y = y>0 ? y:-y ;

	g = gcd(x,y) ;

	x/=g ; 
	y/=g ;

	if( flag )
		y=-y ;
	if( exist(x,y) == false )
	{
		data[data_len].x = x ;
		data[data_len++].y = y ;
		judged[x][y] = true ;

		for( i=1 ; x*i<MAX_DEPTH && y*i<MAX_DEPTH ; i++)
		{
			judged[x*i][y*i] = true ;
		}

	}
}

int main()
{
	long int maxN ;
	long int n ;
	long int x,y ;
	long int i,j ;


	data_len = 0 ;
	x = y = 0 ;

	for( i=0 ; i<MAX_DEPTH ; i++)
	{
		for( j=0 ; j<MAX_DEPTH ; j++)
			judged[i][j] = false ;
	}

	for( maxN = 1 ; maxN<MAX_DEPTH ; maxN += 2 )
	{
		for( i=0 ; i<maxN ; i++)
		{
			y += 1 ;
			if(judged[x][y] == false )
				handle(x,y) ;
		}
		for( i=0 ; i<maxN ; i++)
		{
			x += 1 ;
			if(judged[x][y] == false )
				handle(x,y) ;
		}
		for( i=0 ; i<=maxN ; i++)
		{
			y -= 1 ;
			if(judged[x][y] == false )
				handle(x,y) ;
		}
		for( i=0 ; i<=maxN ; i++)
		{
			x -= 1 ;
			if(judged[x][y] == false )
				handle(x,y) ;
		}
	}

//	printf("%ld\n",data_len) ;

	while( scanf("%ld",&n)==1 )
	{
		printf("%d / %d\n",data[n].y,data[n].x) ;
	}

	return 0 ;
}