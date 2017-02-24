
/* @JUDGE_ID: 7008MR 594 C++ */

#include<stdio.h>

union {
	long number;
	char byte[4];
}number;

int main(){
	while(scanf("%ld",&number.number)==1){
		printf("%ld",number.number);
		number.byte[0]^=number.byte[3]^=number.byte[0]^=number.byte[3];
		number.byte[1]^=number.byte[2]^=number.byte[1]^=number.byte[2];
		printf(" converts to %ld\n",number.number);
	}
	return 0 ;
}
