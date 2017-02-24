
/* @JUDGE_ID: 7008MR 10161 C++ */

#include<stdio.h>
#include<math.h>

int main()
{
	unsigned long int n,m,x,y ;

	while(scanf("%u",&n)){
		if(n==0)
			break ;
		m = sqrt(n) ;
		n -= m*m ;
		if(n){
			if(m%2){
				y=m+1 ; x=0 ;
				for(; x<=m && n>0 ;n--)
					x++ ;
				for(; n>0 ;n--)
					y-- ;
			}
			else{
				x=m+1 ; y=0 ;
				for(; y<=m && n>0 ;n--)
					y++ ;
				for(; n>0 ;n--)
					x-- ;
			}
		}
		else{
			if(m%2){
				x = 1 ; y = m ; }
			else{
				x = m ; y = 1 ; }
		}
		printf("%u %u\n",x,y) ;
	}
	return 0 ;
}