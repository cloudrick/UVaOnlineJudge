
#include<stdio.h>

int main()
{
	long int num[10010],n,i,j ;
	int table[10010] ;
	for(i=0;i<=10000;i++) num[i] = 0 ;
	num[0] = 1 ;

	for(i=1;i<=10000;i++){
		for(j=0;j<10000;j++)
			num[j]*= i ;
		for(j=0;j<9999;j++){
			if(num[j]>9){
				num[j+1] += num[j]/10 ;
				num[j] %= 10 ;
			}
		}
		for(j=0;j<10000;j++){
			if(num[j]){
				table[i] = num[j] ;
				break ;
			}
		}
	}

	while(scanf("%ld",&n)==1){
		printf("%5ld -> %ld\n",n,table[n]) ;
	}
	return 0 ;
}