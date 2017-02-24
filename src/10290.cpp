
#include<stdio.h>
#include<math.h>

int main()
{
	double nn,n,a,sum ;
	while(scanf("%lf",&nn)==1){
		sum=0 ;
		for(n=1.0;n<=100000.0;n++){
			a = (((2.0*nn)/n)+1.0-n)/2.0 ;
			if((n*(2*a+n-1)/2)==nn)
				sum++ ;
		}
		printf("%.0lf\n",sum) ;
	}
	return 0 ;
}
