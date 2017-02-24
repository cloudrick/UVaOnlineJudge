
#include<iostream>
#include<cmath>

using namespace std ;

int main()
{
	int t ;

	cin >> t ;

	while(t--)
	{
		unsigned int i ;
		cin >> i ;

		unsigned int pre = 0 ;
		unsigned int cur = 0 ;
		unsigned int sum = 0 ;

		bool done = false ;

		for( int j=1 ; !done ; ++j)
		{
			cur = pre + log10(j) + 1 ;

			if( sum+cur >= i )
			{
				unsigned int offset = i-sum ;
				unsigned int p ;
				
				for( p=1 ; ; ++p)
				{
					if( offset <= p*(pow(10,p)-pow(10,p-1)) )
					{
						break ;
					}
					offset -= p*(pow(10,p)-pow(10,p-1)) ;
				}
				unsigned int k = pow(10,p-1)+(offset-1)/p ;

				if((offset%=p)==0)
					offset = p ;
					
				while( offset!=p )
				{
					k/=10 ;
					offset++ ;
				}
				cout << k%10 << endl ;
				break ;
			}
			sum += cur ;
			pre = cur ;
		}

	}

	return 0 ;
}