
#include<cstdio>

int main()
{
	double n,i ;

	while(scanf("%lf",&n)==1)
	{
		i = 1.0 ;
		while(true)
		{
			i*=9 ;
			if(i>=n){	
				printf("Stan wins.\n") ;
				break ;
			}
			i*=2 ;
			if(i>=n){
				printf("Ollie wins.\n") ;
				break ;
			}
		}
	}

	return 0 ;
}