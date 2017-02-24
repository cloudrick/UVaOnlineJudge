
#include<cstdio>

int main()
{
	int n1,n2,max,n ;
	int t1[101],t2[101] ;
	int i,j ;
	int table[101][101] ;
	n=1 ;
	while(scanf("%d%d",&n1,&n2)==2)
	{
		if(n1==0 && n1==0) break ;
		printf("Twin Towers #%d\n",n++) ;

		for(i=0 ; i<n1 ; i++) scanf("%d",&t1[i]) ;
		for(j=0 ; j<n2 ; j++) scanf("%d",&t2[j]) ;

		for(i=0 ; i<101 ; i++) table[i][0] = 0 ;
		for(j=0 ; j<101 ; j++) table[0][j] = 0 ;

		max = 0 ;

		for(i=0 ; i<n1 ; i++){
			for(j=0 ; j<n2 ; j++){
				if( t1[i] == t2[j] )
					table[i+1][j+1] = table[i][j]+1 ;
				else if( table[i][j+1] >= table[i+1][j])
					table[i+1][j+1] = table[i][j+1] ;
				else
					table[i+1][j+1] = table[i+1][j] ;

				if(table[i+1][j+1]>max)
					max = table[i+1][j+1] ;
			}
		}

		printf("Number of Tiles : %d\n",max) ;
	}

	return 0 ;
}