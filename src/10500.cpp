
#include<cstdio>

int main()
{
	int i,j ;
	int N,M ;
	int xini,yini,step ;
	int map[12][12] , ans[12][12] , visit[12][12] ;

	char ch[3] ;

	while( true )
	{
		scanf("%d%d",&N,&M) ;
		if(N==0 || M==0)
			break ;
		for(i=0;i<12;i++)
		{
			for(j=0 ; j<12; j++)
			{
				map[i][j] = 1  ;
				ans[i][j] = -1 ;
				visit[i][j] = 1 ;
			}
		}
		scanf("%d%d",&xini,&yini) ;
		step = 0 ;

		for(i=1 ; i<=N ; i++)
		{
			for(j=1 ; j<=M ; j++)
			{
				scanf("%s",ch) ;
				visit[i][j] = map[i][j] = (ch[0]=='X')?1:0 ;
			}
		}

		while(true)
		{
			visit[xini][yini] = 1 ;
			map[xini][yini] = ans[xini][yini] = 0 ;
			ans[xini-1][yini] = map[xini-1][yini] ;
			ans[xini][yini+1] = map[xini][yini+1] ;
			ans[xini+1][yini] = map[xini+1][yini] ;
			ans[xini][yini-1] = map[xini][yini-1] ;

			if(visit[xini-1][yini]==0)
			{
				step++ ;
				xini-- ;
				continue ;
			}
			if(visit[xini][yini+1]==0)
			{
				step++ ;
				yini++ ;
				continue ;
			}
			if(visit[xini+1][yini]==0)
			{
				step++ ;
				xini++ ;
				continue ;
			}
			if(visit[xini][yini-1]==0)
			{
				step++ ;
				yini-- ;
				continue ;
			}
			break ;
		}

		printf("\n") ;
		for(j=0;j<M;j++)
			printf("|---") ;
		printf("|\n") ;
		for(i=1;i<=N;i++)
		{
			for(j=1;j<=M;j++)
			{
				if(ans[i][j]==0)
					printf("| 0 ") ;
				else if(ans[i][j]==1)
					printf("| X ") ;
				else 
					printf("| ? ") ;
			}
			printf("|\n") ;
			for(j=0;j<M;j++)
				printf("|---") ;
			printf("|\n") ;
		}
		printf("\nNUMBER OF MOVEMENTS: %d\n",step) ;
	}

	return 0 ;
}