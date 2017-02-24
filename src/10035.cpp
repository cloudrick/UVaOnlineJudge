
#include<stdio.h>
#include<string.h>

int main()
{
	char str1[150],str2[150] ;
	int num[150],i,ans ;
	while(scanf("%s %s",str1,str2)==2){
		ans = 0 ;
		for(i=0;i<150;i++) num[i]=0 ;
		if(str1[0]=='0' && str2[0]=='0')
			break ;
		for(i=0;i<strlen(str1);i++)
			num[i] = str1[strlen(str1)-i-1] - '0' ;
		for(i=0;i<strlen(str2);i++)
			num[i] += str2[strlen(str2)-i-1] - '0' ;
		for(i=0;i<149;i++){
			if(num[i]>=10){
				ans++ ;
				num[i+1] += num[i]/10 ;
				num[i] %= 10 ;
			}
		}
		if(ans)
			printf("%d ",ans) ;
		else
			printf("No ") ;
		if(ans>1)
			printf("carry operations.\n") ;
		else
			printf("carry operation.\n") ;
	}
	return 0 ;
}