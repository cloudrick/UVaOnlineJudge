
/*
	using Euler's Phi function
	http://mathworld.wolfram.com/TotientFunction.html
*/

#include<iostream>
#include<fstream>

using namespace std ;

const int size = 50010 ;

int main()
{
	unsigned int i,j ;
	unsigned int data[size] ;

	bool prime[size] ;

	prime[0] = prime[1] = false ;
	data[0] = data[1] = 1 ;
	for( i=2 ; i<size ; ++i)
	{
		prime[i] = true ;
		data[i] = i ;
	}

	for( i=2 ; i<size ; ++i)
	{
		if( prime[i] )
		{
			// prime
			data[i] = i-1 ;

			// multiple of prime
			for( j=2 ; i*j<size ; ++j)
			{
				prime[i*j] = false ;
				data[i*j] = data[i*j] * (i-1) / (i) ;
			}

			// power of prime
			for( j=i*i ; j<size ; j*=i)
			{
				prime[j] = false ;
				data[j] = j - (j/i) ;
			}

		}
	}

	for( i=2 ; i<size ; ++i)
		data[i] = data[i-1]+data[i]*2 ;


	while(true)
	{
		int n ;
		cin >> n ;

		if( n==0 )
			break ;

		cout << data[n] << endl ;
	}

	return 0 ;
}