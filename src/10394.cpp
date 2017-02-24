
#include<iostream>

using namespace std ;

int main()
{
	bool *map ;
	unsigned int i,j ;
	unsigned int prime[100001] ;
	int length = 0 ;

	map = new bool[20000000] ;

	for(i=0 ; i<20000000 ; i++)
		map[i] = true ;

	map[0] = map[1] = false ;

	for( i=2 ; i<20000000 ; i++)
	{
		if(map[i])
		{
			if(map[i-2])
			{
				prime[length++] = i-2 ;
				if( length > 100000 )
					break ;
			}
		
			for(j=2 ; i*j<20000000 ; j++)
			{
				map[i*j] = false ;
			}
		}
	}

	while(true)
	{
		int S ;
		cin >> S ;
		if( cin.eof() )
			break ;
		cout << '(' << prime[S-1] << ", " << prime[S-1]+2 << ')' << endl ;
	}
	
	delete [] map ;

	return 0 ;
}