
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>

using namespace std ;

int FindEquel(string str)
{
	for( int i=0 ; i<str.length() ; ++i)
	{
		if( str[i] == '=' )
			return i ;
	}
	return -1 ;
}

int main()
{
	int n ;
	cin >> n ;

	for( int nn=1 ; nn<=n ; ++nn)
	{
		cout << "Problem #" << nn << endl ;

		char tmp[200] ;

		do
		{
			cin.getline(tmp,199) ;
		}while( strlen(tmp)==0 ) ;

		string line = tmp ;


		bool bp = false ;
		bool bu = false ;
		bool bi = false ;
		double vp = 0.0 ;
		double vu = 0.0 ;
		double vi = 0.0 ;

		int c = 2 ;

		for( ; c-- ; )
		{			
			int e = FindEquel(line) ;
			if( line[e-1] == 'P' )
			{
				bp = true ;
				double tmpd = 0 ;
				int tmpc = 0 ;
				bool flag = false ;
				for( int i=e+1 ; i<line.length() ; ++i)
				{
					if( line[i] >= '0' && line[i]<='9' )
					{
						tmpd = (tmpd*10) + line[i] - '0' ;
						if( flag )
							tmpc++ ;
					}
					else if( line[i] == '.' )
					{
						flag = true ;
					}
					else if( line[i] == 'm' )
					{
						vp = tmpd/pow(10.0,tmpc)/1000 ;
						break ;
					}
					else if( line[i] == 'k' )
					{
						vp = tmpd/pow(10.0,tmpc)*1000 ;
						break ;
					}
					else if( line[i] == 'M' )
					{
						vp = tmpd/pow(10.0,tmpc)*1000000 ;
						break ;
					}
					else
					{
						vp = tmpd/pow(10.0,tmpc) ;
						break ;
					}
				}
			}
			else if( line[e-1] == 'U' )
			{
				bu = true ;
				double tmpd = 0 ;
				int tmpc = 0 ;
				bool flag = false ;
				for( int i=e+1 ; i<line.length() ; ++i)
				{
					if( line[i] >= '0' && line[i]<='9' )
					{
						tmpd = (tmpd*10) + line[i] - '0' ;
						if( flag )
							tmpc++ ;
					}
					else if( line[i] == '.' )
					{
						flag = true ;
					}
					else if( line[i] == 'm' )
					{
						vu = tmpd/pow(10.0,tmpc)/1000 ;
						break ;
					}
					else if( line[i] == 'k' )
					{
						vu = tmpd/pow(10.0,tmpc)*1000 ;
						break ;
					}
					else if( line[i] == 'M' )
					{
						vu = tmpd/pow(10.0,tmpc)*1000000 ;
						break ;
					}
					else
					{
						vu = tmpd/pow(10.0,tmpc) ;
						break ;
					}
				}
			}
			else if( line[e-1] == 'I' )
			{
				bi = true ;
				double tmpd = 0 ;
				int tmpc = 0 ;
				bool flag = false ;
				for( int i=e+1 ; i<line.length() ; ++i)
				{
					if( line[i] >= '0' && line[i]<='9' )
					{
						tmpd = (tmpd*10) + line[i] - '0' ;
						if( flag )
							tmpc++ ;
					}
					else if( line[i] == '.' )
					{
						flag = true ;
					}
					else if( line[i] == 'm' )
					{
						vi = tmpd/pow(10.0,tmpc)/1000 ;
						break ;
					}
					else if( line[i] == 'k' )
					{
						vi = tmpd/pow(10.0,tmpc)*1000 ;
						break ;
					}
					else if( line[i] == 'M' )
					{
						vi = tmpd/pow(10.0,tmpc)*1000000 ;
						break ;
					}
					else
					{
						vi = tmpd/pow(10.0,tmpc) ;
						break ;
					}
				}
			}

			line = string( line.begin()+e+1 , line.end() ) ;
		}

		if( bp && bu )
		{
			printf("I=%.2lfA\n\n" , vp/vu ) ;
		}
		else if( bp && bi )
		{
			printf("U=%.2lfV\n\n" , vp/vi ) ;
		}
		else if( bu && bi )
		{
			printf("P=%.2lfW\n\n" , vu*vi ) ;
		}
	}

	return 0 ;
}
