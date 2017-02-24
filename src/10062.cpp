
#include<stdio.h>
#include<string.h>

int main()
{
	int time[97],i,min,mi ;
	char str[1005] ;

	while(gets(str)){
		for(i=0;i<97;i++) time[i] = 0 ;
		for(i=0;i<int(strlen(str));i++)
			time[str[i]-32]++ ;
		while(true){
			min = 2000 ;
			for(i=96;i>=0;i--){
				if(time[i]<min && time[i]!=0){
					min = time[i] ;
					mi = i ;
				}
			}
			if(min==2000) break ;
			else{
				printf("%d %d\n",mi+32,time[mi]) ;
				time[mi] = 0 ;
			}
		}
		printf("\n") ;
	}

	return 0 ;
}