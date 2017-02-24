
/*   @JUDGE_ID: 7008MR  10008 C++ */ 

#include<stdio.h>

int main()
{
	int c[26],i,max=0 ;
	char a,s[27]="ABCDEFGHIJKLMNOPQRSTUVWXYZ" ;

	for(i=0 ; i<26 ; i++)
		c[i] = 0 ;

	while(scanf("%c",&a)==1){
		if((a>='A' && a<='Z')||(a>='a'&&a<='z')){
			if(a >='a')
				c[int(a-97)]++ ;
			else
				c[int(a-65)]++ ;
		}
	}

	for(i=0 ; i<26 ; i++){
		if(c[i]>max)
			max=c[i] ;
	}

	for(;max>=1;max--){
		for(i=0 ; i<26 ; i++){
			if(c[i]==max)
				printf("%c %d\n",s[i],max) ;
		}
	}

	return 0 ;
}