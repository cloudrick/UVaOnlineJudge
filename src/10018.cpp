
#include<stdio.h>
#include<string.h>

unsigned long int rev(unsigned long int nn){
	unsigned long int mm=0 ;
	while(nn){
		mm=(mm*10)+(nn%10) ;
		nn/=10 ;
	}
	return(mm) ;
}

int main()
{
	unsigned long int nn,n,count ;
	scanf("%u",&n) ;
	while(n--){
		scanf("%u",&nn) ;
		count = 0 ;
		do{
			nn+=rev(nn) ;
			count++ ;
		}while(nn!=rev(nn)) ;
		printf("%lu %lu\n",count,nn) ;
	}
	return 0 ;
}