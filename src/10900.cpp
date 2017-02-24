
#include<iostream>
#include<cstdio>

using namespace std ;

double f(int n,int a,const double &t)
{
	if( n==0 )
		return a ;
	else
	{
		double b = f(n-1,2*a,t) ;
		double p = a/b ;

		double r = 0.0 ;

		if( p>t )
		{
			if( p>1 )
				r += a*(1-t) ;
			else
				r += a*(p-t) ;
		}
		if( p<1 )
		{
			if( p<t )
				r += (0.5*b)-(0.5*t*t*b) ;
			else
				r += (0.5*b)-(0.5*p*p*b) ;
		}

		return r/(1-t) ;
	}
}

int main()
{
	for(;;)
	{
		int n ;
		double t ;

		cin >> n >> t ;

		if( n==0 && t==0 )
			break ;

		printf("%.3lf\n",f(n,1,t)) ;

	}
	return 0 ;
}
