
#include<iostream>

using namespace std ;

int f91(int n)
{
	if( n<=100 )
		return f91(f91(n+11)) ;
	else
		return n-10 ;
}

int main()
{
	while(true)
	{
		int n ;
		cin >> n ;
		if( n==0 )
			break ;
		cout << "f91(" << n << ") = " ;
		cout << f91(n) << endl ;
	}

	return 0 ; 
}