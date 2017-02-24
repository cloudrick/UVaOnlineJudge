
#include<stdio.h>

int main()
{
	int n,m,t[25],s ;

	int i,j ;
	scanf("%d",&n);
	while(n--){
		scanf("%d",&m);
		s=0 ;
		for(i=0;i<m;i++){
			scanf("%d",&t[i]) ;
			s+=t[i] ;
		}
		if(s!=(s/4)*4){
			printf("no\n") ;
			continue ;
		}
		s/=4 ;
		
	}
	return 0 ;
}