
#include<iostream>
#include<vector>

using namespace std ;

long long int gcd(long long int a,long long int b)
{
	while(b)
		b^=a^=b^=a%=b ;
	return a ;
}

long long int C(int n,int m)
{
	if( n-m < m )
		m = n-m ;

	vector<long long int> denom ;

	for(long long int i=m ; i>=2 ; --i)
		denom.push_back(i) ;

	long long int r = 1 ;

	for(long long int j=n ; j>n-m ; --j)
	{
		r*=j ;
		for( int k=0 ; k<denom.size() ; ++k)
		{
			if( denom[k] == 1 )
				continue ;

			long long int g = gcd( denom[k] , r ) ;
			r /= g ;
			denom[k] /= g ;
		}
	
	}

	if( r<0 )
		r = 0 ;

	return r ;
}

int main()
{
	int K ;
	cin >> K ;

	while(K--)
	{
		int N,T,P ;

		cin >> N >> T >> P ;

		T -= N*P ;
		N += T-1 ;

		if( N<0 || T<0)
			cout << 0 << endl ;
		else
			cout << C(N,T) << endl ;

	}

	return 0 ;
}
