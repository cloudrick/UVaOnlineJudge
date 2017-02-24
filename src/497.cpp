
#include<cstdio>
#include<cstring>

int main()
{
	int n,a[2000],b[2000],c[2000] ;
	int ai,ci,lasti ;

	int i,j ;
	char tmp[10] ;
	int maxlen ;

	scanf("%d\n",&n) ;

	while( n-- )
	{
		ai = ci = 0 ;

		strcpy(tmp,"") ;

		while(gets(tmp))
		{
			if( strlen( tmp )==0 ) 
				break ;
			sscanf(tmp,"%d",&a[ai++]) ;

		}

		maxlen = 1 ;
		lasti = 0 ;

		for( i=0 ; i<ai ; i++)
		{
			b[i] = 1 ;
			c[i] = -1 ;
			

			for( j=0 ; j<i ; j++)
			{
				if( a[j] < a[i] && b[j]+1>b[i] )
				{
					b[i] = b[j] + 1 ;
					c[i] = j ;					
				}
			}
			if( b[i]>=maxlen)
			{
				maxlen = b[i] ;
				lasti  = i ;
			}
		}

		printf("Max hits: %d\n",maxlen) ;

		int oi=0 , out[2000] ;

		for( i=lasti ; i>=0 ; i = c[i] )
			out[oi++] = a[i] ;

		for( i=oi-1 ; i>=0 ; i--)
			printf("%d\n",out[i]) ;
		printf("\n") ;

	}

	return 0 ;
}
