
#include<iostream>
#include<string>
#include<queue>

using namespace std ;

class Num
{
public :
	string n ;
	bool operator<(const Num &r) const
	{
		string a = n + r.n ;
		string b = r.n + n ;
		
		for( int i=0 ; i< a.size() ; ++i )
		{
			if( a[i] > b[i] )
				return false ;
			if( a[i] < b[i] )
				return true ; 
		}
		return true ;
	}
};

int main()
{
	for(;;)
	{
		int n ;
		cin >> n ;

		if( n==0)
			break ;

		priority_queue<Num> q ;
		
		while(n--)
		{
			Num tmp ;
			cin >> tmp.n ;
			q.push(tmp) ;
		}

		while( !q.empty() )
		{
			cout << q.top().n ;
			q.pop();
		}

		cout << endl ;
	}

	return 0 ;
}
