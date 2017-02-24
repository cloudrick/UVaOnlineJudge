
/* @JUDGE_ID: 7008MR 621 C++ */

#include<stdio.h>
#include<string.h>

int main(){
	int n,i ;
	char str[128] ;

	scanf("%d",&n) ;
	i=n ;
	while(n--){
		if(i!=n+1)
			printf("\n") ;
    	scanf("%s",str) ;
        if(strlen(str)==1||strlen(str)==2)
			printf("+") ;
		else if(str[strlen(str)-2]=='3'&&str[strlen(str)-1]=='5')
        	printf("-") ;
        else if(str[0]=='9')
        	printf("*") ;
        else
        	printf("?") ;
	}
	return 0 ;
}
