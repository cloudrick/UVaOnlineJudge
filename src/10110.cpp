
#include<cstdio>
#include<cmath>

int main()
{
	unsigned long n,m ;

	while(scanf("%u",&n)==1)
	{
		if(!n) break ;
		m = (unsigned long)sqrt(n) ;
		if(pow(m,2)==n)
			printf("yes\n") ;
		else
			printf("no\n") ;
	}

	return 0 ;
}