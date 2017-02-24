
#include<stdio.h>
#include<math.h>

int main()
{
	long int i,j,k,n,c,min ;
	scanf("%ld",&n) ;

	while(n--){
		scanf("%ld",&c) ;
		min=4*c+2 ;
		for(i=1;i<=sqrt(c);i++){
			for(j=1;j<=sqrt(c);j++){
				if(c%(i*j))
					continue ;
				else
					k = c/(i*j) ;
				if( (2*i*j)+(2*i*k)+(2*k*j)<min )
					min= (2*i*j)+(2*i*k)+(2*k*j) ;
			}
		}
		printf("%ld\n",min) ;
	}
	return 0 ;
}