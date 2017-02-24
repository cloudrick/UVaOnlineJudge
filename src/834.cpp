
#include<cstdio>

int main()
{
	int a,b ;
	bool flag ;

	while(scanf("%d%d",&a,&b)==2)
	{
		printf("[") ;

		flag = true ;
		printf("%d;",a/b) ;
		a = a%b ;

		while(true)
		{
			if(a==1){
				if(!flag) printf(",") ;
				printf("%d",b) ;
				break ;
			}		
			if(a<b)	a^=b^=a^=b ;
			if(!flag) 
				printf(",") ;
			printf("%d",a/b) ;
			flag = false ;
			a = a%b ;
		}

		printf("]\n") ;
	}

	return 0 ;
}