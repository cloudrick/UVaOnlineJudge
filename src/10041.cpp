
#include<cstdio>

int main()
{
	long int n,r,s[501],avg,ans ;
	long int i ;

	scanf("%ld",&n) ;

	while(n--)
	{
		scanf("%ld",&r) ;
		avg = ans = 0 ;
		for(i=0 ; i<r ; i++){
			scanf("%ld",&s[i]) ;
			avg += s[i] ;
		}
		avg = ((double)avg/r)+0.5 ;

		for(i=0 ; i<r ; i++)
			ans += (s[i]-avg>0) ? s[i]-avg : (avg-s[i]) ;
		printf("%ld\n",ans) ;
	}

	return 0 ;
}