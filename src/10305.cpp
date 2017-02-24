
#include<stdio.h>

int main()
{
	int t[110],n,m,tmp[100][2] ;
	int i,j,k ;

	while(scanf("%d%d",&n,&m)==2){
		if(n==0&&m==0) break ;
		for(i=0;i<110;i++) t[i] = i*100 ;
		for(k=0 ; k<m ; k++)
			scanf("%d%d",&tmp[k][0],&tmp[k][1]) ;
		for(k=0;k<m;k++)
			if(t[tmp[k][0]]<=t[tmp[k][1]]) t[tmp[k][0]] = t[tmp[k][1]]+1 ;
		for(k=m-1;k>=0;k--)
			if(t[tmp[k][0]]<=t[tmp[k][1]]) t[tmp[k][0]] = t[tmp[k][1]]+1 ;
		for(k=0;k<m;k++)
			if(t[tmp[k][0]]<=t[tmp[k][1]]) t[tmp[k][0]] = t[tmp[k][1]]+1 ;
		for(k=m-1;k>=0;k--)
			if(t[tmp[k][0]]<=t[tmp[k][1]]) t[tmp[k][0]] = t[tmp[k][1]]+1 ;

		for(i=11000;i>=0;i--){
			for(j=n;j>=1;j--)
				if(t[j]==i) printf("%d ",j) ;
		}
		printf("\n") ;
	}
	return 0 ;
}