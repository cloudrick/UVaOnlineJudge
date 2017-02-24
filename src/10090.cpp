
#include<iostream>

using namespace std ;

int gcd( int a,int b)
{
	while(b)
		b^=a^=b^=a%=b ;
	return a ;
}

int main()
{
	while(true)
	{
		int n ;
		cin >> n ;
		if(n==0)
			break ;

		int c1,c2,n1,n2 ;

		cin >> c1 >> n1 >> c2 >> n2 ;

		int g = gcd(n1,n2) ;

		if( (n-g*n1)%n2!=0 && (n-g*n2)%n1!=0 )
		{
			cout << "failed" << endl ;
		}
		else
		{
			if( c1>c2 )
			{
				cout <<  (g < (n-g*n1)/n2 ? g : (n-g*n1)/n2) << ' ' ;
				cout <<  (g < (n-g*n1)/n2 ? (n-g*n1)/n2 : g) << endl ;

			}
			else
			{
				cout <<  (g > (n-g*n2)/n1 ? g : (n-g*n2)/n1) << ' ' ;
				cout <<  (g > (n-g*n2)/n1 ? (n-g*n2)/n1 : g) << endl ;
			}
		}

	}

	return 0 ;
}