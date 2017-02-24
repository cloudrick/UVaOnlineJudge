
#include<stdio.h>

int main()
{
	char str[1000010],tmp ;
	long int n,len,c ;
	long int i,j;
	bool flag ;

	while(scanf("%s",str)==1){
		for(len=0;str[len];len++) ;
		if(str[0]=='.')
			break ;
	
		for(n=len;n>=1;n--){
			if(len%n)
				continue ;
			c = len/n ;
			flag = true ;
			for(i=0;i<c;i++){
				for(j=0;j<n;j++){
					if(j==0){
						tmp = str[i] ;
						continue ;
					}
					else{
						if(str[(j*c)+i]!=tmp){
							flag = false ;
						}

					}
				}
			}
			if(flag){
				printf("%d\n",n) ;
				break ;
			}
		} 
	}
	return 0 ;
}