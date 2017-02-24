
#include<stdio.h>

inline unsigned long solve(unsigned long n)
{
	if(n==1) return(3) ;
	unsigned long k=0 ;
	for(;n!=1;k++){
		if(n%2)
			n = (n*3) + 1 ;
		else
			n /=2 ;
	}
    return(k) ;
}

int main()
{
	unsigned long L,U,max,i,maxi ;
	while( scanf("%u%u",&L,&U)){
		if(U==0&&L==0) break ;
		if(L>U) L^=U^=L^=U ;
		max=0 ;
		for(i=L;i<=U;i++){
			if( solve(i) > max){
				max = solve(i) ;
				maxi=i ;
			}
		}
		printf("Between %u and %u, %u generates the longest sequence of %u values.\n",L,U,maxi,max) ;
	}
	return 0 ;
}
