
#include<iostream>

using namespace std ;

int main()
{
	for(int n=1;;++n)
	{
		int N ;
		cin >> N ;

		if( cin.eof())
			break ;

		int *A = new int[N] ;

		for(int i=0;i<N;++i)
		{
			cin >> A[i] ;
		}

		long long int max_p = 0 ;

		for(int i=0 ; i<N ; ++i)
		{
			for(int j=i ; j<N ; ++j)
			{
				long long int p=1 ;
				for(int k=i ; k<=j ; ++k)
					p *= A[k] ;
				if( p>max_p)
					max_p = p ;
			}

		}
		
		delete [] A ;

		cout << "Case #" << n << ": The maximum product is " << max_p << "." ;
		cout << endl << endl ;

	}
	return 0 ;
}
