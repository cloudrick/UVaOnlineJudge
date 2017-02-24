
#include<stdio.h>
#include<math.h>

long int sum(int n){
	if(n==1) return 1 ;
	else return n*(n-1)/2 ;
}

long int gcd(long int a,long int b){
	while(a)
		a^=b^=a^=b%=a ;
	return b ;
}

int main()
{
	long int n,nn,dd,i,j ;
	long int num[60] ;

	while(scanf("%d",&n)==1){
		if(n==0) break ;
		for(i=0;i<n;i++)
			scanf("%ld",&num[i]) ;
		dd = sum(n) ;
		nn = 0 ;
		for(i=0 ; i<n-1 ; i++){
			for(j=i+1 ; j<n ; j++){
				if(gcd(num[i],num[j])==1)
					nn++ ;
			}
		}
		if(nn==0)
			printf("No estimate for this data set.\n") ;
		else
			printf("%.6lf\n",sqrt(6.0*dd/nn)) ;
	}

	return 0 ;
}