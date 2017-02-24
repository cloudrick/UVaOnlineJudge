
#include<stdio.h>
#include<string.h>

int main()
{
	int c[110][110] ;
	char str1[110],str2[110] ;
	int m,n,i,j,t ;
	t=0 ;
	while(true){
		t++ ;
		gets(str1) ;
		if(str1[0] == '#') break ;
		gets(str2) ;
		m=strlen(str1) ;
		n=strlen(str2) ;
		for(i=0;i<m;i++) c[i][0] = 0 ;
		for(j=0;j<n;j++) c[0][j] = 0 ;

		for(i=0;i<m;i++){
			for(j=0;j<n;j++){
				if(str1[i]==str2[j]){
					c[i+1][j+1] = c[i][j] + 1 ;
				}
				else{
					if(c[i][j+1]>=c[i+1][j])
						c[i+1][j+1] = c[i][j+1] ;
					else 
						c[i+1][j+1] = c[i+1][j] ;
				}
			}
		}

		printf("Case #%d: you can visit at most %d cities.\n",t,c[m][n]) ;
	}
	return 0 ;
}