
#include <iostream>
#include <vector>
#include <cstdio>

using namespace std ;

int main()
{
	int i,j,m ;

	int speed[100] ;
	int distance[100][100] ;

	while(true)
	{
		int n,k ;

		cin >> n >> k ;

		if(cin.eof())
			break ;

		for( i=0 ; i<100 ; i++)
		{
			for( j=0 ; j<100;j++)
			{
				if(i==j)
					distance[i][j] = 0 ;
				else
					distance[i][j] = -1 ;
			}
			speed[i] = 0 ;
		}


		for(i=0 ; i<n ; i++)
		{
			cin >> speed[i] ;
		}

		for(i=0 ; i<n ; i++)
		{
			char list[500] ;
			while( cin.peek() == '\n')
				cin.get() ;
			cin.getline(list,500) ;
			char *tmp ; 
			while( (tmp = strtok(list," \n"))==NULL) ;
			int tmpn = atoi(tmp) ;

			int tmpdata[100] ;
			int tdsize = 0 ;
			tmpdata[tdsize++] = tmpn ;

			while( (tmp = strtok(NULL," \n"))!=NULL)
			{
				tmpn = atoi(tmp) ;
				tmpdata[tdsize++] = tmpn ;
			}

			for( j=0 ; j<tdsize ; j++)
			{
				for( m=j+1 ; m<tdsize ; m++)
				{
					if( distance[tmpdata[j]][tmpdata[m]] == -1 ||
						((tmpdata[m]-tmpdata[j])*speed[i] < distance[tmpdata[j]][tmpdata[m]]))
					{
						distance[tmpdata[j]][tmpdata[m]] = 
							distance[tmpdata[m]][tmpdata[j]] = 
							(tmpdata[m]-tmpdata[j])*speed[i] ;
					}
				}
			}
		}
		
		for( i=0 ; i<100 ; i++)
		{
			for( j=0 ; j<100 ; j++)
			{
				if( i==j )
					continue ;
				for(m=0 ; m<100 ; m++)
				{
					if( distance[i][m] == -1 || distance[m][j]==-1)
						continue ;
					if( (distance[i][m]+distance[m][j]+60) < distance[i][j] ||
						distance[i][j] == -1 )
					{
						distance[i][j] = distance[i][m]+distance[m][j]+60 ;
						distance[j][i] = distance[i][m]+distance[m][j]+60 ;
					}
				}
			}
		}

		if(distance[0][k]<0)
			cout << "IMPOSSIBLE" << endl ;
		else
			cout << distance[0][k] << endl ;
	}

	return 0 ;
}
