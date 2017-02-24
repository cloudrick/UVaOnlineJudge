
#include<stdio.h>

long int table[50002][30] ;

int main()
{
	long int i,j,k ;
	int n ;
	bool f ;
	for(i=1;i<=50000;i++){
		for(j=0;j<30;j++)
			table[i][j]=0 ;
		table[i][0] = 1 ;
		for(k=0;k<3;k++){
			for(j=0;j<30;j++)
				table[i][j]*= i ;
			for(j=0;j<29;j++){
				if(table[i][j]>9){
					table[i][j+1] += table[i][j]/10 ;
					table[i][j]%=10 ;
				}
			}
		}
		if(i>1){
			for(j=0;j<30;j++)
				table[i][j] += table[i-1][j] ;
			for(j=0;j<29;j++){
				if(table[i][j]>9){
					table[i][j+1] += table[i][j]/10 ;
					table[i][j]%=10 ;
				}
			}
		}
	}
	while(scanf("%d",&n)==1){
		f=false ;
		for(i=29;i>=0;i--){
			if(f||table[n][i]!=0){
				printf("%d",table[n][i]) ;
				f=true ;
			}
		}
		printf("\n") ;
	}
	return 0;
}