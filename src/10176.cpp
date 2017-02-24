
#include<iostream>
#include<stack>

using namespace std ;

int main()
{
	while(true)
	{

		stack<char> s ;
		
		while(true)
		{
			char c ;
			cin.get(c) ;
			if( cin.eof() )
			{
				return 0 ;
			}
			if( c=='#')
				break ;
			else if( c=='0' || c=='1')
				s.push(c) ;
		}


		int m=0 ;
		int mm = 1 ;

		for( int i=0 ; !s.empty() ; i++)
		{
			char cc = s.top() ;
			s.pop() ;

			if( cc == '0' )
				continue ;

			if(i!=0)
				mm= (mm*2)%131071 ;

			m+=mm ;
			m%=131071 ; 
		}

		if( m==0 )
			cout << "YES" << endl ;
		else
			cout << "NO" << endl ;

	}

	return 0 ;
}
