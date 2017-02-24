
#include<cstdio>
#include<cmath>

const double pi = 3.141592653589793 ;

inline void doing(double &a,double &b)
{
	double tmp = -a ;
	a = b ;
	b = tmp ;
}

int main()
{
	double x1,x2,x3,x4,x5,y1,y2,y3,y4,y5 ;
	double v1x,v1y,v2x,v2y ;
	double x,y ;
	double a,b,c ;

	while( scanf("%lf%lf%lf%lf%lf%lf" ,&x3,&y3,&x4,&y4,&x5,&y5) == 6)
	{
		x1 = (x4+x3)/2 ;
		y1 = (y4+y3)/2 ;
		x2 = (x5+x4)/2 ;
		y2 = (y5+y4)/2 ;

		v1x = x4-x3 ;
		v1y = y4-y3 ;
		v2x = x5-x4 ;
		v2y = y5-y4 ;

		doing(v1x,v1y) ;
		doing(v2x,v2y) ;

		a = (v1x*(-v2y)) + (v2x*v1y) ;
		b = ((x2-x1)*(-v2y)) + ((v2x)*(y2-y1)) ;
		c = (v1x*(y2-y1)) - ((x1-x2)*v1y) ;

		x = x1 + ((b/a)*v1x) ;
		y = y1 + ((b/a)*v1y) ;

		printf("%.2lf\n",2*sqrt(pow(x-x5,2)+pow(y-y5,2))*pi) ;

	}

	return 0 ;
}