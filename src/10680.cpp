
#include<stdio.h>
#include<math.h>

bool prime[1000001] = {false};

int table[78498] ;
int table_len = 0 ;

int final[1000001] ;

int GetBaseOfPow(int n)
{
	for( int i=0 ; i<table_len ; i++)
	{
		if( table[i] > n )
			break ;
		if( n%table[i] == 0 )
		{
			while(true)
			{
				n/=table[i] ;
				if(n==1)
					return table[i] ;
				if( n%table[i] !=0 )
					return 0 ;
			}
		}
	}
	return 0 ;
}

inline void multiply( int num[50] , int a )
{
	for( int i=0 ; i<50 ; i++)
	{
		num[i] *= a ;
	}
	for( int j=0 ; j<49 ; j++)
	{
		if( num[j]>=10)
		{
			num[j+1] += num[j]/10 ;
			num[j]%=10 ;
		}
	}
}

int main()
{
	int n ;

	for( int i=2 ; i<=500000 ; i++)
	{
		if( prime[i] == true )
			continue ;
		for( int j=2 ; i*j<=1000000 ; j++)
		{
			prime[i*j] = true ;
		}
	}

	for( int k=2 ; k<=1000000 ; k++)
	{
		if( !prime[k] )
			table[table_len++] = k ;
	}

	int a[50] ;
	for( int ii=0 ; ii<50 ; ii++)
		a[ii] = 0 ;
	a[0] = 1 ;

	for( int jj=1 ; jj<1000001 ; jj++)
	{
		if( prime[jj] == false )
		{
			multiply(a,jj) ;
		}
		else
		{
			int tmp = GetBaseOfPow(jj) ;
			if( tmp>0 )
			{
				multiply(a,tmp) ;
			}
		}
		for( int m=0 ; m<50 ; m++)
		{
			if( a[m] != 0 )
			{
				final[jj] = a[m] ;
				break ;
			}
		}
	}

	while( scanf("%d",&n)==1 )
	{
		if( n==0 )
		{
			break ;
		}

		printf("%d\n",final[n]) ;
	}
	return 0 ;
}