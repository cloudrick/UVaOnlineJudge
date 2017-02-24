
#include<cstdio>
#include<cmath>

int main()
{
	int S ;
	int N,I ;
	double p,ans ;

	scanf("%d",&S) ;

	while(S--)
	{
		scanf("%d %lf %d",&N,&p,&I) ;
		
		if(p==0.0)
			ans = 0.0 ;
		else{
			ans = p*pow(1.0-p,I-1) ;
			ans = ans/(1-pow(1.0-p,N)) ;
		}

		printf("%.4lf\n",ans) ;

	}

	return 0 ;
}