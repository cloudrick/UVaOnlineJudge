
#include<iostream>
#include<cmath>
#include<vector>

using namespace std ;

const double r = 6366.197723676 ;

class CPoint
{
public :
	double x ;
	double y ;
	double z ;
} ;

bool CanBeHit(vector<CPoint> &s , CPoint &t)
{
	for( vector<CPoint>::iterator i=s.begin() ; 
	     i!=s.end() ; ++i )
	{
		double theta_t = (*i).x*t.x + (*i).y*t.y + (*i).z*t.z ;
		double theta_i = r / sqrt( pow((*i).x,2)+pow((*i).y,2)+pow((*i).z,2) ) ;
		theta_t /= sqrt( pow((*i).x,2)+pow((*i).y,2)+pow((*i).z,2) ) ;
		theta_t /= sqrt( pow(t.x,2)+pow(t.y,2)+pow(t.z,2) ) ;

		if( acos(theta_t) <= acos(theta_i) )
			return true ;
	}
	return false ;
}

int main()
{
	int i ;

	for(;;)
	{
		int k,m ;

		cin >> k >> m ;

		if( k==0 && m==0 )
			break ;

		vector<CPoint> satellite ;

		for( i=0 ; i<k ; ++i)
		{
			CPoint tmp ;
			cin >> tmp.x >> tmp.y >> tmp.z ;
			satellite.push_back(tmp) ;
		}

		int hits = 0 ;

		for( i=0 ; i<m ; ++i)
		{
			CPoint tmp ;
			cin >> tmp.x >> tmp.y >> tmp.z ;

			if( CanBeHit(satellite,tmp) )
				hits++ ;
		}

		cout << hits << endl ;
	}

	return 0 ;
}