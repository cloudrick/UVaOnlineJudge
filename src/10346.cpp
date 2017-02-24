
#include<stdio.h>

int main()
{
	long int n,k,sum,tmp ;

	while(scanf("%ld%ld",&n,&k)==2){
		sum=0 ;
		while(n>0){
			if(n>=k){
				tmp=n ;
				sum += k*(n/k) ;
				tmp -= k*(n/k);
				tmp += (n/k) ;
				n=tmp ;
				if(n==0)
					n++;
			}
			else{
				sum+=n ;
				n=0 ;
			}
		}
		printf("%ld\n",sum) ;
	}

	return 0 ;
}