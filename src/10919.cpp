
#include<iostream>
#include<string>
#include<set>

using namespace std ;

int main()
{
	int i,j ;

	for(;;)
	{
		int k ;
		cin >> k ;

		if( k==0 )
			break ;

		int m ;
		cin >> m ;

		set<string> selected ;

		for(i=0 ; i<k ; ++i)
		{
			string tmp ;
			cin >> tmp ;
			selected.insert(tmp) ;
		}

		bool pass = true ;

		for( i=0 ; i<m ; ++i)
		{
			int c,r ;
			cin >> c >> r ;

			int s=0 ;

			for( j=0 ; j<c ; ++j)
			{
				string tmp ;
				cin >> tmp ;

				if(pass)
				{
					if( selected.find(tmp) != selected.end() )
						s++ ;
				}
			}

			if( pass && s<r )
			{
				pass = false ;
			}
		}

		if( pass )
			cout << "yes" << endl ;
		else
			cout << "no" << endl ;

	}


	return 0 ;
}
