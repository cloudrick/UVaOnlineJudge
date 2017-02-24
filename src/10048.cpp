
#include<cstdio>

int map[101][101] ;
int value[101] ;
int C,S,Q,c1,c2,d ;

struct qq
{
	int c1 ;
	int c2 ;
	int output ;
}q[10001] ;

void make(int a,int b)
{
	int v1 = value[a] , v2 =value[b];
	for(int i=1 ; i<=C ; i++){
		if(value[i]==v1)
			value[i] = v2 ;
	}
}

void doing()
{
	int i,j,mini,minj,min ;
	while(true)
	{
		min = -1 ;
		mini = -1 ;
		minj = -1 ;
		for(i=1 ; i<=C ; i++){
			for(j=1;j<=C;j++){
				if((map[i][j]<min && map[i][j]>0) || 
					(map[i][j]>0 && min==-1)){
					mini = i ; 
					minj = j ;
					min = map[i][j] ;
				}
			}
		}
		if(min == -1 ) break ;
		make(mini,minj) ;
		map[mini][minj] = map[minj][mini] = -1 ;
		for(i=0 ; i<Q ; i++){
			if(value[q[i].c1]==value[q[i].c2] && q[i].output==-1)
			   q[i].output = min ;
		}
	}
}

int main()
{
	
	int i,j,n ;

	n = 1 ;
	while(scanf("%d%d%d",&C,&S,&Q)==3)
	{
		if(!C && !S && !Q) break ;
		printf("Case #%d\n",n++) ;
		for(i=0 ; i<101 ; i++ ){
			for(j=0 ; j<101; j++)
				map[i][j] = -1 ;
		}

		for(i=0 ; i<S ; i++){
			scanf("%d%d%d",&c1,&c2,&d) ;
			map[c1][c2] = map[c2][c1] = d ;
			map[c1][c1] = map[c2][c2] = 0 ;
		}

		for(i=0 ; i<Q ; i++){
			scanf("%d%d",&q[i].c1,&q[i].c2) ;
			q[i].output = -1 ;

		}

		for(i=0 ; i<=C ; i++)
			value[i] = i ;

		doing() ;

		for(i=0 ; i<Q ; i++){
			if(q[i].output==-1)
				printf("no path\n") ;
			else
				printf("%d\n",q[i].output) ;
		}

		printf("\n") ;

	}

	return 0 ;
}