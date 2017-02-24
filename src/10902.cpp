
#include<iostream>
#include<list>
#include<algorithm>

using namespace std ;

class CPoint
{
public :
	double x ;
	double y ;
} ;

class CStick
{
public :
	int num ;
	CPoint p1 ;
	CPoint p2 ;
} ;

double DIRECTION(const CPoint &p1,const CPoint &p2,const CPoint &p3)
{
	return (p2.x-p1.x)*(p3.y-p1.y)-(p3.x-p1.x)*(p2.y-p1.y) ;
}

bool ON_SEGMENT(const CPoint &pi,const CPoint &pj,const CPoint &pk)
{
	if( (min(pi.x,pj.x) <= pk.x && pk.x <= max(pi.x,pj.x)) &&
		(min(pi.y,pj.y) <= pk.y && pk.y <= max(pi.y,pj.y)) )
		return true ;
	else
		return false ;
}


bool SEGMENTS_INTERSECT(const CPoint &p1,const CPoint &p2,const CPoint &p3,const CPoint &p4)
{
	double d1 = DIRECTION(p3, p4, p1) ;
	double d2 = DIRECTION(p3, p4, p2) ;
	double d3 = DIRECTION(p1, p2, p3) ;
	double d4 = DIRECTION(p1, p2, p4) ;

	if( ( (d1>0 && d2<0)||(d1<0 && d2>0) )  &&
		( (d3>0 && d4<0)||(d3<0 && d4>0) ) )
		return true ;
	else if( d1==0 && ON_SEGMENT(p3,p4,p1) )
		return true ;
	else if( d2==0 && ON_SEGMENT(p3,p4,p2) )
		return true ;
	else if( d3==0 && ON_SEGMENT(p1,p2,p3) )
		return true ;
	else if( d4==0 && ON_SEGMENT(p1,p2,p4) )
		return true ;
	else
		return false ;
}

int main()
{
	int n ;

	for(;;)
	{
		cin >> n ;
		if( n==0 )
			break ;

		list<CStick> stick ;

		for( int i=1 ; i<=n ; ++i)
		{
			CStick s ;
			s.num = i ;

			cin >> s.p1.x >> s.p1.y ;
			cin >> s.p2.x >> s.p2.y ;

			for( list<CStick>::iterator j= stick.begin() ;
			     j!=stick.end() ; ++j )
			{
				if( SEGMENTS_INTERSECT(s.p1,s.p2,(*j).p1,(*j).p2))
				{
					stick.erase(j) ;
					j-- ;
				}
			}

			stick.push_back(s) ;
		}

		cout << "Top sticks: " ;

		while( !stick.empty() )
		{
			cout << stick.front().num ;

			if( stick.size() == 1)
			{
				cout << '.' << endl ;
				break ;
			}

			cout << ',' << ' ' ;
			stick.pop_front() ;
		}

	}

	return 0 ;
}
