
#include<iostream>
#include<cmath>

using namespace std ;

int main()
{
	for(;;)
	{
		int SZ,P ;

		cin >> SZ >> P ;

		if( SZ==0 && P==0 )
			break ;

		int powp = sqrt(P) ;
		if( powp%2 == 0 )
			powp -=1 ;

		int offset = P - powp*powp ;
		int line = powp + 1 ;

		int x = (SZ/2)+1+(powp/2) ;
		if( offset !=0 )
			x++ ;
		int y = (SZ/2)+1+(powp/2) ;

		bool done ;

		if( offset == 0 )
			done = true ;
		else
			done = false ;

		if( offset > line && !done)
		{
			offset -= line ;
			y = y-line+1 ;
			x-=1 ;
		}
		else if(!done)
		{
			y = y-offset+1 ;
			done = true ;
		}

		if( offset > line && !done)
		{
			offset -= line ;
			x = x-line+1 ;
			y+=1 ;
		}
		else if(!done)
		{
			x = x-offset+1 ;
			done = true ;
		}

		if( offset > line && !done)
		{
			offset -= line ;
			y = y+line-1 ;
			x+=1 ;
		}
		else if(!done)
		{
			y = y+offset-1 ;
			done = true ;
		}

		if(!done)
		{
			x = x+offset-1 ;
			done = true ;
		}

		cout << "Line = " << x << ", column = " << y << '.' << endl ;
	}

	return 0 ;
}
