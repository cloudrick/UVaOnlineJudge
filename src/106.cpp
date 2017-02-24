
#include<cstdio>
#include<cmath>
	
bool num[1000010] ;

inline long int gcd(long int a,long int b)
{
	if(a<b) a^=b^=a^=b ;
	return(a%b ? gcd(b,a%b) : b) ;
}

int main()
{
	long int n,p,q,i,j,k,x,y,z ;

	while(scanf("%ld",&n)==1){
		for(i=1;i<=n ;i++) num[i]=false ;
		p=0 ;
		q=n ;
		for(i=long(sqrt(n))+1 ; i>1 ; i--){
			for(j=i-1 ; j>0 ; j--){
				x = (i*i) - (j*j) ;
				y = (i*j)<<1 ;
				z = (i*i) + (j*j) ;
				if(x<=n && y<=n && z<=n){
					for(k=1 ; x*k<=n && y*k<=n && z*k<=n ; k++){
						if(!num[k*x]){ q-- ; num[k*x] = true ; }
						if(!num[k*y]){ q-- ; num[k*y] = true ; }
						if(!num[k*z]){ q-- ; num[k*z] = true ; }
					}
					if( gcd(x,y)==1 && gcd(y,z)==1 && gcd(x,z)==1 )
						p++ ;
				}
			}
		}
		printf("%ld %ld\n",p,q) ;
	}

	return 0 ;
}

