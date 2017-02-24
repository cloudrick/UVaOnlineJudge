
#include<stdio.h>

const int prime[50]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97} ;

int main()
{
	int table[50],n,i,j,k,max ;
	bool sec ;

	while(scanf("%d",&n)==1){
		if(n==0)
			break ;
		for(i=0;i<50;i++) table[i]=0 ;
		sec = false ;
		max=0 ;
		for(i=2;i<=n;i++){
			k=i ;
			for(j=0;j<=24;j++){
				while(k%prime[j]==0){
					k/=prime[j] ;
					table[j]++ ;
					if(j>14)
						sec=true ;
					if(j>max)
						max=j ;
				}
			}
		}
		printf("%3d! =",n) ;
		for(i=0;i<=14 && i<=max;i++)
				printf("%3d",table[i]) ;
		printf("\n");
		if(sec){
			printf("      ") ;
			for(i=15;i<=24 && i<=max;i++)
				printf("%3d",table[i]) ;
			printf("\n") ;
		}
	}
	return 0 ;
}