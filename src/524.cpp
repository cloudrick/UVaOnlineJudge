
#include<cstdio>

int n ;
bool used[17] ;
int stack[16],len ;

inline bool prime(int n)
{
	if( n==2 || n==3 || n==5 || n==7 || n==11 || n==13 ||
		n==17 || n==19 || n==23 || n==29 || n==31 )
		return true ;
	return false ;
}

void DFS()
{
	int i ;

	if( len == n )
	{
		if( prime (stack[len-1] + 1 ))
		{
			for( i=0 ; i<n ; i++)
				printf("%d ",stack[i]) ;
			printf("\n") ;
		}
		return ;
	}

	for( i=1 ; i<=n ; i++)
	{
		if( used[i] == false )
		{
			if( prime(stack[len-1]+i))
			{
				stack[len++] = i ;
				used[i] = true ;
				DFS() ;
				used[i] = false ;
				len-- ;
			}
		}
	}

}

int main()
{
	int nn,i ;

	nn=1 ;

	while( scanf("%d",&n) == 1)
	{
		for( i=0 ; i<17 ; i++)
			used[i] = false ;

		printf("Case %d:\n",nn++) ;

		len = 1 ;
		used[1] = true ;
		stack[0] = 1 ;

		DFS() ;
	}

	return 0 ;
}