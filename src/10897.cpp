
#include<cstdio>
#include<iostream>
#include<cmath>

using namespace std ;

const double pi = acos(-1) ;
const double r  = 6371.01  ;

int main()
{
	int n;

	cin >> n ;

	while(n--)
	{
		double a1,d1,e1,a2,d2,e2 ;
		double b1,c1,f1,b2,c2,f2 ;
		char X1,Y1,X2,Y2 ;

		cin >> a1 >> b1 >> c1 >> X1 ;
		cin >> d1 >> e1 >> f1 >> Y1 ;
		cin >> a2 >> b2 >> c2 >> X2 ;
		cin >> d2 >> e2 >> f2 >> Y2 ;


		double r1 = (a1 + b1/60 + c1/3600 )*pi/180 ;
		double r2 = (d1 + e1/60 + f1/3600 )*pi/180 ;
		double r3 = (a2 + b2/60 + c2/3600 )*pi/180 ;
		double r4 = (d2 + e2/60 + f2/3600 )*pi/180 ;

		if( X1 == 'S' )
			r1 *= (-1) ;

		if( Y1 == 'W' )
			r2 *= (-1) ;

		if( X2 == 'S' )
			r3 *= (-1) ;

		if( Y2 == 'W' )
			r4 *= (-1) ;

		/*
			x1 = r*sin(r1)
            y1 = r*cos(r1)*sin(r2)
			z1 = r*cos(r1)*cos(r2)

			x2 = r*sin(r3)
            y2 = r*cos(r3)*sin(r4)
			z2 = r*cos(r3)*cos(r4)

			by inner product

		*/

		double d = acos( sin(r1) * sin(r3) +
                         cos(r1) * cos(r3) * cos(r2) * cos(r4) +
                         cos(r1) * cos(r3) * sin(r2) * sin(r4) ) * r; 

		printf("%.2lf\n",d) ;

	}

	return 0 ;
}