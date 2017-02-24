
#include<iostream>

using namespace std ;


int main()
{
	unsigned int i,j ;
	bool prime[100000] ;
	
	for( i=0 ; i<100000 ; ++i)
		prime[i] = true ;

	prime[0] = prime[1] = false ;
	
	for( i=2 ; i<100000 ; ++i)
	{
		if( prime[i] )
		{
			for( j=2 ; i*j<100000 ; ++j)
			{
				prime[i*j] = false ;
			}
		}
	}
	
	int t ;
	cin >> t ;
	
	while( t-- )
	{
		int n ;
		unsigned int data[10001] ;
		unsigned int tmp[10001] ;
		
		cin >> n ;
		
		for( i=0 ; i<n ; ++i)
		{
			cin >> data[i] ;
			tmp[i] = data[i] ;
		}
		
		unsigned int length = 2 ;

		bool done = false ;
		
		while( length <= n && !done)
		{
			for(i=0 ; i<n ; ++i)
			{
				if( i+length > n  )
					break ;

				tmp[i] += data[i+length-1] ;
												
				if( tmp[i] <100000 )
				{
					if( prime[tmp[i]] )
					{
						cout << "Shortest primed subsequence is length " << length << ": " ;
						for( j=0 ; j<length ; ++j)
						{
							if( j!=0)
								cout << ' ' ;
							cout << data[i+j] ;
						}
						cout << endl ;
						done = true ;
						break ;
					}
				}
				else
				{
					bool isprime = true ;
					for(int k=2 ; k<100000 ; ++j)
					{
						if( prime[k] && tmp[i]%k==0)
						{
							isprime = false ;
							break ;
						}
					}
					
					if( isprime )
					{
						cout << "Shortest primed subsequence is length " << length << ": " ;
						for( j=0 ; j<length ; ++j)
						{
							if( j!=0)
								cout << ' ' ;
							cout << data[i+j] ;

						}
						cout << endl ;
						done = true ;
						break ;
					}

				}
			}
			length++ ;
		}
		if(!done)
			cout << "This sequence is anti-primed." << endl ;
		
	}
	return 0 ;
}