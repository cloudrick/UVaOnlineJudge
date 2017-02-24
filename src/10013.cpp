
/* @JUDGE_ID: 7008MR 10013 C++ */

#include<stdio.h>

int main()
{
	int n,s[100][100],s1,s2,c ;
	long int m,i,j,k ;
	scanf("%d",&n) ;

	while(n--){
		scanf("%ld",&m) ;
		for(k=m ; k>=0 ; k--){
			i=k/1000 ;
			j=k%1000 ;
			if(k==m){
				s[i][j] = 0 ;
				continue ;
			}
			scanf("%d %d",&s1,&s2) ;
			s[i][j] = s1 + s2 ;
		}
		for(k=0,c=0 ; k<m ; k++){
			i=k/1000 ;
			j=k%1000 ;
			s[i][j] += c ;
			if(s[i][j]>9){
				c=1 ;
				s[i][j] %= 10 ;
			}
			else 
				c=0 ;
		}
		for(k=m ; k>=0 ; k--){
			i=k/1000 ;
			j=k%1000 ;
			if(!(k==m&&s[i][j]==0))
				printf("%d",s[i][j]) ;
		}
		printf("\n") ;
	}
	return 0 ;
}