
#include<iostream>

using namespace std ;

int main()
{

	while(true)
	{
		int n,m,k ;

		cin >> n >> m >> k ;

		if( n==0 && m==0 && k==0 )
			break ;

		if( m%2 == 0 )
			cout << "Gared" << endl ;
		else
			cout << "Keka" << endl ;
		
	}

	return 0 ;
}