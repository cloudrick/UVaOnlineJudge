
#include<cstdio>

int main()
{
	int i,n,m ;
	double table[53] ;

	table[0] = table[1] = 1 ;

	for( i=2 ; i<53 ; i++)
		table[i] = table[i-1] + table[i-2] ;

	scanf("%d",&n) ;

	for(i=1 ; i<=n ; i++)
	{	
		scanf("%d",&m) ;
		printf("Scenario #%d:\n%.0lf\n\n",i,table[m+1]) ;
	}
	return 0 ;
}