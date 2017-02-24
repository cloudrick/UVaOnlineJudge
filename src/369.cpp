
#include<stdio.h>

int main()
{
	int n , m ;
	int i,j,k ;
    unsigned long t[102][102] ;

    while(scanf("%d %d",&n,&m)==2){  
		for(i=0 ; i<101 ;i++){
			for(j=0 ; j<101 ; j++)
				t[i][j] = 0 ;
		}
        if(n==0 && m==0)
                break ;
        for(k=1 ; k<=n ; k++ ){
			     t[k][0] = 1 ;
                for(i=k,j=1 ; i<=n ; i++,j++){	
                        if(i==j)
                                t[i][j] = 1 ;
                        else
                                t[i][j] = t[i-1][j-1] + t[i-1][j] ;
                        if(i==n && j==m){
                                printf("%d things taken %d at a time is %u exactly.\n",n,m,t[i][j]) ;
                                i = j = k = n+1 ;
                        }
                }
        }
	}
        return 0 ;
}
