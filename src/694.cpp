
#include<cstdio>
#include<cmath>

long int sum(double A,double L)
{
	long int k=0 ;
	while(true)
	{
		if(A>L) break ;
		if(A==1){k++ ; break ;}
		k++ ;
		if(fmod(A,2.0)==0)
			A/=2.0 ;
		else
			A = A*3 +1 ;
	}
	return k ;
}

int main()
{
	double A,L ;
	int n ;

	for(n=1;;n++)
	{
		scanf("%lf%lf",&A,&L) ;
		if(L<0 || A<0) break ;
		printf("Case %d: A = %.0lf, limit = %.0lf, ",n,A,L) ;
		printf("number of terms = %ld\n",sum(A,L)) ;
	}
	return 0 ;
}