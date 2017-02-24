
#include<stdio.h>

int main()
{
	int num[1010],n ;
	int i ;
	double average,m,j ;
	
	scanf("%d",&n) ;
	while(n--)
	{
		scanf("%lf",&m) ;
		average=0 ;

		for(i=0;i<m;i++)
		{
			scanf("%d",&num[i]) ;
			average += num[i] ;
		}

		average /= m ;
		j=0 ;

		for(i=0;i<m;i++)
		{
			if(num[i]>average)
				j++ ;
		}
		printf("%.3lf%%\n",(100*j)/m) ;
	}
	return 0 ;
}