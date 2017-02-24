
#include<iostream>
#include<set>
#include<cmath>

using namespace std ;

inline int gcd( int a ,int b)
{
	if( a<0 )
		a = -a ;
	if( b<0 )
		b = -b ;
	while(b)
		b^=a^=b^=a%=b ;
	return a ;
}



class CPoint
{
public :

	bool operator<(const CPoint &rhs) const
	{
		if( rhs.theta - theta > 0.0000001 ) 
			return true ;
		else if ( theta - rhs.theta > 0.0000001) 
			return false ;
		else
		{
			return r<rhs.r ;
		}
	}

	CPoint(int xx,int yy,int zz): x(xx),y(yy),z(zz)
	{
		int g = gcd( x , y ) ;

		if(g!=0)
		{
			mx = x / g ;
			my = y / g ;
		}

		if( my == 0 )
			mx = 1 ;

		if( mx == 0 )
			my = 1 ;

		r = sqrt( pow(x,2.0)+pow(y,2.0)) ;
		theta = acos(x/r) ;
	}

public:
	int x ;
	int y ;
	int z ;
	int mx,my ;
	double r ;
	double theta ;
} ;


class CPoint2
{
public :
	CPoint2(int xx,int yy):x(xx),y(yy) { }
	bool operator<(const CPoint2 &r) const
	{
		return x<r.x || ( x==r.x && y<r.y) ;
	}
public :
	int x ;
	int y ;
} ;


inline bool aligned( const CPoint &l ,const CPoint &r)
{
	return (l.mx==r.mx) && (l.my==r.my) ;
}

int main()
{
	for(int t=1 ;; ++t)
	{
		int N ;
		cin >> N ;
		if( N==0 )
			break ;

		set<CPoint> S ;
		set<CPoint2> printed ;

		for( int nn=0 ; nn<N ; ++nn)
		{
			int x,y,z ;
			cin >> x >> y >> z ;
			CPoint tmp(x,y,z) ;
			S.insert(tmp) ;
		}

		CPoint buff(0,0,-1) ;

		for( set<CPoint>::iterator i=S.begin() ; i!=S.end() ; )
		{
			if( aligned( *i , buff) )
			{
				if( buff.z >= (*i).z )
				{
					printed.insert( CPoint2( (*i).x , (*i).y ) ) ;
					int tmp = buff.z ;
					buff = (*i) ;
					buff.z = tmp ;
					++i ;
					continue ;
				}
			}
			buff = (*i) ;
			++i ;
		}

		cout << "Data set " << t << ":" << endl ;

		if( printed.empty() )
		{
			cout << "All the lights are visible." << endl ;
		}
		else
		{
			cout << "Some lights are not visible:" << endl ;
			
			int s = printed.size() ;
			int j=0 ;
			for( set<CPoint2>::iterator i=printed.begin() ; j<s ; j++,i++ )
			{
				cout << "x = " << (*i).x << ", y = " << (*i).y ;
				if( j==s-1)
					cout << '.' << endl ;
				else
					cout << ';' << endl ;
			}
		}  

	}

	return 0 ;
}
