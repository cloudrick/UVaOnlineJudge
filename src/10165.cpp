
#include<stdio.h>

int main()
{
	unsigned long int n,p,r ;

    while(scanf("%u",&n)==1){
		if(n==0) break ;
		r=0 ;
        while(n--){                  
			scanf("%u",&p) ;
			r^=p ;
		}
        if(r==0)
			printf("No\n") ;
		else
            printf("Yes\n") ;
	}
    return 0 ;
}
