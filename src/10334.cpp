
#include<stdio.h>
#include<math.h>

int num[1002][500] ;

int main()
{
	int i,j,n ;
	bool flag ;

	for(i=0;i<1002;i++){
		for(j=0;j<500;j++)
			num[i][j] = 0 ;
	}

	num[0][0]=num[1][0]=1 ;

	for(i=2;i<1002;i++){
		for(j=0;j<500;j++)
			num[i][j] = num[i-1][j]+num[i-2][j] ;
		for(j=0;j<499;j++){
			if(num[i][j]>9){
				num[i][j+1] += num[i][j]/10 ;
				num[i][j] %= 10 ;
			}
		}
	}

	while(scanf("%d",&n)==1){
		flag = false ;
		for(i=499;i>=0;i--){
			if(flag || num[n+1][i]!=0){
				printf("%d",num[n+1][i]) ;
				flag = true ;
			}
		}
		printf("\n") ;
	}
	return 0 ;
}