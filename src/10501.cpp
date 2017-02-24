
#include<iostream>

using namespace std ;

int main()
{
	int n,m ;
	int i,j ;

	int output[800][4],length=0 ;

	cin >> n >> m ;

	int map[1600] ;

	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			char ch ;

			do
			{
				cin >> ch ;
			}while(ch=='\n') ;

			map[i*m+j] = ch ;

			for(int k=0 ; k<i*m+j ; k++)
			{
				if( map[k] == map[i*m+j] && map[i*m+j] != 0 )
				{
					output[length][0] = (k%n)+1 ;
					output[length][1] = (k/n)+1 ;
					output[length][2] = j+1 ;
					output[length][3] = i+1 ;
					length++ ;
					map[k]     = -1 ;
					map[i*m+j] = -1 ;
					break ;
				}
			}
		}
	}

	bool solved = true ;

	for( i=0 ; i<n*m ; i++)
	{
		if(map[i]>0)
		{
			solved = false ;
			break ;
		}
	}

	if(solved)
	{
		for(i=0 ; i<length ; i++)
		{
			cout << '(' << output[i][0] 
				 << ',' << output[i][1]
				 << "),(" << output[i][2]
			     << ',' << output[i][3]
			     << ')' << endl ;
		}
	}
	else
	{
		cout << "No solution" << endl ;
	}

	return 0 ;
}