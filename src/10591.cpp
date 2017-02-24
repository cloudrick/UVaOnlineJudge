
#include<iostream>
#include<set>

using namespace std ;

int main()
{
	int N ;
	cin >> N ;

	for( int nn=1 ; nn<=N ; ++nn)
	{
		int n ; 
		cin >> n ;

		if( cin.eof() )
			break ;

		cout << "Case #" << nn << ": " << n ;

		set<int> S ;
		S.insert(n) ;

		for(;;)
		{
			if( n==1 )
			{
				cout << " is a Happy number." << endl ;
				break ;
			}

			int tmp = 0 ;
			while( n!=0 )
			{
				tmp += (n%10)*(n%10) ;
				n/=10 ;
			}

			if( S.find(tmp) != S.end() )
			{
				cout << " is an Unhappy number." << endl ;
				break ;
			}
			else
			{
				S.insert(tmp) ;
				n = tmp ;
			}
		}

	}

	return 0 ;
}