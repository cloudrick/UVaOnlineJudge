
#include<cstdio>
#include<cstring>
#include<cmath>

int main()
{
	char str[100] ;
	int s,i,j ;
	long sum ;

	while(scanf( "%s" , str ) )
	{
		if(strcmp("0",str)==0) break ;
		s=0 ;
		for(i=0 ; i<strlen(str) ; i++){
			if(str[i]-'0' > s)
				s = str[i]-'0' ;
		}
		s++ ;

		for(i=s ; i<=100 ; i++){
			sum = 0 ;
			for(j=0 ; j<strlen(str) ; j++)
				sum = sum*i + str[j] - '0' ;
			if(sqrt(sum)==long(sqrt(sum))){
				printf("%d\n",i) ;
				break ;
			}
		}

	}

	return 0 ;
}