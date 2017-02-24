
/* @JUDGE_ID: 7008MR 10106 C++ */

#include<stdio.h>
#include<string.h>

int main()
{
	int Num1[300],Num2[300],Sum[600] ;
	char s1[300] , s2[300] ;
	int i,j ;

	while(scanf("%s %s",s1,s2)==2){
		if((s1[0]=='0'&&s1[1]==NULL)||
			(s2[0]=='0'&&s2[1]==NULL)){
			printf("0\n") ;
			continue ;
		}

		for(i=0 ; i<600 ; i++){
			if(i<300){
				Num1[i] = 0 ;
				Num2[i] = 0 ;
			}
			Sum[i] = 0 ;
		}
		Sum[0] = -1 ;
		for(i=299 ; i>=0 ; i--){
			if(i>=strlen(s1))
				Num1[i] = -1 ;
			else
				Num1[i] = int(s1[strlen(s1)-i-1])-48 ;
		}
		for(i=299 ; i>=0 ; i--){
			if(i>=strlen(s2))
				Num2[i] = -1 ;
			else
				Num2[i] = int(s2[strlen(s2)-i-1])-48 ;
		}

		for(i=0 ; Num2[i]>=0 ; i++){
			for(j=0 ; Num1[j]>=0 ; j++){
				if(Sum[i+j]<0){
					Sum[i+j] = Num2[i] * Num1[j] ;
					Sum[i+j+1] = -1 ;
				}
				else
					Sum[i+j] += Num2[i] * Num1[j] ;
			}
		}

		for(i=0 ; Sum[i]>=0 ; i++){
			if(Sum[i]>=10){
				if(Sum[i+1]>=0){
					Sum[i+1] += Sum[i] / 10 ;
					Sum[i] %= 10 ;
				}
				else{	
					Sum[i+1] = Sum[i] / 10 ;
					Sum[i+2] = -1 ;
					Sum[i] %= 10 ;
				}
			}
		}
		for(i--; i>=0 ; i--)
			printf("%d",Sum[i]) ;
		printf("\n") ;
	}
	return 0 ;
}