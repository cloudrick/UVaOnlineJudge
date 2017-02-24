
#include<cstdio>
#include<cmath>

bool table[1000001] ;

int main()
{
	long int n,a,b,i,j ;

	for(i=0 ; i<=1000000 ; i++) table[i] = true ;
	for(i=2 ; i<=1000000 ; i++){
		if(table[i]){
			j=i+i ;
			while(j<=1000000){
				table[j] = false ;
				j+=i ;
			}
		}
	}

	while(scanf("%ld",&n)==1)
	{
		if(!n) break ;

		a = 3 ;
		b= n-3 ;
		bool found = false ;

		while(!table[a] || !table[b]){
			if(a>b)
			{
				printf("Goldbach's conjecture is wrong.\n") ;
				found = true ;
				break ;
			}
			a++ ; 
			b-- ;
		}

		if(!found)
			printf("%ld = %ld + %ld\n",n,a,b) ;

	}
	
	return 0 ;
}

