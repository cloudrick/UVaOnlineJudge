
#include<cstdio>
#include<cmath>

unsigned mm ;

unsigned table[1000][2],len ;

inline unsigned FibonacciMod(unsigned n)
{
	if(n==0) return(0) ;
	if(n==1||n==2) return(1%mm) ;
	if(n==3) return(2%mm) ;

	unsigned p1,p2 ;

	for(int i=0;i<len;i++){
		if(table[i][0]==n){
			return(table[i][1]) ;
		}
	}

	if(n%2){
		p1 = FibonacciMod((n+1)/2)%mm ;
		p2 = FibonacciMod((n-1)/2)%mm ;
		if(len<999){
			table[len][0] = (n+1)/2 ; table[len++][1] = p1 ;
			table[len][0] = (n-1)/2 ; table[len++][1] = p2 ;
		}
		return( ((p1*p1)%mm) + ((p2*p2)%mm)) ;
	} 
	else{
		p1 = FibonacciMod((n/2)+1)%mm ;
		p2 = FibonacciMod((n/2)-1)%mm ;
		if(len<999){
			table[len][0] = (n/2)+1 ; table[len++][1] = p1 ;
			table[len][0] = (n/2)-1 ; table[len++][1] = p2 ;
		}
		return( ((p1*p1)%mm)-((p2*p2)%mm) ) ;
	}

}

int main()
{
	unsigned n ;
	int m ;
	while(scanf("%u%d",&n,&m)==2)
	{
		mm =(pow(2,m)) ;
		len=0 ;
		printf("%u\n",FibonacciMod(n)%mm) ;
	}

	return 0 ;
}