
#include<stdio.h>

int main()
{
	int n,num[1010],time ;
	int i,j ;

	while(scanf("%d",&n)==1){
		time=0 ;
		for(i=0;i<n;i++)
			scanf("%d",&num[i]) ;
		for(i=n-1;i>=0;i--){
			for(j=0;j<i;j++){
				if(num[j+1]<num[j]){
					num[j+1]^=num[j]^=num[j+1]^=num[j] ;
					time++ ;
				}
			}
		}
		printf("Minimum exchange operations : %d\n",time) ;
	}
	return 0 ;
}
