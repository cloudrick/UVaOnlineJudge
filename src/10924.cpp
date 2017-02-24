
#include<iostream>
#include<string>

using namespace std ;

int main()
{
	bool isPrime[1041] ;
	int i ;

	for( i=2 ; i<1041 ; ++i)
	{
		isPrime[i] = true ;
	}

	isPrime[0] = isPrime[1] = true ;

	for( i=2 ; i<1041 ; ++i)
	{
		if( isPrime[i] )
		{
			for( int j=2 ; i*j<1041 ; ++j)
				isPrime[i*j] = false ;
		}
	}

	for(;;)
	{
		string line ;

		cin >> line ;

		if( cin.eof() )
			break ;

		int sum = 0 ;

		for( i=0 ; i<line.size() ; ++i)
		{
			if( line[i] >= 'a' && line[i] <='z' )
				sum += line[i] - 'a' + 1 ;
			else if( line[i] >= 'A' && line[i] <='Z' )
				sum += line[i] - 'A' + 27 ;
		}

		if( isPrime[sum] )
			cout << "It is a prime word." << endl ;
		else
			cout << "It is not a prime word." << endl ;
	}

	return 0 ;
}