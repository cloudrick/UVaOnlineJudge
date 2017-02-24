
/* @JUDGE_ID: 7008MR 264 C++ */

#include<stdio.h>

int main(){
	long int n,i ;
	bool d ;
	while(scanf("%ld",&n)==1){
		printf("TERM %ld ",n) ;
		d = true ;
		i=1 ;
		while(n>i){
			n -= i ;
			i++ ;
			d = (d==true)? false : true ;
		}
		if(d)
			printf("IS %ld/%ld\n",i-n+1,n) ;
		else
			printf("IS %ld/%ld\n",n,i-n+1) ;
	}
	return 0 ;
}