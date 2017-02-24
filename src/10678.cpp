
#include<cstdio>
#include<iostream>
#include<cmath>

using namespace std ;

int main()
{
	int n ;

	double pi = 2*acos(0.0) ;

	cin >> n ;

	while(n--)
	{
		double D,L,B ;

		cin >> D ;
		cin >> L ;

		B = sqrt( (L*L/4.0) - (D*D/4.0)) ;

		printf("%.3lf\n", pi*(L/2.0)*B ) ;
	}

	return 0 ;
}

