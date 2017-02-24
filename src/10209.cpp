
#include<cstdio>

int main() { 

	double a; 

	while(scanf("%lf",&a)==1) 
	{ 
		printf("%.3lf %.3lf %.3lf\n", 
			a*a*0.3151467436277204526267681195873 ,
		    a*a*0.51129916633435233320910714410491 ,
		    a*a*0.17355409003792721416412473630779 ) ;
	} 
	return 0; 
}