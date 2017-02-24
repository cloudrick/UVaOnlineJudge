
#include<iostream>

using namespace std ;

int main()
{
	int i,j ;
	for(;;)
	{
		int x,y ;
		cin >> x >> y ;
		if( cin.eof() )
			break ;

		int alphabet[26] ;
		int **table ;
		int **count ;

		for( i=0 ; i<26 ; ++i)
			alphabet[i] = 0 ;

		table = new int* [x+2] ;
		count = new int* [x+2] ;

		for( i=0 ; i<x+2 ; ++i)
		{
			table[i] = new int[y+2] ;
			count[i] = new int[y+2] ;
		}

		for( i=0 ; i<x+2 ; ++i)
		{
			if( i==0 || i==x+1 )
			{
				for( j=0 ; j<y+2 ; ++j)
				{
					table[i][j] = 0 ;
					count[i][j] = 0 ;
				}
			}
			else
			{
				table[i][0] = 0 ;
				count[i][0] = 0 ;

				char *line = new char[y+2] ;
				cin >> line ;

				for( j=1 ; j<=y ; ++j)
				{
					table[i][j] = line[j-1] ;
					count[i][j] = 0 ;
				}
				table[i][y+1] = 0 ;
				count[i][y+1] = 0 ;

				delete [] line ;
			}
		}

		for( i=1 ; i<=x ; ++i)
		{
			for( j=1 ; j<=y ; ++j)
			{
				count[i][j] = 1 ;

				if( table[i][j] == talbe[i][j-1] )
				{
					if( count[i][j] <= count[i][j-1] )
						count[i][j] +=
				}
			}

			for( j=y ; j>=1 ; --j)
			{

			}
		}


		for( i=0 ; i<x+2 ; ++i)
		{
			delete [] table[i] ;
			delete [] count[i] ;
		}
		delete [] table ;
		delete [] count ;
	}

	return 0 ;
}