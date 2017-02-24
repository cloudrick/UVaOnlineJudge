
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std ; 

int main()
{
	int N ;

	cin >> N ;

	for(int n=1 ; n<=N ; n++)
	{
		cout << "Case #" << n << ":" << endl ;

		string str ;
		cin >> str ;

		vector<int> height ;

		height.clear() ;

		int h = 1 ;
		int max = 1 , min = 1 ;
		int i ;

		for( i=0 ; i<str.length() ; i++)
		{
			if( str[i] == 'R' )
			{
				height.push_back(h++) ;
				if( h>max )
					max = h ;
			}
			else if( str[i] == 'F' )
			{
				height.push_back(--h) ;
				if( h<min)
					min = h ;
			}
			else
			{
				height.push_back(h) ;
			}
		}

		for( i=max ; i>=min ; i--)
		{
			if( find( height.begin(),height.end(), i) == height.end())
				continue ;
			cout << "| " ;
			for( int j=0 ; j<height.size() ; j++)
			{
				if( height[j] == i )
				{
					if( str[j] == 'R')
						cout << '/' ;
					else if( str[j] == 'F')
						cout << '\\' ;
					else
						cout << '_' ;
				}
				else
					cout << ' ' ;
			}
			cout << endl ;
		}

		cout << "+-" ;
		for( i=0 ; i<height.size() ; i++)
			cout << '-' ;
		cout << '-' << endl << endl ;

	}

	return 0 ;
}