
#include<cstdio>
#include<cstring>

struct T
{
	char str[20] ;
	long int V ;
}D[1001] ;

int main()
{
	int m,n,i ;
	char tmp[20] ;
	double sum ;

	scanf("%d%d",&m,&n) ;

	for(i=0 ; i<m ; i++)
		scanf("%s %ld",D[i].str,&D[i].V) ;
	sum = 0 ;
	while(scanf("%s",tmp)==1){
		if(tmp[0]=='.' && strlen(tmp)==1) {
			printf("%.0lf\n",sum) ;
			sum = 0 ;
			continue ;
		}

		for(i=0 ; i<m ; i++){
			if(strcmp(tmp,D[i].str)==0)
				sum += D[i].V ;
		}
	}
	return 0 ;
}