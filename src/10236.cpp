
#include<stdio.h>

int nn[22001][3000] ;

int main()
{
	int i,j,n ;
	bool f ;

	nn[0][0]=nn[1][0]=1 ;
	for(i=1;i<3000;i++) nn[0][i]=nn[1][i]=0 ;
	for(i=2;i<22001;i++){
		for(j=0;j<3000;j++)
			nn[i][j] = nn[i-1][j] + nn[i-2][j] ;
		for(j=0;j<2999;j++){
			if(nn[i][j]>9){
				nn[i][j+1] += (nn[i][j]/10) ;
				nn[i][j] %= 10 ;
			}
		}
	}
	while(scanf("%d",&n)==1){
		i=0;
		j=2999 ;
		f=false ;
		while(i<9 && j>=0){
			if((nn[n-1][j]!=0) || f){
				printf("%d",nn[n-1][j]) ;
				f=true ;
				i++;
			}
			j-- ;
		}
		printf("\n") ;
	}
	return 0 ;
}