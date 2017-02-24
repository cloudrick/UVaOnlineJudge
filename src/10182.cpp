
/* @JUDGE_ID: 7008MR 10182 C++ */

#include<stdio.h>

int main(){

	long int n ;
	int x,y ;
	int i,j,k ;

	while(scanf("%ld",&n)==1){
		x=y=0 ;
		for(i=1,j=1 ; i<n ; j++){
			if(i==1)
			{ y++ ; i++ ; }
			for(k=1 ; k<=j && i<n ; k++)
			{ x-- ; i++ ; }
			for(k=1 ; k<=j && i<n ; k++)
			{ y-- ; i++ ; }
			for(k=1 ; k<=j && i<n ; k++)
			{ y-- ; x++ ; i++ ; }
			for(k=1 ; k<=j && i<n ; k++)
			{ x++ ; i++ ; }
			for(k=1 ; k<=j && i<n ; k++)
			{ y++ ; i++ ; }
			if(i<n)
			{ y++ ; i++ ; }
			for(k=1 ; k<=j && i<n ; k++)
			{ x-- ; y++ ; i++ ; }
		}
		printf("%d %d\n",x,y) ;
	}
	return 0 ;
}