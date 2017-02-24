
#include<cstdio>
#include<cmath>

int main()
{
	long int t,n,p[55],i,k,ball ;
	bool end ;

	scanf("%ld",&t) ;
	while(t--){
		scanf("%ld",&n) ;
		for(i=0;i<55;i++) p[i] = 0 ;
		p[0] = 1 ;
		end = true ;
		for(ball=2;end;ball++){
			for(i=0;i<=n;i++){
				if(i==n){
					end = false ;
					break ;
				}
				k=ball+p[i] ;
				if((sqrt(k)-long(sqrt(k))==0.0)||p[i]==0){
					p[i] = ball ;
					break ;
				}
			}
		}
		printf("%ld\n",ball-2) ;
	}
	return 0 ;
}