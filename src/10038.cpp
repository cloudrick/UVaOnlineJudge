
#include<cstdio>
#include<cmath>
#include<algorithm>

using namespace std ;

int main()
{
	int n,s[3001],d[3001],i ;
	bool flag ;

	while(scanf("%d",&n)==1)
	{
		for(i=0 ; i<n ; i++)
			scanf("%d",&s[i]) ;
		for(i=0 ; i<n-1 ; i++)
			d[i] = fabs(s[i+1]-s[i]) ;
		sort(d,d+n-1) ;

		flag = true ;

		for( i=0 ; i<n-1 ; i++){
			if(d[i]-i!=1){
				flag = false ;
				break ;
			}
		}
		if(flag)
			printf("Jolly\n") ;
		else
			printf("Not jolly\n") ;
	}

	return 0 ;
}