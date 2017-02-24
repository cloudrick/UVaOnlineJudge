
#include<iostream>
#include<list>
#include<string>

using namespace std ;

class Car
{
public :
	int arive_time ;
	int dir ;
	int order ;
} ;

int main()
{

	int c ;
	cin >> c ;

	while(c--)
	{
		int n ;
		int t ;
		int m ;

		list<Car> jobs ;
		
		cin >> n >> t >> m ;

		for(int i=0 ; i<m ; ++i)
		{
			Car tmp ;
			string d ;

			tmp.order = i ;
			cin >> tmp.arive_time >> d ;

			if( d == "left" )
				tmp.dir = 0 ;
			else
				tmp.dir = 1 ;

			jobs.push_back(tmp) ;
		}

		int now_time = 0 ;
		int now_dir = 0 ;
		int now_load = 0 ;
		int unload_time[10010] ;

		while( !jobs.empty() )
		{
			list<Car>::iterator p = jobs.begin() ;

			now_load = 0 ;

			bool flag = false ;
			
			while( (*p).arive_time <= now_time && now_load<n)
			{
				if( (*p).dir == now_dir )
				{
					now_load++ ;
					unload_time[(*p).order] = now_time+t ;
					flag = true ;
					jobs.erase(p) ;
					p = jobs.begin() ;
				}
				else
				{
					p++ ;
				}

				if( p == jobs.end() )
					break ;
			}

			if( flag )
			{
				now_time += t ;
				now_dir = (now_dir+1)%2 ;
			}
			else
			{
				p = jobs.begin() ;
				if( (*p).dir != now_dir )
				{
					now_time = max( (*p).arive_time, now_time )+ t ;
					now_dir = (now_dir+1)%2 ;
				}
				else
				{
					now_time = max( (*p).arive_time, now_time ) ;
				}
			}

		}

		for( int j=0 ; j<m ; ++j)
			cout << unload_time[j] << endl ;
		if( c!=0 )
			cout << endl ;
	}

	return 0 ;
}
