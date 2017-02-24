
#include<cstdio>
#include<cmath>

long int rev(long int n)
{
	long int m=0 ;

	while(n){
		m=(m*10)+(n%10) ;
		n/=10 ;
	}
	return m ;
}

int main()
{
	long int n,m,i ;
	bool fn,fm ;
	
	while(scanf("%ld",&n)==1)
	{
		m = rev(n) ;
		fn = fm = true ;
		if((n%2==0&&n!=2)||(n%3==0&&n!=3)) fn = false ;
		if((m%2==0&&m!=2)||(m%3==0&&m!=3)) fm = false ;
		for(i=3;(i<=sqrt(n)+5)||(i<=sqrt(m)+5);i+=2){
			if(n%i==0 && n>i && n>3) fn=false ;
			if(m%i==0 && m>i && m>3) fm=false ;
		}
		if(m<10 && n>=10) printf("%ld is not prime.\n",n) ;
		else if(!fn) printf("%ld is not prime.\n",n) ;
		else if(fn&&!fm) printf("%ld is prime.\n",n) ;
		else{
			if(n==m) printf("%ld is prime.\n",n) ;
			else printf("%ld is emirp.\n",n) ;
		}
	}
	return 0 ;
}