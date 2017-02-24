
#include<cstdio>
#include<string>
#include<cstdlib>
#include<iostream>

using namespace std ;

class mmm
{
public :
	int n ;
	string str ;
	bool operator>(const mmm &p)
	{ return ( n > p.n ); }
} ;

int len ;

int main()
{
	int nn ;
	char tmp[100000],*str ;
	mmm table[10000] ;

	scanf("%d\n",&nn) ;

	while(nn--)
	{

		scanf("\n") ;

		long int i,j ;

	
		gets(tmp) ;

		i=len=0 ;

		table[i++].n = atoi( strtok(tmp," \n")) ;
	
		while( str = strtok(NULL," \n") ) 
		{
			if(!str) break ;
			table[i++].n = atoi(str) ;
		}

		len = i ;

		gets(tmp) ;
	
		i=0 ;

		table[i++].str = strtok(tmp," ") ;

		while( str = strtok(NULL," ") ) 
		{
			if(!str) break ;
			table[i++].str = str ;
		}

		for( j=1 ; j<len ; j++ )
		{
			mmm k = table[j] ;
			i=j-1 ;
			while( i>=0 && table[i]>k)
			{
				table[i+1] = table[i] ;
				i-- ;
			}
			table[i+1] = k ;
		}

		for( i=0 ; i<len ; i++)
			cout << table[i].str << endl ;
		cout << endl ;
	}

	return 0 ;
}