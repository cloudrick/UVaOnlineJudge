
#include<iostream>

using namespace std ;

int main()
{
	char ch ;
	
	bool get_next = true ;
	bool antislash = false ;
	bool star = false ;

	for(;;)
	{
		if( get_next )
		{
			ch = cin.get() ;
			if( cin.eof() )
				break ;
		}

		get_next = true ;

		if( ch == '\\' )
		{
			if( star )
			{
				ch = cin.get() ;
				if( cin.eof() )
				{
					cout << '\\' ;
					break ;
				}
				if( ch != '*' )
				{
					cout << '\\' ;
					get_next = false ;
				}
				else
				{
					star = false ;
				}
			}
			else
			{
				if( antislash )
				{
					cout << '\\' ;
					antislash = false ;
				}
				else
				{
					antislash = true ;
				}
			}
			continue ;
		}

		if( ch == 'b' )
		{
			if( antislash )
			{
				if( star )
					cout << "\\b" ;
				antislash = false ;
			}
			else
			{
				cout << 'b' ;
			}
			continue ;
		}

		if( ch == 'i' )
		{
			if( antislash )
			{
				if( star )
					cout << "\\i" ;
				antislash = false ;
			}
			else
			{
				cout << 'i' ;
			}
			continue ;
		}

		if( ch == '*' )
		{
			if( antislash )
			{
				if( star )
					star = false ;
				else
					star = true ;
				antislash = false ;
			}
			else
			{
				cout << '*' ;
			}
			continue ;
		}
	
		if( ch == 's' )
		{
			if( antislash )
			{
				if( star )
					cout << "\\s" ;
				
				int state = 0 ;
				for(;;)
				{
					ch = cin.get() ;
					if( cin.eof() )
						break ;

					if( state == 0 )
					{
						if( ch == '.' )
							state = 1 ;
						else if( ch < '0' || ch>'9' )
						{
							get_next = false ;
							break ;
						}
						if( star )
							cout << ch ;
					}
					else if( state == 1 )
					{
						if( ch < '0' || ch>'9' )
						{
							get_next = false ;
							break ;
						}
						if( star )
							cout << ch ;
					}
				}
				antislash = false ;
			}
			else
			{
				cout << 's' ;
			}
			continue ;
		}

		cout << ch ;
		antislash = false ;
	}

	return 0 ;
}