
#include<stdio.h>

int b1(int m)
{
	int sum=0 ;
	while(m>0){
		if(m%2) sum++ ;
		m/=2 ;
	}
	return(sum) ;
}

int b2(int m)
{
	int sum=0,p ;
	while(m>0){
		p=m%10 ;
		while(p>0){
			if(p%2) sum++ ;
			p/=2 ;
		}
		m/=10 ;
	}
	return(sum) ;
}

int main()
{
	int n,m ;
	scanf("%d",&n) ;
	while(n--){
		scanf("%d",&m) ;
		printf("%d %d\n",b1(m),b2(m)) ;
	}
	return 0 ;
}