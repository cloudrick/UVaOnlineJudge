
#include<cstdio>
#include<cmath>

const long int table[9] ={
			0,
			9,
			189,
			2889,
			38889,
			488889,
			5888889,
			68888889,
			788888889 } ;

int main()
{
	long int  n,m,ans,mod ;
	int i,d ;

	while( scanf("%ld",&n)==1 )
	{
		m = n ;
		for(i=0 ; i<8 ; i++){
			m -= table[i] ;
			if(i>=1)
				m+=table[i-1] ;
			if( n>table[i] && n<=table[i+1] ){
				d = i+1 ;	
				break ;
			}
		}
		if(d==1){
			printf("%ld\n",n) ;
			continue ;
		}

		ans = pow(10,d-1) + ((m-1)/d) ;

		mod = fmod(m,d) ;

		if( mod == 0 )
			printf("%ld\n",long(fmod(ans,10))) ;
		else{
			for(i=0 ; i<d-mod ;i++)
				ans = (ans/10) ;
			printf("%ld\n",long(fmod(ans,10))) ;
		}
	}
	return 0 ;
}