
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std ;

class M
{
public :
	int d ;
	int n ;
	int v ;
	M(int dd,int nn,int vv):d(dd),n(nn),v(vv){} ;
} ;

int main()
{
	while(true)
	{
		int C,S,E,T ;
		int i,j ;

		cin >> C >> S >> E >> T ;

		if( C==0 && S==0 && E==0 && T==0 )
			break ;

		int map[101][101] ;

		for(i=1 ; i<=C ; i++)
		{
			for(j=1 ; j<=C ; j++)
			{
				cin >> map[i][j] ;
				map[i][j] ;
			}
		}

		vector<int> Es ;

		for(i=0;i<E;i++)
		{
			int tmp ;
			cin >> tmp ;
			Es.push_back(tmp) ;
		}

		queue<M> q ;
		q.push(M(0,S,0)) ;

		int max = 0 ;

		while(!q.empty())
		{
			M tmp = q.front() ;
			q.pop() ;
			if(tmp.d>T)
				break ;
			if(tmp.d==T)
			{
				if( find(Es.begin(),Es.end(),tmp.n) != Es.end() )
				{
					if(tmp.v>max)
						max = tmp.v ;
				}
			}

			for( i=1 ; i<=C ; i++)
			{
				if( tmp.n == i)
					continue ;
				if(tmp.d+1<=T)
					q.push(M(tmp.d+1,i,tmp.v+map[tmp.n][i])) ;
			}
		}

		cout << max << endl ;

	}

	return 0 ;
}