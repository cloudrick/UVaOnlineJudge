
/* @JUDGE_ID: 7008MR 445 C++ */

#include<stdio.h>

int main(){
	char c;
	int d,i; 

	while(scanf("%c",&c)==1){
		if('0'<=c && c<='9' )
			d+=c-'0';
		else if(c=='!'||c=='\n')
			printf("\n");
		else{
			if(c =='b')
				c=' ';
			for(i=0;i<d;i++)
				printf("%c",c);
			d=0;
		}
	}
	return 0 ;
}