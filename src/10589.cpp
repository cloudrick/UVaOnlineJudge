
#include<cstdio>
#include<cmath>

int main()
{

	for(;;)
	{
		int N,a ;

		scanf("%d%d",&N,&a) ;

		if( N==0 )
			break ;

		int M=0 ;

		for( int i=0 ; i<N ; ++i)
		{
			double x,y ;
			scanf("%lf%lf",&x,&y) ;

			if( x*x + y*y > a*a )
			{
				continue ;
			}
			if( (a-x)*(a-x) + y*y > a*a )
			{
				continue ;
			}
			if( (a-x)*(a-x) + (a-y)*(a-y) > a*a )
			{
				continue ;
			}
			if( x*x + (a-y)*(a-y) > a*a )
			{
				continue ;
			}
			M++ ;
		}

		printf("%.5lf\n",(double)M*a*a/N) ;

	}

	return 0 ;
}