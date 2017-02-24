
#include<iostream>
#include<algorithm>

using namespace std ;

bool check(int c,int x,int y,int z)
{
	if( (c%4 == 0 && x==0) || ( x%4==0 && x!=0 ) )
	{
		if( y<=12 && y>=1)
		{
			if( ((y==1 || y==3 || y==5 || y==7 || y==8 || y==10 || y==12) && z>=1 && z<=31) || 
				((y==4 || y==6 || y==9 || y==11) && (z>=1 && z<=30)) || ( y==2 && z>=1 && z<=29) )
			{
				x%=100 ;
				if( x<10 )
					cout << '0' ;
				cout << x << ' ' ;
				if( y<10)
					cout << '0' ;	
				cout << y << ' ' ;
				if( z<10)
					cout << '0' ;
				cout << z << endl ;
				return true ;
			}
		}
	}
	else
	{
		if( y<=12 && y>=1)
		{
			if( ((y==1 || y==3 || y==5 || y==7 || y==8 || y==10 || y==12) && z>=1 && z<=31) || 
				((y==4 || y==6 || y==9 || y==11) && (z>=1 && z<=30)) || ( y==2 && z>=1 && z<=28) )
			{
				x%=100 ;
				if( x<10 )
					cout << '0' ;
				cout << x << ' ' ;
				if( y<10)
					cout << '0' ;	
				cout << y << ' ' ;
				if( z<10)
					cout << '0' ;
				cout << z << endl ;
				return true ;
			}
		}
	}
	return false ;
}

int main()
{
	int n ;
	cin >> n ;

	while(n--)
	{
		int c,x,y,z ;

		cin >> c >> x >> y >> z ;

		if( x>y )
			x^=y^=x^=y ;
		if( y>z )
			y^=z^=y^=z ;
		if( x>y )
			x^=y^=x^=y ;


		if( z>=100 )
		{
			while(1) ;
		}

		int A[3] = { x,y,z } ;
		int time = 6 ;

		while( time-- )
		{
			if( check (c,A[0],A[1],A[2]) )
				break ;
			next_permutation(A,A+3) ;
		}

		if( time < 0 )
			cout << -1 << endl ;

	}

	return 0 ;
}
