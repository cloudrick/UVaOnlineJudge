
#include<iostream>
#include<fstream>

using namespace std ;

void DFS(int remain_letters , int weight , int max_element , int &way)
{
	if( remain_letters==0 )
	{
		if( weight == 0 )
			way++ ;
		return ;
	}

	for( int i=max_element+1 ; i<=26 ; ++i)
	{	
		if( weight > (i+26)*(27-i)/2 )
			break ;
		DFS(remain_letters-1,weight-i,i,way) ;
	}
}

int main()
{
	for(int c=1 ;; ++c)
	{
		int L,S ;
		cin >> L >> S ;

		if( L==0 && S==0)
			break ;

		if( S>351 || L>26 || S<(1+L)*L/2 || S>(53-L)*L/2 )
		{
			cout << "Case " << c << ": 0" << endl ;
			continue ;
		}

		int way = 0 ;

		DFS(L,S,0,way) ;

		cout << "Case " << c << ": " << way << endl ;
	}

	return 0 ;
}