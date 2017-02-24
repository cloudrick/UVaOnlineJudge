
#include <iostream>
#include <string>

using namespace std ;

int main()
{

	while(true)
	{

		bool isCurrect = true ;
		int tmp = 0 ;
		string str ;

		cin >> str ;
		
		if( cin.eof() )
			break ;


		for( int i=str.length()-1 ; i>=0 ; i-- )
		{
			if( (str[i] < 'p' || str[i] > 'z') && 
				( str[i] != 'N' && str[i] != 'C' &&
				  str[i] != 'D' && str[i] != 'E' &&
				  str[i] != 'I' 
				))
			{
				isCurrect = false ;
				break ;
			}

			if( str[i] >='p' && str[i] <= 'z')
			{
				tmp++ ;
			}

			if( str[i] == 'C' || str[i] == 'D' || str[i] == 'E' ||
				str[i] == 'I' )
			{
				tmp-- ;
			}

			if( tmp<=0 )
			{
				isCurrect = false ;
				break ;
			}

		}

		if( tmp != 1 )
			isCurrect = false ;

		if( isCurrect )
			cout << "YES" << endl ;
		else
			cout << "NO" << endl ;

	}

	return 0 ;
}