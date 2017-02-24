
#include<cstdio>
#include<cstring>

inline long int gcd(long int a,long int b)
{
	while(a)
		a^=b^=a^=b%=a ;
	return b ;
}

int main()
{
	long int i,j,mom,chl,tmp,g ;
	int n,k ;
	char str[20] ;

	n=1 ;

	while( scanf("%d",&j) == 1 )
	{
		if(j<0)
			break ;

		scanf("%s",str) ;

		for(i=0 ; i<int(strlen(str)) ; i++)
		{
			if(str[i]=='.')
			{
				 k=i+1 ;
				 break ;
			}
		}

		if(j==0){
			mom = 1 ;
			chl = 0 ;
			for(i=k ; i<int(strlen(str)) ; i++)
			{
				mom = mom*10 ;
				chl = chl*10 + str[i] - '0' ;
			}
		}
		else
		{
			mom = chl = tmp = 0 ;

			for(i=0 ; i<j ; i++)
				mom = mom*10+9 ;
			for(i=0 ; i< int(strlen(str))-k-j ; i++ )
				mom*=10 ;

			for(i=k ; i<int(strlen(str)) ; i++)
				chl = chl*10 + str[i] - '0' ;
			for(i=k ; i<int(strlen(str))-j ; i++)
				tmp = tmp*10 + str[i] - '0' ;

			chl -= tmp ;
		}

		g = gcd(mom,chl) ;

		if(chl==0){
			printf("Case %d: 0/1\n",n++) ;
			continue ;
		}
		mom/=g ;
		chl/=g ;

		printf("Case %d: %ld/%ld\n",n++,chl,mom) ;
	}

	return 0 ;
}