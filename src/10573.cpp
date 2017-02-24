
#include<cstdio>
#include<math.h>

const double pi = acos(-1.0) ;

int main()
{

	int N ;
	char str[10] ;
	gets(str) ;

	sscanf(str,"%d",&N) ;

	while(N--)
	{
		
		double r1,r2 ;

		gets(str) ;

		if( sscanf(str,"%lf %lf",&r1,&r2) == 2 )
		{
			double r3 = r1+r2 ;
			printf("%.4lf\n", r1*r2*pi*2.0) ;
		}
		else
		{
			printf("%.4lf\n",r1*r1*pi/8.0) ;
		}

	}

	return 0 ;
}