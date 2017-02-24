
#include<iostream>
#include<string>

using namespace std ;

int parse_if()
{
	int res[2] = {1,0} ;
	int i=0 ;

	while( true )
	{
		string tmp ;
		cin >> tmp ;
		if( tmp == "END_IF" )
		{
			return res[0]+res[1] ;
		}
		else if( tmp == "IF" )
		{
			res[i] *= parse_if() ;
		}
		else if( tmp == "ELSE" )
		{
			res[1] = 1 ;
			i=1 ;
		}
	}
}

int parse_start()
{
	int res = 1 ;

	while( true )
	{
		string tmp ;
		cin >> tmp ;
		if( tmp == "ENDPROGRAM" )
		{
			return res ;
		}
		else if( tmp == "IF" )
		{
			res *= parse_if() ;
		}
	}
	return res ;
}

int main()
{
	int n ;

	cin >> n ;

	while(n--)
	{
		cout << parse_start() << endl ;
	}

	return 0 ;
}