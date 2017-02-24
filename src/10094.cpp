
#include<stdio.h>

int main()
{
	int n,i,table[1002] ;

	while(scanf("%d",&n)==1){
		if(n<4){
			printf("Impossible\n") ;
			continue ;
		}
		if(n==8){
			printf("4 6 8 2 7 1 3 5\n") ;
			continue ;
		}
		if(n%6==0 || (n+2)%6==0){
			for(i=1 ; i<=(n/2) ; i++){
				table[2*i] = i ;
				table[2*i-1] = (n/2) + i ;
			}
		}
		if((n+1)%6==0 || (n-1)%6==0){
			for(i=1;i<=(n-1)/2;i++)
				table[2*i] = i ;
			for(i=1;i<=(n+1)/2;i++)
				table[(2*i)-1] = ((n-1)/2) + i ;
		}
		if((n-3)%6==0){
			table[1] = n-1 ;
			table[2] = (n-1)/2 ;
			table[3] = n ;
			for(i=1;i<=(n-3)/2;i++){
				table[(2*i)+2] = i ;
				table[(2*i)+3] = ((n-1)/2)+i ;
			}
		}

		if((n-8)%6==0){
			for(i=1;i<=3;i++)
				table[(2*i)-1] = (n/2) -2+i ;
			table[2] = n ;
			table[4] = 1 ;
			table[6] = n-1 ;
			for(i=1;i<=(n/2)-3 ;i++){
				table[2*i+5] = i+1 ;
				table[2*i+6] = (n/2) +1+i ;
			}
		}

		for(i=1;i<=n;i++)
			printf("%d ",table[i]) ;
		printf("\n") ;
	}

	return 0 ;
}
