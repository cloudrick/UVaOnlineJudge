
#include<stdio.h>

long int solve(long int n)
{
	long int k=1 ;

	for(;n!=1;k++){
		if(n%2)
			n = n*3 + 1 ;
		else
			n /= 2 ;
	}
    return(k) ;
}

int main()
{
	long int i,j,t ;

	while( scanf( "%ld%ld" ,&i,&j)==2 )
	{

		printf("%ld %ld ",i,j) ;

		if(i>j)
			i^=j^=i^=j ;

		for(t=1;i<=j;i++)
		{
			if( solve(i) > t)
				t = solve(i) ;
		}

		printf("%ld\n" , t) ;
	}
	return 0 ;
}
