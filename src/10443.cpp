
#include<cstdio>

int main()
{
	int t_main[102][102],t_tmp[102][102] ;
	int n,r,c,d ;

	int i,j ;
	char tmp_in[105] ;

	scanf("%d",&n) ;

	while(n--)
	{
		scanf("%d%d%d",&r,&c,&d) ;

		for(i=0 ; i<102 ; i++)
		{
			for(j=0 ; j<102; j++)
			{
				t_main[i][j] = t_tmp[i][j] = -1 ;
			}
		}

		for( i=0 ; i<r ; i++)
		{
			scanf("%s",tmp_in) ;
			for(j=0 ; j<c ; j++)
			{
				if( tmp_in[j] == 'R' )
					t_main[i][j] = 2 ;
				else if( tmp_in[j] == 'S' )
					t_main[i][j] = 1 ;
				else if( tmp_in[j] == 'P' )
					t_main[i][j] = 0 ;
			}
		}

		while(d--)
		{
			for( i=0 ; i<r ; i++)
			{
				for( j=0 ; j<c ; j++)
				{
					if( i!=0 )
					{
						if( (t_main[i-1][j]+1)%3 == t_main[i][j] )
							t_tmp[i-1][j] = t_main[i][j] ;
						else if(t_tmp[i-1][j]==-1)
							t_tmp[i-1][j] = t_main[i-1][j] ;
					}
					if( i!=r-1)
					{
						if( (t_main[i+1][j]+1)%3 == t_main[i][j] )
							t_tmp[i+1][j] = t_main[i][j] ;
						else if(t_tmp[i+1][j]==-1)
							t_tmp[i+1][j] = t_main[i+1][j] ;
					}
					if( j!=0)
					{
						if( (t_main[i][j-1]+1)%3 == t_main[i][j] )
							t_tmp[i][j-1] = t_main[i][j] ;
						else if(t_tmp[i][j-1]==-1)
							t_tmp[i][j-1] = t_main[i][j-1] ;
					}
					if( j!=c-1)
					{
						if( (t_main[i][j+1]+1)%3 == t_main[i][j] )
							t_tmp[i][j+1] = t_main[i][j] ;
						else if(t_tmp[i][j+1]==-1)
							t_tmp[i][j+1] = t_main[i][j+1] ;
					}
				}
			}
			for( i=0 ; i<r ; i++)
			{
				for(j=0 ; j<c ; j++)
				{
					if(t_tmp[i][j] != -1 )
						t_main[i][j] = t_tmp[i][j] ;
					t_tmp[i][j] = -1 ;
				}
			}
		}

		for( i=0 ; i<r ; i++)
		{
			for(j=0 ; j<c ; j++)
			{
//				printf("%d",t_main[i][j]) ;
				
				if( t_main[i][j] == 0 )
					printf("P") ;
				else if ( t_main[i][j] == 1 )
					printf("S") ;
				else if( t_main[i][j] == 2 ) 
					printf("R") ;
					
					
			}
			printf("\n") ;
		}
		printf("\n") ;

	}

	return 0 ;
}