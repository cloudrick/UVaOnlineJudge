
/* @JUDGE_ID: 7008MR 10099 C++ */

#include<stdio.h>

int distance[105][105] ;
int connect[105] ;
int N,R,T ;

int MST(int s,int d)
{
	int i,j,ai,aj,max ;
	while(1){
		max = -1 ;
		for(i=1;i<=N;i++){
			for(j=1;j<=N;j++){
				if(max<0)
					max = distance[i][j] ;
				else{
					if(distance[i][j]>max){
						max = distance[i][j] ;
						ai = i ; aj = j ;
					}
				}
			}
		}
		distance[ai][aj] = distance[aj][ai] = 0 ;
		for(i=0;i<=N;i++){
			if(connect[i]==connect[ai] && i!=ai){
				connect[i] = connect[aj] ;
			}
		}
		connect[ai] = connect[aj] ;
		if(connect[s] == connect[d]){
			return(max) ;
			break ;
		}
	}		
}

int main()
{
	int C1,C2,P,S,D ;
	int i,j,k=1 ;
	int min,time ;
	while(scanf("%d%d",&N,&R)==2){
		if(N==0&&R==0)
			break ;
		for(i=0;i<105;i++){
			for(j=0;j<105;j++){
				distance[i][j] = distance[j][i] = 0 ;
				connect[i] = i ;
			}
		}
		for(i=0;i<R;i++){
			scanf("%d%d%d",&C1,&C2,&P) ;
			distance[C1][C2] = distance[C2][C1] = P ;
		}
		scanf("%d%d%d",&S,&D,&T) ;
		min = MST(S,D) ;
		time = T/(min-1) ;
		if(T%(min-1))
			time++;
		printf("Scenario #%d\n",k++) ;
		printf("Minimum Number of Trips = %d\n",time) ;
	}
	return 0 ;
}