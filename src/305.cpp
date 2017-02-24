
/* @JUDGE_ID: 7008MR 305 C++ */

#include<stdio.h>

const long int table[14] = { 2,7,5,30,169,441,1872,7632,1740,93313,459901,1358657,2504881} ;

int main(){
	int n ;
	while(scanf("%d",&n)){
        if(n==0)
			break ;
        printf("%ld\n",table[n-1]) ;
    }
	return 0 ;
}
