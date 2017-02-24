
#include<iostream>
#include<vector>

using namespace std ;

enum LIGHT {ttGREEN , ttYELLOW , ttRED } ;

class TLight
{
public :
	LIGHT light ;
	int r_remain ;
	int y_remain ;
	int g_remain ;
	int value ;
} ;

bool ALLGreenLight( vector<TLight> &t )
{
	for( int i=0 ; i<t.size() ; ++i)
	{
		if( t[i].light != ttGREEN )
			return false ;
	}
	return true ;
}

void IncTLight( TLight &t )
{
	if( t.g_remain > 0 )
	{
		if( --t.g_remain == 0 )
			t.light = ttYELLOW ;
	}
	else if( t.y_remain > 0 )
	{
		if( --t.y_remain == 0 )
			t.light = ttRED ;
	}
	else if( t.r_remain > 0 )
	{
		if( --t.r_remain == 0 )
		{
			t.light = ttGREEN ;
			t.r_remain = t.value ;
			t.y_remain = 5 ;
			t.g_remain = t.value - 5 ;
		}
	}

}

int main()
{
	int C = 0 ;
	bool done = false ;

	while(!done)
	{
		vector<TLight> TLights ;
		int min = 1000000000 ;

		while( !done )
		{
			int n ;
			cin >> n ;
			if( n==0 )
			{
				++C ;
				if( C==3 )
				{
					done = true ;
				}
				break ;
			}
			else
			{
				C=0 ;
				TLight t ;
				t.value = n ;
				TLights.push_back(t) ;

				if( n<min )
					min = n ;
			}
		}

		if( C!=1 )
			continue ;

		if(!done)
		{
			int i ;
			for( i=0 ; i<TLights.size() ; ++i)
			{
				TLights[i].light = ttGREEN ;
				TLights[i].r_remain = TLights[i].value ;
				TLights[i].y_remain = 5 ;
				TLights[i].g_remain = TLights[i].value - 5 ;
			}

			int time = 0 ;
			for(;;)
			{
				if( time > 18000 )
				{
					cout << "Signals fail to synchronise in 5 hours" << endl ;
					break ;
				}

				if( time>min )
				{
					if( ALLGreenLight(TLights) )
					{
						int sec = time%60 ;
						time /= 60 ;
						int min = time%60 ;
						time /= 60 ;
						int hour = time ;

						cout << '0' << hour << ':' ;
						if( min < 10)
							cout << '0' ;
						cout << min << ':' ;
						if( sec < 10 )
							cout << '0' ;
						cout << sec << endl ;
						break ;
					}
				}
				
				for( i=0 ; i<TLights.size() ; ++i)
				{
					IncTLight( TLights[i] ) ;
				}
				time++ ;
			}
		}
	}

	return 0 ;
}