
#include<stdio.h>

int main()
{
	int s[10],i ;
	bool printed ;
	while(scanf("%d%d%d%d%d%d%d%d%d",&s[8],&s[7],&s[6],&s[5],&s[4],&s[3],&s[2],&s[1],&s[0])==9){
		printed = false ;
		if(!(s[8])&&!(s[7])&&!(s[6])&&!(s[5])&&!(s[4])&&!(s[3])&&!(s[2])&&!(s[1])&&!(s[0])){
			printf("0\n") ;
			continue ;
		}
		for(i=8;i>=0;i--){
			if(s[i]==0)
				continue ;
			else{
				if(s[i]<0){
					if(printed)
						printf(" - ") ;
					else
						printf("-") ;
				}
				if(s[i]>0 && printed)
					printf(" + ") ;
				if((s[i]!=1&&s[i]!=-1) || i==0)
					printf("%d",s[i]>0?s[i]:-s[i]) ;
				if(i>=1)
					printf("x") ;
				if(i>1)
					printf("^%d",i) ;
				printed = true ;
			}
		}
		printf("\n") ;
	}
	return 0 ;
}