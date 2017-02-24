
#include<cstdio>
#include<cmath>

const double pi = acos(-1.0) ;

int main()
{
	int n,i ;
	double A,R,r,ans1,ans2 ;
	
	i=1 ;
	while(scanf("%d %lf",&n,&A)==2)
	{
		if( n<3 ) break ;

		R = sqrt((2*A)/(n*sin(2*pi/n))) ;
		r = R*cos(pi/n) ;
		ans1 = (R*R*pi)-A ;
		ans2 = A - (r*r*pi) ;

		printf("Case %d: %.5lf %.5lf\n",i++,ans1,ans2) ;
	}

	return 0 ;
}