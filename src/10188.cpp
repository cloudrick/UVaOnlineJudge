
#include<cstdio>
#include<cstdlib>
#include<cstring>

bool num_match(char *a , int n , char *b , int m)
{
	bool found_num = false ;
	bool all_match = false ;

	int *aa , ai=0 , *bb , bi=0 ;
	int i ;

	aa = new int[128*n] ;
	bb = new int[128*m] ;

	for(i=0 ; i<128*n ; i++)
	{
		if( a[i]>='0' && a[i]<='9')
		{
			aa[ai++] = a[i] - '0' ;
			found_num = true ;
		}
	}

	for(i=0 ; i<128*m ; i++)
	{
		if( b[i]>='0' && b[i]<='9')
		{
			bb[bi++] = b[i] - '0' ;
			found_num = true ;
		}
	}

	if( ai==bi  && ai !=0)
	{
		all_match = true ;
		for( i=0 ; i<ai ; i++)
		{
			if( aa[i] != bb[i])
			{
				all_match = false ;
				break ;
			}
		}
	}

	delete [] aa ;
	delete [] bb ;

	if( found_num == false || all_match == true )
		return true ;
	else
		return false ;

}

bool match( char *a , int n , char *b , int m )
{
	if(n!=m) return false ;

	for( int i=0 ; i<n ; i++)
	{
		if( strcmp( &a[i*128] , &b[i*128] )!=0 )
			return false ;
	}

	return true ;
}

int main()
{
	int n,m,i ;

	char *ans_data ;
	char *in_data ;
	char tmp[10] ;

	long int nn ;

	nn=1 ;

	while( gets(tmp) != NULL )
	{
		n = atol(tmp) ;

		if( n==0 )
			break ;

		ans_data = new char[128*n] ;

		for(i=0 ; i<128*n ; i++)
			ans_data[i] = '\0' ;
		
		for(i=0 ; i<n ; i++)
		{
			gets(&ans_data[i*128]) ;
		}

		gets(tmp) ;
		m = atol(tmp) ;

		in_data = new char[128*m] ;

		for(i=0 ; i<128*m ; i++)
			in_data[i] = '\0' ;

		for(i=0 ; i<m ; i++)
		{
			gets( &in_data[i*128] ) ;
		}

		if(  match( ans_data , n , in_data , m )  ) 
		{
			printf("Run #%d: Accepted\n", nn++ ) ;
		}
		else if( num_match( ans_data , n , in_data , m ) )
		{
			printf("Run #%d: Presentation Error\n", nn++) ;
		}
		else
		{
			printf("Run #%d: Wrong Answer\n", nn++ ) ;
		}
		delete [] ans_data ;
		delete [] in_data ;
	}

	return 0 ;
}