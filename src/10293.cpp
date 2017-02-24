
#include<stdio.h>

int main()
{
	int map[32],i,tmp ;
	char c ;
	bool flag ;
	for(i=0;i<32;i++) map[i]=0 ;
	tmp = 0 ; flag=true ;
	while(scanf("%c",&c)==1){
		if(c=='#'){
			for(i=1;i<=30;i++){
				if(map[i])
					printf("%d %d\n",i,map[i]) ;
			}
			printf("\n") ;
			for(i=0;i<32;i++) map[i]=0 ;
		}
		else{
			if((c==' '|| c=='.'||c=='?'||c=='!'||c=='\n')&&flag){
				map[tmp]++ ;
				tmp = 0 ;
				flag=true ;
			}
			else{
				if((c>='A'&&c<='Z')||(c>='a'&&c<='z'))
					tmp++ ;
				if(c=='-') flag=false ;
				else	flag=true ;
			}
		}
	}
	return 0 ;
}