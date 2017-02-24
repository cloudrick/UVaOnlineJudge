
#include<iostream>
#include<list>

using namespace std ;

int main()
{

	while(true)
	{
		int n ;	
		cin >> n ;

		if( n==0 )
			break ;

		list<int> seq ;
	
		for( int i=0 ; i<n ; ++i)
		{
			int tmp ;
			cin >> tmp ;
			seq.push_back(tmp) ;
		}

		int s = 1 ;
		int diff = 0 ;

		while( !seq.empty() )
		{
			int max = -9999999999  ;
			int tmp = 0 ;

			list<int>::iterator head = seq.begin() ;
			list<int>::iterator end ;

			for( list<int>::iterator i=seq.begin() ; i!=seq.end() ; ++i)
			{
				tmp += (*i) ;

				if(tmp >= max  )
				{
					max = tmp ;
					end = i ;
					end++ ;
				}
			}

			for( list<int>::iterator j=seq.begin() ; j != seq.end() ; ++j)
			{
				tmp -= (*j) ;

				if(tmp >= max && (++j)-- != seq.end())
				{
					max = tmp ;
					end = seq.end() ;
					head = j ;
					head++ ;
				}
			}

			diff += s*max ;
			s *= -1 ;
			seq.erase(head,end) ;

		}

		cout << (diff<0 ? -diff:diff) << endl ;

	}

	return 0 ;
}