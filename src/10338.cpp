
#include<stdio.h>
#include<string.h>

const double f[25]= {1.0,1.0,2.0,6.0,24.0,120.0,720.0,5040.0,40320.0,362880.0,3628800.0,39916800.0,479001600.0,6227020800.0,87178291200.0,1307674368000.0,20922789888000.0,355687428096000.0,6402373705728000.0,121645100408832000.0,2432902008176640000.0} ;

int main()
{
	unsigned int n,j ;
	char str[25] ;
	int table[27],i ;
	double p ;
	scanf("%u",&n) ;
	for(j=0;j<n;j++){
		scanf("%s",str) ;
		for(i=0;i<27;i++) table[i] = 0 ;
		for(i=0;i<strlen(str);i++) table[str[i]-'A']++ ;
		p = f[strlen(str)] ;
		for(i=0;i<27;i++) p /= f[table[i]] ;
		printf("Data set %u: %.0lf\n",j+1,p) ;
	}
	return 0 ;
}