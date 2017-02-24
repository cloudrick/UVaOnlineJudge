
#include<iostream>
#include<string>

using namespace std ;

int main()
{
	int nn=1 ;
	for(;;)
	{
		int N,F ;

		cin >> N >> F ;

		if( N==0 && F==0)
			break ;

		int Num[25] ;
		int i ;
		bool flag ;

		for( i=0 ; i<25 ; ++i)
			Num[i] = 0 ;

		for( i=0 ; i<N ; ++i)
		{
			string line ;
			cin >> line ;
			
			for( int j=line.size()-1 ; j>=0 ; --j)
			{
				Num[line.size()-j-1] += line[j]-'0' ;
			}
		}

		for( i=0 ; i<23 ; ++i)
		{
			if( Num[i] > 9 )
			{
				Num[i+1] += Num[i]/10 ;
				Num[i] %= 10 ;
			}
		}

		cout << "Bill #" << nn++ << " costs " ;
		flag = false ;
		for( i=24 ; i>=0 ; --i)
		{
			if( flag || Num[i]!=0)
			{
				cout << Num[i] ;
				flag = true ;
			}
		}
		if( !flag)
			cout << '0' ;
		cout << ": each friend should pay " ;

		int num=0 ;
		flag = false ;

		for( i=24 ; i>=0 ; --i)
		{
			num*=10 ;
			num += Num[i] ;

			if( num/F != 0 || flag)
			{
				cout << num/F ;
				num%=F ;
				flag = true ;
			}
		}
		if( !flag)
			cout << '0' ;
		cout << endl << endl ;
	}

	return 0 ;
}