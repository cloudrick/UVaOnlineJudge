
#include<iostream>
#include<cmath>

using namespace std ;

int main()
{
	
	cout <<   0   << ' ' << 13200 << endl ;
	cout <<   0   << ' ' << 16800 << endl ;
	cout <<  3500   << ' ' <<  4800 << endl ;
	cout <<  3500   << ' ' << 25200 << endl ;
	cout <<  9900   << ' ' <<   0 << endl ;
	cout <<  9900   << ' ' << 30000<< endl ;
	cout << 22400   << ' ' <<   0 << endl ;
	cout << 22400   << ' ' << 30000 << endl ;
	cout << 28800   << ' ' <<  4800 << endl ;
	cout << 32300   << ' ' << 13200 << endl ;
	cout << 32300   << ' ' << 16800 << endl ;
	cout << 28800   << ' ' << 25200 << endl ;
	cout << 2816   << ' ' << 5712 << endl ;



/*
	for(int i=0 ; i<=33000 ; i+=1)
	{
		for( int j=0 ; j<=33000 ; j+=1)
		{
			if( i==0 && j==13200 ) continue ;
			if( i==0 && j==16800 ) continue ;
			if( i==3500 && j==4800 ) continue ;
			if( i==3500 && j==25200 ) continue ;
			if( i==9900 && j==0 ) continue ;
			if( i==9900 && j==30000 ) continue ;
			if( i==22400 && j==0 ) continue ;
			if( i==22400 && j==30000 ) continue ;
			if( i==28800 && j==4800 ) continue ;
			if( i==32300 && j==13200 ) continue ;
			if( i==32300 && j==16800 ) continue ;
			if( i==28800 && j==25200 ) continue ;

			int d ;

			d = sqrt( pow(i-0,2) + pow(j-13200,2) ) ;
			if( d*d != pow(i-0,2) + pow(j-13200,2) )
				continue ;

			d = sqrt( pow(i-0,2) + pow(j-16800,2) ) ;
			if( d*d != pow(i-0,2) + pow(j-16800,2) )
				continue ;

			d = sqrt( pow(i-3500,2) + pow(j-4800,2) ) ;
			if( d*d != pow(i-3500,2) + pow(j-4800,2) )
				continue ;

			d = sqrt( pow(i-3500,2) + pow(j-25200,2) ) ;
			if( d*d != pow(i-3500,2) + pow(j-25200,2) )
				continue ;

			d = sqrt( pow(i-9900,2) + pow(j-0,2) ) ;
			if( d*d != pow(i-9900,2) + pow(j-0,2) )
				continue ;

			d = sqrt( pow(i-9900,2) + pow(j-30000,2) ) ;
			if( d*d != pow(i-9900,2) + pow(j-30000,2) )
				continue ;

			d = sqrt( pow(i-22400,2) + pow(j-0,2) ) ;
			if( d*d != pow(i-22400,2) + pow(j-0,2) )
				continue ;

			d = sqrt( pow(i-22400,2) + pow(j-30000,2) ) ;
			if( d*d != pow(i-22400,2) + pow(j-30000,2) )
				continue ;

			d = sqrt( pow(i-28800,2) + pow(j-4800,2) ) ;
			if( d*d != pow(i-28800,2) + pow(j-4800,2) )
				continue ;

			d = sqrt( pow(i-32300,2) + pow(j-13200,2) ) ;
			if( d*d != pow(i-32300,2) + pow(j-13200,2) )
				continue ;

			d = sqrt( pow(i-32300,2) + pow(j-16800,2) ) ;
			if( d*d != pow(i-32300,2) + pow(j-16800,2) )
				continue ;

			d = sqrt( pow(i-28800,2) + pow(j-25200,2) ) ;
			if( d*d != pow(i-28800,2) + pow(j-25200,2) )
				continue ;


			if( sqrt( pow(i-16150,2)+pow(j-15000,2) ) == 16250  )
			{
				cout << i << ' ' << j << endl ;
				continue ;
			}

		}
	}
*/
	return 0 ;
}
