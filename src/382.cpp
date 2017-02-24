
/* @JUDGE_ID: 7008MR 382 C++ */

#include<stdio.h>

int main(){
	long int sum,n,i ;
	printf("PERFECTION OUTPUT\n") ;

    while(1){
        scanf("%ld",&n) ;
        if(n==0)
			break ;
        printf("%5d  ",n) ;
        sum = 0 ;
        for(i=1 ; i<=n-1 ; i++){
            if(n%i==0)
                sum += i ;
		}
        if(sum==n)
        	printf("PERFECT\n") ;
        else if(sum<n)
        	printf("DEFICIENT\n") ;
        else
        	printf("ABUNDANT\n") ;
	}
    printf("END OF OUTPUT") ;

	return 0 ;
}
