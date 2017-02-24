
#include<cstdio>

long int n,p,ANS,ans,num[101] ;
int stack[101] ;

bool solved ;


void DFS(int depth)
{
	if(solved)
		return ;

	if( p==depth )
	{
		if( ans == ANS )
		{
			for( int i=0 ; i<p-1 ; i++)
			{
				printf("%d",num[i]) ;
				switch(stack[i])
				{
				case 1 : printf("+") ; break ;
				case 2 : printf("-") ; break ;
				case 3 : printf("*") ; break ;
				case 4 : printf("/") ; break ;
				}
			}
			printf("%d=%d\n",num[p-1],ans) ;
			solved = true ;
			return ;
		}
		else
			return ;
	}

	if( ans % num[depth] == 0 && ans / num[depth] <= 32000 && !solved)
	{
		ans /= num[depth] ;
		stack[depth-1] = 4 ;
		DFS(depth+1) ;
		ans *= num[depth] ;
	}
	
	if( ans * num[depth] <= 32000 && !solved )
	{
		ans *= num[depth] ;
		stack[depth-1] = 3 ;
		DFS(depth+1) ;
		ans /= num[depth] ;
	}

	if( ans + num[depth] <= 32000 && !solved)
	{
		ans += num[depth] ;
		stack[depth-1] = 1 ;
		DFS(depth+1) ;
		ans -= num[depth] ;
	}
	if( ans - num[depth] >= -32000 && !solved )
	{
		ans -= num[depth] ;
		stack[depth-1] = 2 ;
		DFS(depth+1) ;
		ans += num[depth] ;
	}
}

int main()
{
	int i ;

	scanf("%d",&n) ;

	while(n--)
	{
		scanf("%d",&p) ;
		for( i=0 ; i<p ; i++)
			scanf("%d",&num[i]) ;
		scanf("%d",&ANS) ;
		solved = false ;
		ans = num[0] ;
		DFS(1) ;
		if(!solved)
			printf("NO EXPRESSION\n") ;
	}

	return 0 ;
}