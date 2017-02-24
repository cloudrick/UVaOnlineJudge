
#include<iostream>

using namespace std ;

int main()
{
	int C ;
	cin >> C ;

	while(C--)
	{
		char c ;
		int m,n ;

		cin >> c >> m >> n ;

		if( c=='r' || c=='Q')
			cout << (m<n ? m:n) << endl ;
		else if( c=='k')
			cout << m*n/2 << endl ;
		else if( c == 'K' )
		{
			if(m%2!=0) 
				m++ ;
			if(n%2!=0)
				n++ ;
			cout << m*n/4 << endl ;
		}

	}

	return 0 ;
}