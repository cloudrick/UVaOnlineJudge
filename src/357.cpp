
#include<stdio.h>

int main()
{
	int table[100][5],i,n ;

	for(i=0;i<100;i++){
		table[i][0] = 1 ;
		table[i][1] = (i>=5) ? table[i-5][1] + table[i][0] : table[i][0] ;
		table[i][2] = (i>=10) ? table[i-10][2] + table[i][1] : table[i][1] ;
		table[i][3] = (i>=25) ? table[i-25][3] + table[i][2] : table[i][2] ;
		table[i][4] = (i>=50) ? table[i-50][4] + table[i][3] : table[i][3] ;
	}

	while(scanf("%d",&n)==1){
		if(table[n][4]==1)
			printf("There is only 1 way to produce %d cents change.\n",n) ;
		else
			printf("There are %d ways to produce %d cents change.\n",table[n][4],n) ;
	}
	return 0 ;
}

