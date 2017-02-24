
#include<iostream>

using namespace std ;

int n,m ;
int trail[50]

int main()
{
	int N ;

	cin >> N ;

	for(int iN=1 ; iN<=N ; iN++) 
	{
		
		int i,j ;

		int mat[26][26] ;
		for(i=0 ; i<26 ; i++)
		{
			for(j=0 ; j<26 ; j++)
			{
				if( i==j )
					mat[i][j] = 0 ;
				else
					mat[i][j] = -1 ;
			}
		}

		cin >> n >> m ;

		for(i=0 ; i<m ; i++)
		{
			int x,y ;
			cin >> x >> y ;
		}

		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(i==j)
					continue ;
				for(int k=0 ; k<n ; k++)
				{
					if( mat[i][k]<0 || mat[k][j] <0)
						continue ;
					if( mat[i][k]+mat[k][j] < mat[i][j] || mat[i][j]<0)
						mat[i][j] = mat[i][k]+mat[k][j] ;
				}
			}
		}

		int max = -1 ;

		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(mat[i][j]>max)
					max = mat[i][j] ;
			}
		}

		cout << "Case #" << iN << ":" << endl ;
		cout << max << endl << endl ;


	}

	return 0 ;
}