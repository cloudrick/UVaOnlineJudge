
/*@JUDGE_ID: 7008MR 483 C++ */

#include<stdio.h>

int main(){
	char c,word[100];
	int wordl,i,j;
	wordl=0;
	while(scanf("%c",&c)==1){
		if(c==' '||c=='\n'){
			for(i=wordl-1;i>=0;i--)
				printf("%c",word[i]);
			wordl=0;
			printf("%c",c);
		}
		else{
			word[wordl]=c;
			wordl++;
		}
	}
	for(i=wordl-1;i>=0;i--)
		printf("%c",word[i]);

	return 0 ;
}
