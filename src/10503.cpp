
#include<cstdio>

int n,m ;
int i1,i2,d1,d2 ;
int pq[14][2] ;
bool pq_used[14] ;

bool solved ;

void DFS(const int depth,const int key)
{
	if( depth==n)
	{
		if( key==d1 )
			solved = true ;
		return ;
	}

	for(int i=0 ; i<m ; i++)
	{
		if( pq[i][0]==key && pq_used[i]==false)
		{
			pq_used[i] = true  ;
			DFS(depth+1,pq[i][1]) ;
			pq_used[i] = false ;
		}
		if( pq[i][1]==key && pq_used[i]==false)
		{
			pq_used[i] = true ;
			DFS(depth+1,pq[i][0]) ;
			pq_used[i] = false ;
		}
	}
}

int main()
{

	int i ;

	while( scanf("%d",&n) ==1 )
	{
		if( n==0 )
			break ;
		scanf("%d",&m) ;

		scanf("%d%d%d%d",&i1,&i2,&d1,&d2) ;

		for( i=0 ; i<m ; i++)
			scanf("%d%d",&pq[i][0],&pq[i][1]) ;
		for( i=0 ; i<14 ; i++) 
			pq_used[i] = false ;

		solved = false ;

		DFS(0,i2) ;

		if( solved )
			printf("YES\n") ;
		else
			printf("NO\n") ;

	}


	return 0 ;
}