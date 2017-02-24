
/* @JUDGE_ID:7008MR 10212 C++ */

#include<stdio.h>

int main(){
	long int num[20000],N,M ;
	int i ;
	while(scanf("%ld %ld",&N,&M)==2){
		num[0]=1 ;
		for(i=1;i<20000;i++) num[i] = 0 ;
		while(M--){
			for(i=0 ; i<20000 ; i++)
				num[i] *= N ;
			for(i=0 ; i<20000 ; i++){
				if(num[i]>9){
					num[i+1] += num[i]/10 ;
					num[i] %= 10 ;
				}
			}
			N-- ;
		}
		for(i=0;i<20000;i++){
			if(num[i]!=0)
				break ;
		}
		printf("%d\n",num[i]) ;
	}
	return 0 ;
}