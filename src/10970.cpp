
#include<iostream>

using namespace std ;

int main()
{
	for(;;)
	{
		int n,m ;

		cin >> n >> m ;

		if( cin.eof() )
			break ;

		cout << n*m-1 << endl ;
	}

	return 0 ;
}