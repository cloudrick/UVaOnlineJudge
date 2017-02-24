
 /* @JUDGE_ID: 7008MR 488 C++ */

#include<stdio.h>

int main(){
	int nnn,i,j,k,n,m ;
	
	scanf("%d",&nnn) ;

	for(;nnn>0;nnn--){
		scanf("%d %d",&n,&m) ;
		for(k=1 ; k<=m ; k++){
			if(k!=1)
				printf("\n") ;
			for(i=1 ; i<=n ; i++){
				for(j=1 ; j<=i ; j++)
					printf("%d",i) ;
				printf("\n") ;
			}
			if(n!=1){
				for(i=n-1 ;i>0 ; i--){
					for(j=1 ; j<=i ; j++)
        				printf("%d",i) ;
	        		printf("\n") ;
				}
			}
		}
	}
	return 0 ;
}