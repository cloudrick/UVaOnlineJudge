
/* @JUDGE_ID: 7008MR 623 C++ */

#include<stdio.h>

int main()
{
	int s[1500],n,i,j,m ;

	while(scanf("%d",&n)==1){
		if(n==1 || n==0){
			printf("%d!\n1\n",n) ;
			continue ;
		}
		for(i=0 ; i<1500 ; i++)
			s[i] = -1 ;
		s[0] = 1 ;
		m=0 ;
		for(i=2 ; i<=n ; i++){
			for(j=0 ; s[j]>=0 ; j++)
				s[j] *= i ;
			for(j=0 ; s[j]>=0 ; j++){
				if(s[j]>9){
					if(s[j+1]<0){
						s[j+2] = -1 ;
						s[j+1] = s[j]/10 ;
						s[j] %= 10 ;
						m=j+2 ;
					}
					else{
						s[j+1] +=  s[j]/10 ;
						s[j] %= 10 ;
					}
				}
			}
			m = j ;
		}
		printf("%d!\n",n) ;
		for(m--;m>=0;m--)
			printf("%d",s[m]) ;
		printf("\n") ;
	}

	return 0 ;
}