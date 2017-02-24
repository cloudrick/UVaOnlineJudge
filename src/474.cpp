
/*@JUDGE_ID: 7008MR 474 C++ */

#include<stdio.h>

const MAX=1000000 ;

double table[MAX+1];
long len[MAX+1];

int main(){
	long i,n;
	table[0]=1;
	len[0]=0;
	for(i=1;i<=MAX;i++){
		table[i]=table[i-1]/2;
		len[i]=len[i-1];
		while(table[i]<1){
			table[i]*=10;
			len[i]++;
		}
	}
	while(scanf("%ld",&n)==1){
		if(n>1000000){
			n=0;
			i=3/n;
		}
		printf("2^-%ld = %1.3fe-%ld\n",n,table[n],len[n]);
	}
	return 0 ;
}
