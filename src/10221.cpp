
#include<stdio.h>
#include<math.h>

const double R = 6440.0 ;
const double pi = 3.14159265358979323846264 ;

int main()
{
	double s,a ;
	char str[5] ;
	while(scanf("%lf %lf %s",&s,&a,str)==3){
		if(str[0]=='m')
			a = (360*(a/21600)) ;
		if(a>180) a=360-a ;
		printf("%.6f %.6lf\n",2*pi*(s+R)*(a/360),(R+s)*sin(pi*((a/2)/180))*2) ;
	}
	return 0 ;
}