
#include<cstdio>

bool check(long int a,long int b)
{
	bool used[10] ;
	int i ;

	for(i=0 ; i<10 ; i++)
		used[i] = false ;
	for(i=0 ; i<5 ; i++)
	{
		used[a%10] = true ;
		a/=10 ;
	}
	for(i=5 ; i<10 ; i++)
	{
		used[b%10] = true ;
		b/=10 ;
	}

	for(i=0 ; i<10 ; i++){
		if(used[i]==false)
			return false ;
	}
	return true ;
}

int main()
{

	long int n,i ;
	bool flag ;

	while(scanf("%d",&n)==1)
	{
		if(n==0) break ;

		flag = false ;

		for(i=1234 ; i<=98765 ; i++)
		{	
			if(i*n >= 100000) continue ;
			if(check(i,i*n)){
				if(i*n <10000) 
					printf("0") ;
				printf("%ld",i*n) ;

				printf(" / ") ;
				
				if(i <10000) 
					printf("0") ;
				printf("%ld",i) ;

				printf(" = %ld\n",n) ;
				flag = true ;
			}
		}

		if(!flag)
			printf("There are no solutions for %ld.\n",n) ;

		printf("\n") ;

	}

	return 0 ;
}