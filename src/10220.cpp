
#include<stdio.h>

int main()
{
	int d[5000],n,i,j ;
	long int sum ;
	while(scanf("%d",&n)==1){
		for(i=0;i<5000;i++)
			d[i]=0 ;
		sum=0 ;
		d[0]=1;
		for(i=2;i<=n;i++){
			for(j=0;j<5000;j++)
				d[j]*=i ;
			for(j=0;j<4999;j++){
				if(d[j]>9){
					d[j+1] += d[j]/10 ;
					d[j] %= 10 ;
				}
			}
		}
		for(i=0;i<5000;i++)
			sum += d[i] ;
		printf("%ld\n",sum) ;
	}
	return 0 ;
}