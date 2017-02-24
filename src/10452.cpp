
#include<cstdio>

const char str[8] = "IEHOVA#" ;

int main()
{
	char map[9][9] ;
	int N,n,m,x,y ;
	int i,k ;

	scanf("%d",&N) ;

	while(N--)
	{
		scanf("%d%d",&n,&m) ;

		for( i=0 ; i<n ; i++ )
			scanf("%s",map[i]) ;
		for(i=0 ; i<m ; i++)
		{
			if( map[n-1][i] == '@')
			{
				x = n-1 ;
				y = i ;
			}
		}
		k = 0 ;
		while( k<=6 )
		{
			if( y>0){
				if(map[x][y-1] == str[k]){
					printf("left ") ;
					k++ ;
					y-- ; 
					continue ;
				}
			}
			if(x>0){
				if(map[x-1][y] == str[k]){
					printf("forth ") ;
					k++ ;
					x-- ;
					continue ;
				}
			}
			if( y<m-1){
				if( map[x][y+1] == str[k] ){
					printf("right ") ;
					k++ ;
					y++ ;
					continue ;
				}
			}
		}
		printf("\n") ;
	}

	return 0 ;
}