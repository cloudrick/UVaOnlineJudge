

#include<iostream>
#include<string>

using namespace std ;

int match(int table[101][101],int h,int w,int x,int y)
{
	if( x<0 || x>=h || y<0 || y>=w )	
	{
		return 0 ;
	}
	else
	{
		int max_L = 1 ;
		
		while( x-max_L >=0 && x+max_L<h && y-max_L>=0 && y+max_L <w )
		{
			if( table[x-max_L][y-max_L] == table[x+max_L][y+max_L] &&
			    table[x][y] == table[x+max_L][y+max_L])	
			{
				++max_L ;	
			}
			else
			{
				break ;	
			}
		}

		--max_L	;
		
		bool done = false ;
		
		while(!done)
		{
			done = true ;
			for( int i=x-max_L ; i<=x+max_L && done ; ++i )	
			{
				for( int j=y-max_L ; j<=y+max_L && done ; ++j)	
				{
					if( table[x][y] != table[i][j] )
					{
						done = false ;
						--max_L ;
						break ;
					}
				}
			}
		}
		
		return max_L ;
	}
}

int main()
{
	int T ;
	cin >> T ;
	
	while(T--)
	{
		int N,M,Q ;
		
		cin >> N >> M >> Q ;
		cout << N << ' ' << M << ' ' << Q << endl ;
		
		int table[101][101] ;
		
		for( int i=0 ; i<N ; ++i)
		{
			string line ;
			cin >> line ;
			
			for( int j=0 ; j< line.size() ; ++j)
			{
				table[i][j] = line[j] ;	
			}
		}
		
		for( int k=0 ; k<Q ; ++k)
		{
			int x,y ;
			cin >> x >> y ;
			cout << match(table,N,M,x,y)*2+1 << endl ;
		}
		
	}
	
	return 0 ;	
}
