
#include<iostream>
#include<string>

using namespace std ;

int main()
{
	for( ;; )
	{
		string line ;
		cin >> line ;

		if( line == "0" )
			break ;

		int sum = 0 ;
		int degree = 1 ;

		for( int i=0 ; i<line.size() ; ++i)
		{
			sum += line[i] - '0' ;
		}

		while( sum > 9 )
		{
			int tmp=0 ;

			while( sum!=0 )
			{
				tmp += sum%10 ;
				sum/=10 ;
			}

			sum = tmp ;
			degree++ ;
		}

		if(sum==9)
		{
			cout << line << " is a multiple of 9 and has 9-degree " << degree << "." << endl ;
		}
		else
		{
			cout << line << " is not a multiple of 9." << endl ;
		}
	}

	return 0 ;
}