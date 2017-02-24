
#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std ;

int main()
{
	int N ;

	cin >> N ;

	for(int iN=1 ; iN<=N ; iN++)
	{
		int n,i,j ;
		cin >> n ;

		double mat[101][101] ;

		for(i=0 ; i<101 ; i++)
		{
			for(j=0;j<101;j++)
			{
				if(i==j)
					mat[i][j] = 0.0 ;
				else
					mat[i][j] = -1.0 ;
			}
		}

		int town[101][2] ;

		for(int in=0 ; in<n ; in++)
		{
			cin >> town[in][0] >> town[in][1] ;
		}

		for( i=0 ; i<n;i++)
		{
			for(j=i+1 ; j<n ; j++)
			{
				int r = (town[i][0]-town[j][0])*(town[i][0]-town[j][0])+
						   (town[i][1]-town[j][1])*(town[i][1]-town[j][1]) ;
				if(r>100)
				{
					mat[i][j] = mat[j][i] = -1.0 ;
				}
				else
				{
					mat[i][j] = mat[j][i] = sqrt(r) ;
				}
			}
		}

		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(i==j)
					continue ;
				for(int k=0 ; k<n ; k++)
				{
					if(mat[i][k]<0.0 || mat[j][k]<0.0)
						continue ;
					if( mat[i][j] < 0.0 ||
						mat[i][k]+mat[k][j] < mat[i][j] )
						 
					{
						mat[i][j]=mat[j][i] = mat[i][k]+mat[k][j] ;
					}
				}
			}
		}

		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(i==j)
					continue ;
				for(int k=0 ; k<n ; k++)
				{
					if(mat[i][k]<0.0 || mat[j][k]<0.0)
						continue ;
					if( mat[i][j] < 0.0 ||
						mat[i][k]+mat[k][j] < mat[i][j] )
						 
					{
						mat[i][j] = mat[j][i] = mat[i][k]+mat[k][j] ;
					}
				}
			}
		}

		double max = -1.0 ;
		bool flag = true ;

		for(i=0;i<n && flag ;i++)
		{
			for(j=0;j<n && flag ;j++)
			{
				if( mat[i][j] > max && i!=j)
					max = mat[i][j] ;
				if( mat[i][j] < 0.0 )
				{
					flag = false ;
					break ;
				}
			}
		}

		printf("Case #%d:\n",iN) ;

		if(!flag)
			printf("Send Kurdy\n\n") ;
		else
			printf("%.4lf\n\n",max) ;
	}

	return 0 ;
}