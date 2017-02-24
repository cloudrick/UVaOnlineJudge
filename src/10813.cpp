
#include<iostream>
#include<set>

using namespace std ;

class number
{
public :
	int x ;
	int y ;
	int key ;
	number(int xx,int yy,int kk) : x(xx) ,y(yy),key(kk) {} ;
	bool operator==(const number&) const ;
	bool operator<(const number&) const ;
} ;

bool number::operator==(const number& r) const 
{
	return key == r.key ;
}

bool number::operator<(const number& r) const 
{
	return key < r.key ;
}

int main()
{
	int n ;

	cin >> n ;

	while(n--)
	{
		int map[12] ;
		set<number> data ;
		int i,j ;

		for( i=0 ; i<12 ; ++i) map[i] = 0 ;

		for( i=1 ; i<=5 ; ++i)
		{
			for( j=1 ; j<=5 ; ++j)
			{
				if( i==3 && j==3) continue ;
				int key ;
				cin >> key ;
				number tmp(i,j,key) ;
				data.insert(tmp) ;
			}
		}

		bool bingo = false ;
		int step ;
		for( i=0 ; i<75 ; ++i)
		{
			int key ;
			cin >> key ;

			if(bingo)
				continue ;

			set<number>::iterator idx ;

			if( (idx = data.find( number(0,0,key)))!= data.end() )
			{
				int x = (*idx).x ;
				int y = (*idx).y+5 ;

				map[x]++ ;
				map[y]++ ;

				if( x==y-5 )
					map[11]++ ;
				if( x+y==11)
					map[0]++ ;

				if( map[x]==5 || map[y]==5 || map[0]>=4 || map[11]>=4 || map[3]==4 || map[8]==4)
				{
					step = i+1 ;
					bingo = true ;
				}

			}
		}

		cout << "BINGO after " << step << " numbers announced" << endl ;
	}

	return 0 ;
}