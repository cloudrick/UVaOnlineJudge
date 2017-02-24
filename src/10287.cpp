
#include<cstdio>
#include<cmath>

int main()
{
	double n,r1 ;

	while(scanf("%lf",&n)==1)
	{
		if(n==0.0){
			printf("0.0000000000 0.0000000000 0.0000000000 0.0000000000\n") ;
			continue ;
		}
		r1 = sqrt(3)*n/2 ;
		printf("%.10lf ",r1) ;
		printf("%.10lf ",(2*n)/(2+(4/sqrt(3)))) ;
		printf("%.10lf ",sqrt(3)*n/4) ;
		printf("%.10lf\n",r1*sqrt(r1*r1 + n*n)/(2*r1 + sqrt(r1*r1 + n*n))) ;
	}

	return 0 ;
}