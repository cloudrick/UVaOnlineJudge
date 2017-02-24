
#include<iostream>
#include<cmath>
#include<cstdio>

using namespace std ;

int main()
{

	while(true)
	{
		double L,f ;
		cin >> L >> f ;

		if( L==0 && f==0 )
		{
			break ;
		}

		double v = sqrt(2*L*f) ;
		printf("%.8lf %.8lf\n",v,(3600*v)/(L+((v*v)/(2*f)))) ;
	}

	return 0 ;
}