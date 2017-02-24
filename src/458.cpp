
// Written by Rick-Yang.
// ACM
// Problem(458) The Decoder .

/*   @JUDGE_ID: 7008MR   458   C++  */ 


#include<stdio.h>

int main(){
	char ch ;

	while(scanf("%c",&ch) != EOF){
		if(ch == '\n')
			printf("\n") ;
		else 
			printf("%c",ch-7) ;
	}

	return 0 ;
}
