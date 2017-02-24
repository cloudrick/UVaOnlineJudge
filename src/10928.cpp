
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	char line[5000] = "\0" ;

	for( ; strlen(line)==0 ; )
	{
		gets(line) ;
	}

	int n = atoi(line) ;

	while(n--)
	{
		strcpy(line,"\0") ;
		for( ; strlen(line)==0 ; )
		{
			gets(line) ;
		}

		int m = atoi(line) ;
		int min = 100000000 ;

		int *C = new int[m] ;

		for(int i=0 ; i<m ; ++i)
		{
			strcpy(line,"\0") ;
			for( ; strlen(line)==0 ; )
			{
				gets(line) ;
			}

			int count = 1 ;

			strtok(line," ") ;

			while( strtok(NULL," ") != NULL )
				count++ ;

			C[i] = count ;

			if( count < min )
				min = count ;
		}

		bool f = false ;
		for( int j=0 ; j<m ; ++j)
		{
			if( C[j] == min )
			{
				if(f)
					printf(" ") ;
				else
					f = true ;
				printf("%d",j+1) ;
			}
		}
		printf("\n") ;

		delete [] C ;
	}

	return 0 ;
}
