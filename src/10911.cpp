

#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<cstdio>

using namespace std ;

class CPoint
{
public :
	int x ;
	int y ;
} ;



void DFS( double d[][16] , bool s[] ,const int &size, int cur_s, double cur_d,double &min_d )
{
	if( cur_s == size )
	{
		if( cur_d < min_d )
			min_d = cur_d ;
		return ;
	}

	int pivot = -1 ;
	int i ;

	for( i=0 ; i<size ; ++i)
	{
		if( !s[i] )
		{
			s[i] = true ;
			pivot = i ;
			break ;
		}
	}

	for( i=pivot+1 ; i<size ; ++i)
	{
		if( !s[i] )
		{
			if( cur_d + d[i][pivot] > min_d )
				continue ;
			s[i] = true ;
			DFS( d , s , size , cur_s+2 , cur_d + d[i][pivot] , min_d ) ;
			s[i] = false ;
		}
	}

	s[pivot] = false ;
}

int main()
{
	for(int t=1;;++t)
	{
		int N ;
		cin >> N ;
		if(N==0)
			break ;

		vector<CPoint> home ;

		double distance[16][16] ;
		bool selected[16] ;

		for(int i=0 ; i<2*N ; ++i)
		{
			int j ;
			selected[i] = false ;
			for(  j=0 ; j<2*N ; ++j)
				distance[i][j] = -1 ;

			string name ;
			CPoint p ;
			cin >> name >> p.x >> p.y ;

			for(  j=0 ; j<home.size() ; ++j)
			{
				distance[i][j] = distance[j][i] =
					sqrt( pow(p.x-home[j].x,2.0) + pow(p.y-home[j].y,2.0) ) ;
			}
			home.push_back(p) ;
		}
	
		double min_distance = 100000000 ;

		DFS( distance , selected , 2*N , 0 , 0 , min_distance ) ;

		cout << "Case " << t << ": " ;
		printf("%.2lf",min_distance) ;
		cout << endl ;

	}

	return 0 ;
}

 
