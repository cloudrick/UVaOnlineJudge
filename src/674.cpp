
#include<stdio.h>

int main()
{
	int table[7490][5],i,n ;

	for(i=0;i<7490;i++){
		table[i][0] = 1 ;
		table[i][1] = (i>=5)?table[i-5][1] + table[i][0] : table[i][0] ;
		table[i][2] = (i>=10)?table[i-10][2] + table[i][1] : table[i][1] ;
		table[i][3] = (i>=25)?table[i-25][3] + table[i][2] : table[i][2] ;
		table[i][4] = (i>=50)?table[i-50][4] + table[i][3] : table[i][3] ;
	}
	while(scanf("%d",&n)==1)
		printf("%d\n",table[n][4]) ;
	return 0 ;
}