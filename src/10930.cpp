
#include<iostream>
#include<set>
#include<vector>

using namespace std ;

int main()
{
	for(int t=1;;++t)
	{
		int D ;
		cin >> D ;
		if(cin.eof())
			break ;

		set<int> saved ;

		bool res = true ;

		cout << "Case #" << t << ": " ;

		int pre = 0 ;

		for(int d=0 ; d<D ; ++d)
		{
			vector<int> to_save ;
			int tmp ;

			cin >> tmp ;
			cout << tmp ;

			if( d!=D-1)
				cout << ' ' ;

			if( tmp <= pre )
			{
				res = false ;
			}

			pre = tmp ;

			if(!res)
				continue ;

			if( saved.find(tmp) != saved.end() )
			{
				res = false ;
				continue ;
			}

			for( set<int>::iterator i=saved.begin() ;
			     i!=saved.end() ; ++i)
			{
				if( (*i)+tmp <= 1000 )
					to_save.push_back( (*i)+tmp ) ;
			}

			saved.insert( to_save.begin() , to_save.end() ) ;
			saved.insert(tmp) ;
		}

		cout << endl ;

		if( res )
			cout << "This is an A-sequence." << endl ;
		else
			cout << "This is not an A-sequence." << endl ;
	}

	return 0 ;
}