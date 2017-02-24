
/* @JUDGE_ID: 7008MR 299 C++ */

#include<stdio.h>

int main(){
	int counter,i,j,k,l,n ;
	int train[50] ;

	scanf("%d",&n) ;

    while(n--){
		scanf("%d",&l) ;
		for(i=0 ; i<l ; i++)
			scanf("%d",&train[i]) ;
		counter=0;
		for(i=0 ; i<l ; i++){
			for(j=0 ; j<l-1 ; j++){
				if(train[j]>train[j+1]){
					counter++ ;
                    k =train[j] ;
					train[j] = train[j+1] ;
					train[j+1] = k ;
				}
			}
		}
		printf("Optimal train swapping takes %d swaps.\n",counter);
	}
	return 0 ;
}
