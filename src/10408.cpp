
#include<cstdio>
#include<algorithm>

using namespace std ;

class Farey
{
public :
	long int num ;
	long int den ;
	double v ;
	void calcv()
	{
		v = double(num) / double(den) ;
	}
	bool operator<( const Farey& obj) const
	{
		return ( v<obj.v) ;
	}
}seq[304000] ;


inline long gcd(long a,long b)
{
	return(a%b?gcd(b,a%b):b) ;
}

int main()
{
	long int len,k,n,i,j ;

	while(scanf("%ld%ld",&n,&k)==2)
	{
		len=0 ;
		for( i=n ; i>=2 ; i-- ){
			for( j=1 ; j<i ; j++ ){
				if(gcd(i,j)!=1) continue ;
				seq[len].den = i ;
				seq[len].num = j ;
				seq[len].calcv() ;
				len++ ;
			}
		}
		seq[len].den = seq[len].num = 1 ;
		seq[len].v = 1.0 ;

		if(len>=0)
			sort(seq,seq+len) ;

		printf("%ld/%ld\n",seq[k-1].num,seq[k-1].den) ;
	}
	return 0 ;
}

