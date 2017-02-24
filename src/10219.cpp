
#include<stdio.h>
#include<math.h>

int main()
{
	double d1,d2,n,m,i ;
	while(scanf("%lf %lf",&n,&m)==2){
		d1=d2=0.0 ;
		for(i=0.0;i<m;i+=1.0)
			d1+=log10(n-i) ;
		for(i=2.0;i<=m;i+=1.0)
			d2+=log10(i) ;
		printf("%ld\n",long(d1-d2+1)) ;
	}
	return 0 ;
}