
#include<stdio.h>
#include<math.h>

int main()
{
	double a,b,c,sina,cosa,sinb,cosb,sinc,cosc ;
	
	while(scanf("%lf%lf%lf",&a,&b,&c)==3){
		if(a<=0 || b<=0 || c<=0 ||
			a+b<=c || b+c<=a || a+c<=b ){
			printf("-1.000\n") ;
			continue ;
		}
		cosa = fabs(((b*b)+(c*c)-(a*a)) / (2*b*c)) ;
		cosb = fabs(((a*a)+(c*c)-(b*b)) / (2*a*c)) ;
		cosc = fabs(((a*a)+(b*b)-(c*c)) / (2*a*b)) ;
		sina = sin(acos(cosa)) ;
		sinb = sin(acos(cosb)) ;
		sinc = sin(acos(cosc)) ;
		printf("%.3f\n",((a*b*sinc) + (a*c*sinb) + (c*b*sina) )*2.0/9.0) ;
	}
	
	return 0 ;
}