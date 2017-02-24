
#include<stdio.h>

int main()
{
	int N,k,m,d[25],i,j,r,l ;
	while(1){
		scanf("%d %d %d",&N,&k,&m) ;
		if(N==0 && k==0 && m==0)
			break ;
		for(i=0;i<=N+1;i++)
			d[i] = (i==N+1 || i==0) ? 0:1 ;
		j = N ;
		for(r=0,l=N+1;j>0;){
			for(i=0;i<k;){
				if(r==N)
					r=1 ;
				else
					r++ ;
				if(d[r])
					i++ ;
			}
			for(i=0;i<m;){
				if(l==1)
					l=N ;
				else
					l-- ;
				if(d[l])
					i++ ;
			}
			if(r==l){
				d[r]=0 ;
				j-- ;
				printf("%3d",r) ;
				if(j)
					printf(",") ;
			}
			else{
				j-=2 ;
				d[r] = d[l] = 0 ;
				printf("%3d%3d",r,l) ;
				if(j)
					printf(",");
			}
		}
		printf("\n") ;
	}
	return 0 ;
}