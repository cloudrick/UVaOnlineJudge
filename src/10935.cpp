
#include<iostream>
#include<list>

using namespace std ;

int main()
{
	for(;;)
	{
		int n ;
		cin >> n ;

		if( n==0 )
			break ;

		list<int> card ;

		for( int i=1 ; i<=n ; ++i)
			card.push_back(i) ;

		cout << "Discarded cards:" ;

		for(;;)
		{
			if( card.size() > 1 )
				cout << ' ' << card.front() ;
			else
				break ;

			card.pop_front() ;
			card.push_back( card.front() ) ;
			card.pop_front() ;

			if( card.size() > 1 )
				cout << "," ;
		}

		cout << endl << "Remaining card: " << card.front() ;
		cout << endl ;
	}

	return 0 ;
}