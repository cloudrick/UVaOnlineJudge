
#include<cstdio>
#include<cmath>

int main()
{
	double S,D,N ;

	while(scanf( "%lf%lf" , &S,&D )==2)
	{
		N = sqrt(2*D+pow(S,2.0)-S) ;

		for(;;N--){
			if(pow(N,2.0)+N < (2*D+pow(S,2.0)-S))
				break ;
		}

		printf("%.0lf\n",N+1) ;
	}

	return 0 ;
}