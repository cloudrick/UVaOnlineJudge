
#include<stdio.h>

int main()
{
	char s[1000000],t[1000000] ;
	long int si,ti ;
	while(scanf("%s %s",s,t)==2){
		si=ti=0 ;
		while(1){
			if(!s[si]){
				printf("Yes\n") ;
				break ;
			}
			else if(!t[ti]){
				printf("No\n") ;
				break ;
			}
			if(s[si]==t[ti]){
				si++ ;
				ti++ ;
			}
			else
				ti++ ;
		}
	}
	return 0 ;
}