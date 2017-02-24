
#include<cstdio>

bool all_false(bool *man , int n)
{
	for( int i=0 ; i<n ; i++)
	{
		if(man[i])
			return false ;
	}
	return true ;
}

int count_false(bool *man , int n)
{
	int x = 0 ; 
	for( int i=0 ; i<n ; i++)
	{
		if( !man[i] )
			x++ ;
	}
	return x ;
}

int main()
{
	int N,X,nn,x,n,i,j,k ;

	bool man[51] ;

	nn=1 ;

	while( scanf("%d",&N) == 1 ) 
	{
		scanf("%d",&X) ;

		X = N-X ;

		for( i=0 ; i<51 ; i++ )
			man[i] = true ;
		
		x=0 ;

		for( i=0 ; i<20 ; i++)
		{
			scanf("%d",&n) ; 
			if( all_false(man,N) || x>=X)
				continue ;
		
			k = 0 ;

			for ( j=0 ; j<N ; j++)
			{
				if( count_false(man,N) >= X) 
					break ;
				if( man[j] )
				{
					k++ ;
					if(k==n)
					{
						man[j] = false ;
						x++ ;
						k=0 ;
					}
				}
			}

		}

		printf("Selection #%d\n",nn++) ;

		for( i=0 ; i<N ; i++)
		{
			if( man[i] ) 
				printf("%d ",i+1) ;
		}

		printf("\n\n") ;

	}

	return 0 ;
}