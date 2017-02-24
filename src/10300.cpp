
#include<stdio.h>

int main()
{
	long int n,f,a,b,c,sum ;
	scanf("%ld",&n) ;
	while(n--){
		scanf("%ld",&f) ;
		sum=0 ;
		while(f--){
			scanf("%ld%ld%ld",&a,&b,&c) ;
			sum += (a*c) ;
		}
		printf("%ld\n",sum) ;
	}
	return 0 ;
}