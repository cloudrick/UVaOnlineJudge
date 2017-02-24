
#include<stdio.h>
#include<string.h>

int main()
{
	char str1[200][30],str2[200][30] ;
	int c[200][200],b[200][200],a[200],aa ;
	int i1,i2,i,j ;
	while(scanf("%s",str1[0])==1){
		i1=0 ;
		for(i1=0;str1[i1++][0]!='#';i++)
			scanf("%s",str1[i1]) ;
		i2=0 ;
		do{
			scanf("%s",str2[i2]) ;
		}while(str2[i2++][0]!='#') ;

		for(i=0;i<=i1;i++)
			c[i][0] = 0 ;
		for(i=0;i<=i2;i++)
			c[0][i] = 0 ;
		for(i=0;i<=i1;i++){
			for(j=0;j<=i2;j++)
				b[i][j] = 0 ;
		}
		for(i=1;i<i1;i++){
			for(j=1;j<i2;j++){
				if(strcmp(str1[i-1],str2[j-1])==0){
					c[i][j] = c[i-1][j-1] + 1 ;
					b[i][j] = 2 ;
				}
				else{
					if(c[i-1][j]>=c[i][j-1]){
						c[i][j] = c[i-1][j] ;
						b[i][j] = 1 ;
					}
					else{
						c[i][j] = c[i][j-1] ;
						b[i][j] = 3 ;
					}
				}
			}
		}
		i=i1-1 ; j=i2-1 ; aa=0 ;
		while(i>0&&j>0){
			if(b[i][j]==1)
				i-- ;	
			if(b[i][j]==3)
				j-- ;
			if(b[i][j]==2){
				a[aa++] = i ;
				i--;j--;
			}
		}
		for(i=aa-1;i>=0;i--)
			printf("%s ",str1[a[i]-1]) ;
		printf("\n") ;
	}
	return 0 ;
}