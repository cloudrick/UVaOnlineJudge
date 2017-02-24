
#include<stdio.h>

int main()
{
	long int step,mod,tmp,i ;
	int table[100010] ;
	bool f ;

	while(scanf("%ld%ld",&step,&mod)==2){
		for(i=0;i<100000;i++) table[i] = 0 ;
		table[0] = 1 ;
		tmp = 0 ;
		do{
			tmp = (tmp+step)%mod ;
			table[tmp] = 1 ;
		}while(tmp!=0) ;
		f = true ;
		for(i=0;i<mod;i++){
			if(table[i]==0){
				f = false ;
				break ;
			}
		}
		if(f)
			printf("%10d%10d     Good Choice\n",step,mod) ;
		else
			printf("%10d%10d     Bad Choice\n",step,mod) ;
	}
	return 0 ;
}