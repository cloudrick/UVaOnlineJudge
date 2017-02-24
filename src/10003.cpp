
#include<iostream>

using namespace std ;

int main()
{
	int i,j ;

	while(true)
	{
		int L ;
		cin >> L ;

		if( L==0 )
			break ;

		int N ; 
		cin >> N ;

		int *C = new int[N+2] ;

		for( i=1 ; i<=N ;++i)
			cin >> C[i] ;
		C[0] = 0 ;
		C[N+1] = L ;

		int table[52][52] ;

		for( i=0 ; i<N+2 ; ++i)
		{
			table[i][i] = 0 ;
			if( i!= N+1 )
				table[i][i+1] = 0 ;
		}

		for( int d=2 ; d<N+2 ; ++d)
		{
			for( i=0 ; d+i<N+2 ; ++i)
			{
				int l = C[i+d] - C[i] ;
				int local_min = L*N ;

				for(j=i+1 ; j!=i+d ; ++j)
				{
					if( table[i][j] + table[j][i+d] < local_min ) 
						local_min = table[i][j] + table[j][i+d] ;
				}
				table[i][i+d] = local_min + l ;
			}
		}

		cout << "The minimum cutting is " << table[0][N+1] << "." << endl ;

		delete [] C ;
	}

	return 0 ;
}