
#include<iostream>

using namespace std ;

int main()
{
	int A[100] ;
	
	A[0] = 1 ; 
	A[1] = 1 ;
	A[2] = 2 ;

	for(int i=3; i<100 ; ++i)
	{
		A[i] = A[i-2] + A[i-3] ;
	}

	for(;;)
	{
		int n ;
		cin >> n ;
		if( cin.eof() )
			break ;

		cout << A[n] << endl ;
	}

	return 0 ;
}
