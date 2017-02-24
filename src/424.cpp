
#include<cstdio>
#include<cstring>

int main()
{
	int sum[110],i ;
	char str[110] ;
	bool flag ;
	
	for( i=0 ; i<110 ; i++ ) sum[i] = 0 ;
		
	while(scanf("%s",str)) {
	    if(str[0] == '0')	break ;

		for( i=strlen(str)-1 ; i>=0 ; i--)
			sum[i] += str[strlen(str)-i-1] -'0' ;

		for( i=0 ; i<109 ; i++){
			if(sum[i]>9){
				sum[i+1] += sum[i]/10 ;
				sum[i] %= 10 ;
			}
		}
	}

	flag = false ;

	for( i=109 ; i>=0 ; i--){
		if(flag || sum[i]!=0){
			printf("%d",sum[i]) ;
			flag = true ;
		}
	}

	printf("\n") ;

	return 0 ;
}

