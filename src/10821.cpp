
#include<iostream>

using namespace std ;


void make_tree(int s,int e,int h)
{
	for( int r=s ; r<=e ; ++r)
	{
		if( e-r<= (1<<(h-1))-1 )
		{
			cout << ' ' << r ;
			make_tree(s,r-1,h-1) ;
			make_tree(r+1,e,h-1) ;
			break ;
		}
	}
}

int main()
{
	int i=1 ;
	while(true)
	{
		unsigned int N,H ;

		cin >> N >> H ;

		if( N==0 && H==0 )
			break ;


		cout << "Case " << i++ << ":" ;

		if( N>((1<<H))-1 )
		{
			cout << " Impossible." << endl ;
		}
		else
		{
			make_tree(1,N,H) ;
			cout << endl ;
		}
	}
	return 0 ;
}