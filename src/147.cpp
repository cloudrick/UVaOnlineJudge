
#include<stdio.h>

int main()
{
	long int table[5010][10] ;
	float n ;
	for(int i=0;i<=5000;i++){
		if(i%5){
			table[i][9] = 0 ;
			continue ;
		}
		table[i][0] = 1 ;
		table[i][1] = (i>=10) ? table[i-10][1] + table[i][0] : table[i][0] ;
		table[i][2] = (i>=20) ? table[i-20][2] + table[i][1] : table[i][1] ;
		table[i][3] = (i>=50) ? table[i-50][3] + table[i][2] : table[i][2] ;
		table[i][4] = (i>=100) ? table[i-100][4] + table[i][3] : table[i][3];
		table[i][5] = (i>=200) ? table[i-200][5] + table[i][4] : table[i][4] ;
		table[i][6] = (i>=500) ? table[i-500][6] + table[i][5] : table[i][5] ;
		table[i][7] = (i>=1000) ? table[i-1000][7] + table[i][6] : table[i][6] ;
		table[i][8] = (i>=2000) ? table[i-2000][8] + table[i][7] : table[i][7] ;
		table[i][9] = (i>=5000) ? table[i-5000][9] + table[i][8] : table[i][8] ;
	}
	while(scanf("%f",&n)==1){
		if(n==0.0) break ;
		printf("%5.2f%12ld\n",n,table[int(n*100.0)][9]) ;
	}
	return 0 ;
}
