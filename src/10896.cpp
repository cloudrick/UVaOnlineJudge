
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<set>

using namespace std ;

int main()
{
	char nn[10] ;

	gets(nn) ;

	int n = atoi(nn) ;

	while(n--)
	{
		char line[5000] ;
		gets(line) ;

		char p[80] ;
		gets(p) ;

		char *tmp = strtok(line," ") ;

		set<char> lay_out ;

		while( tmp )
		{
			if( strlen(tmp) == strlen(p) )
			{
				int d = (tmp[0] - p[0] + 26)%26 ;
				bool flag = true ;
				for( int i=1 ; i<strlen(p) ; ++i)
				{
					if( (tmp[i] - p[i] + 26)%26 != d)
					{
						flag = false ;
						break ;
					}
				}
				if(flag)
				{
					lay_out.insert( d+'a') ;
				}
			}
			tmp = strtok(NULL," ") ;
		}

		for( set<char>::iterator i=lay_out.begin() ; i!=lay_out.end() ; ++i)
			printf("%c" , (*i) ) ;
		printf("\n") ;
	}

	return 0 ;
}
