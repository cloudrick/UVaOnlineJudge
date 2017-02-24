
#include<stdio.h>

char str[1000010] ;
long int table[500010] ;

int main()
{	
	long int i,itmp,j,k,l ;
	int f,n,nn ;
	nn=1 ;
	while(scanf("%s",str)==1){
		printf("Case %d:\n",nn++) ;
		f = str[0] - '0' ;
		table[0] = -1 ;
		k=1 ;
		for(i=1;str[i];i++){
			if(str[i]-'0' != f){
				table[k++] = i-1 ;
				f = str[i]-'0' ;
			}
		}
		table[k++] = i-1 ;
		scanf("%d",&n) ;
		while(n--){
			scanf("%ld %ld",&i,&itmp) ;
			if(i>itmp){
				j=i ;
				i=itmp;
			}
			else
				j=itmp ;
			f=0 ;
			for(l=0;l<k-1;l++){
				if((table[l]<i && table[l+1]>=j)){
					f=1 ;
					break ;
				}
			}
			if(f||i==j)
				printf("Yes\n") ;
			else
				printf("No\n") ;
		}
	}
	return 0 ;
}

