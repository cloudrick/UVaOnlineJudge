
/* @JUDGE_ID: 7008MR 374 C++ */

#include<stdio.h>

int main(){
	long TABLE[33] ;
	long B,P,M;
	long R;

	while(scanf("%ld %ld %ld",&B,&P,&M)==3){
		TABLE[0]=1 ;
		TABLE[1]=B%M ;
		for(int i=2;i<33;i++){
			TABLE[i] = TABLE[i-1]%M;
			TABLE[i] *= TABLE[i];
			TABLE[i] %= M;
		}

		R=1;

		for(i=1;i<=32;i++){
			if(P%2==1){
				R*=TABLE[i];
				R%=M;
			}
			P/=2;
		}
		printf("%ld\n",R);
	}
	return 0 ;
}