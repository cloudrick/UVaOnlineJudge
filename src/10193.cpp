
#include<stdio.h>
#include<string.h>
#include<math.h>

long Dec(char str[],int len){
	long int sum = 0 ;
	for(int i=0;i<len;i++){
		if(str[i]=='1')
			sum += long(pow(2,len-i-1)) ;
	}
	return(sum) ;
}

long gcd(long int n1,long int n2){
	if(n1<n2) n1^=n2^=n1^=n2 ;
	return (n1%n2 ? gcd(n2,n1%n2) : n2 ) ;
}

int main()
{
	int n ;
	char str[35] ;
	unsigned long int n1,n2 ;

	scanf("%d",&n) ;

	for(int i=1 ; i<=n ; i++){
		scanf("%s",str); 
		n1 = Dec(str,int(strlen(str))) ;
		scanf("%s",str) ;
		n2 = Dec(str,int(strlen(str))) ;
		if(gcd(n1,n2)>1)
			printf("Pair #%d: All you need is love!\n",i) ;
		else
			printf("Pair #%d: Love is not all you need!\n",i) ;
	}

	return 0 ;
}