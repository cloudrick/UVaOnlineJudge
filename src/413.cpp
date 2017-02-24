
#include<iostream>

using namespace std ;

int main()
{
	


	while(1)
	{
		int seq[30] ;
		int len = 1 ;

		cin >> seq[0] ;

		if( seq[0] == 0 )
			break ;

		while(1)
		{
			cin >> seq[len] ;
			if( seq[len] == 0 )
				break ;
			len++ ;
		}

		int h = seq[0] ;

		for( int i=1 ; i<len ; i++)
		{
			
		}

	}

	return 0 ;
}
