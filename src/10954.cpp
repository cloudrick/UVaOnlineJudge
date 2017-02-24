
#include<iostream>
#include<queue>

using namespace std ;

int main()
{
	for(;;)
	{
		int n ;
		cin >> n ;

		if( n==0 )
			break ;

		priority_queue<int> q ;

		for(int nn=0 ; nn<n ; ++nn)
		{
			int t ;
			cin >> t ;
			q.push(-t) ;
		}

		int cost = 0 ;

		while( q.size() > 1)
		{
			int a = -q.top() ;
			q.pop() ;
			int b = -q.top() ;
			q.pop() ;
			cost += a+b ;
			if(q.size() != 0 )
				q.push(-a-b) ;
		}

		if( q.size() == 1 )
			cost += -q.top() ;

		cout << cost << endl ;
	}


	return 0 ;
}
