
#include<stdio.h>

int main()
{
	int n,m,map[110][110],stack[110],top ;
	int pocket ;
	char tmp[110] ;
	int i,j,k ;

	while(scanf("%d%d",&n,&m)==2){
		if(m==0)
			break ;
		pocket = 2 ;
		top = 0 ;
		for(i=0;i<110;i++){
			for(j=0;j<110;j++)
				map[i][j] = 0 ;
		}
		for(i=0;i<n;i++){
			scanf("%s",tmp) ;
			for(j=0;tmp[j];j++){
				if(tmp[j]=='@')
					map[i+1][j+1] = 1 ;
			}
		}
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				if(map[i][j]==1){
					if(map[i][j-1]){
						map[i][j] = map[i][j-1] ;
						continue ;
					}
					else if(map[i-1][j-1]){
						map[i][j] = map[i-1][j-1] ;
						continue ;
					}
					else if(map[i-1][j]){
						map[i][j] = map[i-1][j] ;
						continue ;
					}
					else if(map[i-1][j+1]){
						map[i][j] = map[i-1][j+1] ;
						continue ;
					}
					else
						map[i][j] = ++pocket ;
				}
			}
		}
	}
	return 0 ;
}
