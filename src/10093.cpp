
#include<stdio.h>
#include<string.h>

int main()
{
	char c ;
	long int k,sum;
	sum=k=0 ;
	while(scanf("%c",&c)==1){
		if(c>='0' && c <= '9'){
			sum = sum + c- '0' ;
			if(c-'0'>k)
				k = c-'0' ;
		}
		if(c>='A' && c <= 'Z'){
			sum = sum + c - 'A' + 10 ;
			if(c-'A'+10>k)
				k = c-'A'+10 ;
		}
		if(c>='a' && c <= 'z'){
			sum = sum + c - 'a' + 36 ;
			if(c-'a'+36>k)
				k = c-'a'+36 ;
		}
		if(c=='\n'){
			if(k==0)
				printf("2\n") ;
			else{
				while(sum%k && k<=62)
					k++ ;
				if(k>62)
					printf("such number is impossible!\n") ;
				else if(k)
					printf("%ld\n",k+1) ;
			}
			sum=k=0 ;
		}
	}
	return 0 ;
}