// Written by Rick-Yang.
// ACM
// Problem(10055) Hashmat the brave warrior .

/*   @JUDGE_ID: 7008MR   10055   C++  */ 


#include <stdio.h>
int main()
{
	long long int a , b ;

	while(scanf("%lld %lld",&a,&b) == 2 ){
		if(a>b)
			printf("%lld\n",a-b) ;
		else
			printf("%lld\n",b-a) ;
	}
	return 0 ;
}
