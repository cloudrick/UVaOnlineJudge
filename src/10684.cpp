
#include<iostream>
#include<cmath>

using namespace std ;

int main()
{
	while(true)
	{
		int n ;
		cin >> n ;

		if(n==0)
			break ;

		int max = 0 ;
		int save = 0 ;
		while(n--)
		{
			int m ;
			cin >> m ;

			if( m>0 )
			{
				save += m ;
			}
			else
			{
				if( save+m > 0 )
					save += m ;
				else
					save = 0 ;
			}

			if( save > max)
				max = save ;
		}

		if(max==0)
			cout << "Losing streak." << endl ;
		else
			cout << "The maximum winning streak is " << max << '.' << endl ;
	}
	return 0 ;
}