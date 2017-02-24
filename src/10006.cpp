

#include<iostream>

using namespace std ;

int main()
{
	while(true)
	{
		int n ;

		cin >> n ;
		if( n==0 )
			break ;

		switch(n)
		{
		case 561 :
		case 1105:
		case 1729:
		case 2465:
		case 2821:
		case 6601:
		case 8911:
		case 10585:
		case 15841:
		case 29341:
		case 41041:
		case 46657:
		case 52633:
		case 62745:
		case 63973:
			cout << "The number " << n <<  " is a Carmichael number." << endl ;
			break ;
		default :
			cout << n <<  " is normal." << endl ;
		}
	}

	return 0 ;
}