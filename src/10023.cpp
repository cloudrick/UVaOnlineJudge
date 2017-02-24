
#include<stdio.h>
#include<string.h>

int main()
{
	double x[1010],y[1010] ;
	char tmp[1010] ;
	int n,i,j ;
	
	scanf("%d",&n) ;
	while(n--){
		scanf("%s",tmp) ;
		for(i=0;i<1010;i++){
			if(i<strlen(tmp))
				y[i] = tmp[i] - '0' ;
			else
				y[i] = 0 ;
		}

	}
	return 0 ;
}