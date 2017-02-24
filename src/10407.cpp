
#include<cstdio>

inline int gcd(int a,int b) 
{
	while(a)
		a^=b^=a^=b%=a ;
	return (b) ;
}

int main()
{
	int n,m,ans ;
	
	while(scanf("%d",&n)==1)
	{
		if(!n) break ;

		ans = 0 ;

		while( true )
		{
			scanf("%d",&m) ;
			if(!m) 
				break ;
			if(n<m)
				n^=m^=n^=m ;
			ans = gcd( ans , n-m ) ;
		}

		printf("%ld\n",ans) ;
	}

	return 0 ;
}