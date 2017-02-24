
#include <iostream>
#include <string>
#include <cstdio>
#include <set>

using namespace std ;

class Locality
{
public :
	string local_num ;
	string name ;
	double price ;

	bool operator<(const Locality &rhs ) const 
	{
		return local_num < rhs.local_num ;
	}
	bool operator==(const Locality &rhs ) const 
	{
		return local_num == rhs.local_num ;
	}

} ;

void strip(string &str)
{
	int i ;
	for( i=str.size()-1 ; i>=0 ; --i)
	{
		if( str[i] != ' ' )
			break ;
	}
	str = string( str.begin() , str.begin()+i+1 ) ;
}

int main()
{
	set<Locality> table ;

	for(;;)
	{
		char line[100] ;
		char tt[100] ;

		cin.getline(line,99) ;
		sscanf(line,"%s",tt) ;
		
		string code = tt ;

		if( code == "000000" )
			break ;

		string tmp ;
		tmp = line ;
		tmp = string( tmp.begin()+code.size()+1, tmp.end() ) ;

		Locality t ;
		t.local_num = code ;

		string name ;

		for( int i=0 ; i<tmp.size() ; ++i)
		{
			if( tmp[i] == '$' )
			{
				strip(name) ;
				t.name = name ;
				double p = 0 ;
				for( int j=i+1 ; j<tmp.size() ; ++j)
				{
					if( tmp[j]<'0' || tmp[j]>'9' )
						continue ;
					p = (p*10) + tmp[j] - '0' ;
				}

				t.price = p ;
				break ;
			}
			name += tmp[i] ;
		}

		table.insert(t) ;
	}

	for(;;)
	{
		char line[100] ;
		char tt[100] ;
		int time ;

		cin.getline(line,99) ;

		sscanf(line,"%s %d",tt,&time) ;

		string num ;
		num = tt ;

		if( num == "#" )
			break ;

		if( num[0] == '0' && num[1] == '0' )
		{
			set<Locality>::iterator index = table.end() ;
			int i ;

			for(  i=0 ; i<=3 && index==table.end() && num.size()-2-i>=4 ; ++i )
			{
				if( num.size()-2-i > 10)
					continue ;
				Locality t ;
				t.local_num = string( num.begin() , num.begin()+2+i ) ;
				index = table.find(t) ;
			}
			
			if( index != table.end() )
			{
				printf("%-16s" , num.c_str()  ) ;
				printf("%-25s" , (*index).name.c_str() ) ;
				printf("%10s", string(num.begin()+i+1 , num.end() ).c_str() ) ;
				printf("%5d",time) ;
				printf("%6.2lf",(*index).price/100 ) ;
				printf("%7.2lf", time*((*index).price)/100) ;
				printf("\n") ;
			}
			else
			{
				printf("%-16s" , num.c_str()  ) ;
				printf("%-25s" , "Unknown" ) ;
				printf("%10s", "" ) ;
				printf("%5d",time) ;
				printf("      ") ;
				printf("  -1.00") ;
				printf("\n") ;
			}

		}
		else if(  num[0] == '0' )
		{
			set<Locality>::iterator index = table.end() ;
			int i ;

			for(  i=0 ; i<=5 && index==table.end() && num.size()-1-i>=4 ; ++i )
			{
				if( num.size()-1-i > 7 )
					continue ;
				Locality t ;
				t.local_num = string( num.begin() , num.begin()+1+i ) ;
				index = table.find(t) ;
			}
			
			if( index != table.end() )
			{
				printf("%-16s" , num.c_str()  ) ;
				printf("%-25s" , (*index).name.c_str() ) ;
				printf("%10s", string(num.begin()+i , num.end() ).c_str() ) ;
				printf("%5d",time) ;
				printf("%6.2lf",(*index).price/100 ) ;
				printf("%7.2lf", time*((*index).price)/100) ;
				printf("\n") ;
			}
			else
			{
				printf("%-16s" , num.c_str()  ) ;
				printf("%-25s" , "Unknown" ) ;
				printf("%10s", "" ) ;
				printf("%5d",time) ;
				printf("      ") ;
				printf("  -1.00") ;
				printf("\n") ;
			}
		}
		else
		{
			printf("%-16s" , num.c_str()  ) ;
			printf("%-25s" , "Local" ) ;
			printf("%10s", num.c_str() ) ;
			printf("%5d",time) ;
			printf("  0.00") ;
			printf("   0.00") ;
			printf("\n") ;
		}
	}

	return 0 ;
}