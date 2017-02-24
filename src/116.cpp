
/* @JUDGE_ID:7008MR 116 C++ */

#include<stdio.h>

struct temp
{
	int w ;
	int tw ;
	int p ;
}table[100][100] ;
int m,n ;

int main()
{
	long int i,j,l[101],nn,mm,k,s ;
	while(scanf("%d%d",&m,&n)==2){
		for(i=0;i<m;i++){
			for(j=0;j<n;j++)
				scanf("%d",&table[i][j].w) ;
		}
		for(j=0;j<n;j++){
			for(i=0;i<m;i++){
				if(j==0){
					table[i][j].tw = table[i][j].w ;
					table[i][j].p = -1 ;
					continue ;
				}
				table[i][j].tw = -1 ;
				if(i==0){
					if(table[m-1][j-1].tw>0){
						table[i][j].tw = table[m-1][j-1].tw ;
						table[i][j].p = m-1 ;
					}
				}
				else{
					if(table[i-1][j-1].tw>0){
						table[i][j].tw = table[i-1][j-1].tw ;
						table[i][j].p = i-1 ;
					}
				}

				if(i==m-1){
					if((table[i][j].tw>table[0][j-1].tw &&table[0][j-1].tw>0)||
						table[i][j].tw<0&&table[0][j-1].tw>0){
						table[i][j].tw = table[0][j-1].tw ;
						table[i][j].p = 0 ;
					}
				}
				else{
					if((table[i][j].tw>table[i+1][j-1].tw&&table[i+1][j-1].tw>0)||
						table[i][j].tw<0&&table[i+1][j-1].tw>0){
						table[i][j].tw = table[i+1][j-1].tw ;
						table[i][j].p = i+1 ;
					}
				}
				if((table[i][j].tw>table[i][j-1].tw&&table[i][j-1].tw>0)||
					table[i][j].tw<0&&table[i][j-1].tw>0){
					table[i][j].tw = table[i][j-1].tw ;
					table[i][j].p = i ;
				}
				if(table[i][j].tw>0)
					table[i][j].tw += table[i][j].w ;
			}
		}
		s=table[0][n-1].tw ;
		mm=0 ;
		for(nn=1;nn<m;nn++){
			if(table[nn][n-1].tw<s&&table[nn][n-1].tw>0){
				s = table[nn][n-1].tw ;
				mm = nn ;
			}
		}
		for(nn=n-1,k=0;nn>0;nn--,k++){
			l[k] = mm ;
			mm = table[mm][nn].p ;
		}
		printf("1 ") ;
		for(k=n-2 ; k>=0 ; k--)
			printf("%d ",l[k]+1) ;
		printf("\n%d\n",table[m-1][n-1].tw) ;
	}
	return 0 ;
}