
#include<stdio.h>

int main()
{
	double a0,an1,c[3010],a1 ;
	int n,i,N ;

	scanf("%d",&N) ;
	while(N--){
		while(scanf("%d",&n)==1){
			scanf("%lf %lf",&a0,&an1) ;
			for(i=0;i<n;i++)
				scanf("%lf",&c[i]) ;
			a1 = (double(n)*a0) + an1 ;
			for(i=0;i<n;i++)
				a1 -= 2*(c[i]*double(n-i)) ;
			a1 /= double(n+1) ;
			printf("%.2lf\n",a1) ;
		}
	}
	return 0 ;
}