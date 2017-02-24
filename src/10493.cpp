
#include<cstdio>

int main()
{
	long int n,m ;

	while( scanf("%ld%ld",&n,&m)==2 )
	{
		if(!n) break ;

		printf("%ld %ld ",n,m) ;
		if(n==1 && m!=1) printf("Impossible\n") ;
		else if(n==1 && m==1) printf("Multiple\n") ;
		else
		{
			long int k=m ;
			while(k>=n) 
				k-=(n-1) ;
			if(k==1) 
				printf("%ld\n",(n*m-1)/(n-1)) ;
			else 
				printf("Impossible\n") ;
		}
	}
	return 0 ;
}