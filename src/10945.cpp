
#include<iostream>
#include<list>
#include<cstring>

using namespace std ;

int main()
{
	for(;;)
	{
		char line[1000] ;
		cin.getline(line,1000) ;

		if( strcmp(line,"DONE") == 0 )
			break ;

		list<int> buf ;

		for( int i=0 ; i<strlen(line) ; ++i)
		{
			if( line[i] >= 'A' && line[i] <= 'Z' )
				buf.push_back(line[i]-'A') ;
			else if( line[i] >= 'a' && line[i] <= 'z')
				buf.push_back(line[i]-'a') ;
		}

		bool yes = true ;

		while( buf.size() >=2 )
		{
			if( buf.front() != buf.back() )
			{
				yes = false ;
				break ;
			}
			
			buf.pop_back() ;
			buf.pop_front() ;
		}

		if( yes )
			cout << "You won't be eaten!" << endl ;
		else
			cout << "Uh oh.." << endl ;
	}
	return 0 ;
}