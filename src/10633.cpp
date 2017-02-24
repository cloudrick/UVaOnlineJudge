
#include<iostream>

using namespace std ;

int main()
{

	while(true)
	{
		long long int d ;

		cin >> d ;

		if( d==0 )
			break ;

		for(long long int i=d+d/9-10 ; i<=d+d/9 ; ++i)
		{
			if( i-i/10 == d )
			{
				cout << i  ;
				if( d%9==0 )
					cout << ' ' << i+1 << endl ;
				else
					cout << endl ;
				break ;
			}
		}
	}

	return 0 ;
}