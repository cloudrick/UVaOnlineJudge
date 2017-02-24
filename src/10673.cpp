
#include<iostream>

using namespace std ;

int main()
{

	int n ;

	cin >> n ;

	while(n--)
	{
		int x,k ;

		cin >> x >> k ;

		int a = x/k ;
		int b ;

		if( x%k == 0)
			b = a ;
		else
			b = a+1 ;

		if( x%(a+b) == 0 )
		{
			cout << x/(a+b) << " " 
				 << x/(a+b) << endl ;
		}
		else if( x%a == 0 )
		{
			cout << x/a << " " << "0" << endl ;
		}
		else if( x%b == 0 )
		{
			cout << "0" << " " << x/b << endl ;
		}
		else
		{
			for( int m=1 ; m<1000000 ; m++ )
			{
				if( (x-(a*m))%b == 0)
				{
					cout << m << " " << (x-(a*m))/b << endl ;
					break ;
				}
				if( (x+(a*m))%b == 0)
				{
					cout << -m << " " << (x+(a*m))/b << endl ;
					break ;
				}
			}
		}
	}

	return 0 ;
}
