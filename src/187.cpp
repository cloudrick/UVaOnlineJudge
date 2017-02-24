
#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<set>
#include<map>

using namespace std ;

class Trans
{
public :
	int value ;
	string sn ;
	map<string,int> detail ;
} ;

int main()
{
	map<string,string> Account ;

	for(;;)
	{
		char line[100] ;

		cin.getline(line,99) ;

		string acc = line ;
		acc = string( acc.begin() , acc.begin()+3 ) ;

		string scb = line ;
		scb = string( scb.begin()+3 , scb.end() ) ;

		if( acc == "000")
			break ;

		Account.insert( make_pair(acc,scb) ) ;
	}

	vector<Trans> trans ;

	for(;;)
	{
		char line[100] ;
		cin.getline(line,99) ;

		char sn[10] ;
		int d ;

		sscanf( line , "%s %d",sn,&d) ;

		string snn = sn ;

		if( snn == "000000" )
			break ;

		string acc = string( snn.begin()+3 , snn.begin()+6 ) ;
		snn = string( snn.begin() , snn.begin()+3 ) ;

		bool found = false ;
		for( int i=0 ; i<trans.size() ; ++i)
		{
			if( trans[i].sn == snn )
			{
				trans[i].value += d ;
				trans[i].detail.insert( make_pair(acc,d) ) ;
				found = true ;
				break ;
			}
		}

		if( !found )
		{
			Trans t ;
			t.sn = snn ;
			t.value = d ;
			t.detail.insert( make_pair(acc,d) ) ;
			trans.push_back(t) ;
		}
	}

	for(int i=0 ; i<trans.size() ; ++i)
	{
		if( trans[i].value != 0 )
		{
			if( trans[i].value < 0 )
				trans[i].value = -trans[i].value ;

			printf("*** Transaction %s is out of balance ***\n" , trans[i].sn.c_str() ) ;

			for( map<string,int>::iterator j=trans[i].detail.begin() ; 
			     j!=trans[i].detail.end() ; ++j)
			{
				printf("%s %-30s %10.2f\n" , (*j).first.c_str() , 
					                  (*Account.find( (*j).first )).second.c_str() ,
									  (float)(*j).second / 100 ) ;
		
			}

			printf("999 Out of Balance                 %10.2f\n\n" , (float)trans[i].value/100) ;
		}
	}

	return 0 ;
}