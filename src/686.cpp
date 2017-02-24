
#include<cstdio>
#include<cmath>

bool table[32769] ;

int main()
{
	long int n,a,b,i,j,nn ;

	for(i=0 ; i<32769 ; i++) 
		table[i] = true ;

	for(i=2 ; i<32769 ; i++){
		if(table[i]){
			j=i+i ;
			while(j<=32768){
				table[j] = false ;
				j+=i ;
			}
		}
	}

	while(scanf("%ld",&n)==1)
	{
		if(!n) break ;
		if(n==4){
			printf("1\n") ;
			continue ;
		}
		nn = 0 ;
		a = 3 ;
		b= n-3 ;

		while(true){
			if(a>b)
				break ;
			if(table[a] && table[b])
				nn++ ;
			a++ ; b-- ;
		}
		
		printf("%ld\n",nn) ;

	}
	
	return 0 ;
}

