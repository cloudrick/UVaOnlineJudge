
#include<stdio.h>
#include<string.h>

int m,n,i,j ;
char str1[2000],str2[2000] ;
int table[2000][2000],d[2000][2000],len ;

int main()
{
	while(gets(str1)){
		gets(str2) ;
		m = int(strlen(str1)) ;
		n = int(strlen(str2)) ;
		for(i=0;i<2000;i++) table[i][0] = 0 ;
		for(j=0;j<2000;j++) table[0][j] = 0 ;

		for(i=1;i<=m;i++){
			for(j=1;j<=n;j++){
				if(str1[i-1] == str2[j-1]){
					table[i][j] = table[i-1][j-1] + 1 ;
					d[i][j] = 2 ;
				}
				else if(table[i-1][j]>=table[i][j-1]){
					table[i][j] = table[i-1][j] ;
					d[i][j] = 1 ;
				}
				else{
					table[i][j] = table[i][j-1] ;
					d[i][j] = 3 ;
				}
			}
		}
		i=m ; j=n ;
		len = 0 ;
		while(1){
			if(i==0||j==0) break ;
			if(d[i][j]==1)
				i-- ;
			else if(d[i][j]==3)
				j-- ;
			else{
				i-- ;
				j-- ;
				len++ ;
			}
		}
		printf("%d\n",len) ;
	}
	return 0 ;
}
