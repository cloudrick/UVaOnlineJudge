
#include<stdio.h>
#include<math.h>

int main()
{
	double a,b,c,s ;

	while(scanf("%lf%lf%lf",&a,&b,&c)==3){
		if(a<=0.0||b<=0.0||c<=0.0||
			a+b<=c||b+c<=a||a+c<=b){
			printf("The radius of the round table is: 0.000\n") ;
			continue ;
		}
		s = (a+b+c)/2 ;
		printf("The radius of the round table is: %.3lf\n",2*sqrt(s*(s-a)*(s-b)*(s-c))/(a+b+c)) ;
	}
	return 0 ;
}