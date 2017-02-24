
#include<cstdio>
#include<cmath>

const double pi = acos(-1) ;

int main()
{
	double r,n ;

	while( scanf("%lf %lf",&r,&n)==2 )
	{	
		if(n<=2){
			printf("0.000\n") ;
			continue ;
		}
	
		printf("%.3lf\n",0.5*n*r*r*sin(2*pi/n)) ;
	}

	return 0 ;
}