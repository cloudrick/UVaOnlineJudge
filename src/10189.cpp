
/* @JUDGE_ID: 7008MR 10189 C++ */

#include<stdio.h>

int main()
{
	int table[110][110],num[110][110] ;
	int n,m,i,j,k ;
	char c ;

	for(k=1;scanf("%d %d",&n,&m)==2;k++){
		if(n==0 && m==n)
			break ;
		printf("Field #%d:\n",k) ;
		for(i=0 ; i<=n+1 ; i++){
			for(j=0 ; j<=m+1 ; j++){
				num[i][j] = 0 ;
				if(i==0||j==0||i==n+1||j==m+1){
					table[i][j] = 0 ;
					continue ;
				}
				scanf("%c\n",&c) ;
				if(c=='.')
					table[i][j] = 0 ;
				else if(c=='*')
					table[i][j] = 1 ;
			}
		}
		for(i=1 ; i<=n ; i++){
			for(j=1;j<=m;j++){
				if(table[i][j]==1){
					num[i][j] = -1 ;
					continue ;
				}
				if(table[i-1][j-1]==1)
					num[i][j]++ ;
				if(table[i-1][j]==1)
					num[i][j]++ ;
				if(table[i-1][j+1]==1)
					num[i][j]++ ;
				if(table[i][j-1]==1)
					num[i][j]++ ;
				if(table[i][j+1]==1)
					num[i][j]++ ;
				if(table[i+1][j-1]==1)
					num[i][j]++ ;
				if(table[i+1][j]==1)
					num[i][j]++ ;
				if(table[i+1][j+1]==1)
					num[i][j]++ ;
			}
		}
		for(i=1 ; i<=n ; i++){
			for(j=1;j<=m;j++){
				if(num[i][j]==-1)
					printf("*") ;
				else
					printf("%d",num[i][j]) ;
			}
			printf("\n") ;
		}
	}
	return 0 ;
}