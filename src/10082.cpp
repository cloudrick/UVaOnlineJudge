
#include<stdio.h>
#include<string.h>

const char str1[50] = "1234567890-=WERTYUIOP[]\\SDFGHJKL;\'XCVBNM,./" ;
const char str2[50] = "`1234567890-QWERTYUIOP[]ASDFGHJKL;ZXCVBNM,." ;

int main()
{
	char c ;
	int i ;
	while(scanf("%c",&c)==1){
		for(i=0;i<strlen(str2);i++){
			if(c==str1[i])
				printf("%c",str2[i]) ;
		}
		if(c==' ')
			printf(" ") ;
		if(c=='\n')
			printf("\n") ;
	}
	return 0 ;
}