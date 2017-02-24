
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std ;

inline int GCD(int a,int b)
{
	while(b)
		b^=a^=b^=a%=b ;
	return a ;
}

inline int LCM(int a,int b)
{
	return a/GCD(a,b) *b ;
}

int main()
{
	for(;;)
	{
		int N ;

		cin >> N ;

		if( N==0 )
			break ;

		vector<int> factor ;

		for(int k=1 ; k<=sqrt(N) ; ++k)
		{
			if( N%k==0 )
			{
				factor.push_back(k) ;
				if( k!=N/k)
					factor.push_back(N/k) ;
			}
		}

		sort(factor.begin(),factor.end()) ;


		int counter = 0 ;

		for( int i=0 ; i<factor.size() ; ++i)
		{
			for(int j=0 ; j<factor.size() && factor[i]>= factor[j]; ++j)
			{
				if( LCM( factor[i] , factor[j] ) == N )
				{
					counter++ ;
				}
			}
		}

		cout << N << ' ' << counter << endl ;
	}

	return 0 ;
}