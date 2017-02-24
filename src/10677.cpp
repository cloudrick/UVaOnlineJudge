
#include<iostream>

using namespace std ;

int main()
{
	int n ; 

	cin >> n ;

	while(n--)
	{
		int B1,B2,r1,r2 ;

		cin >> B1 >> B2 >> r1 >> r2 ;

		bool solved = false ;

		for( int i=r2-1 ; i>r1 ; i--)
		{
			int digit[4] ;
			int total = i ;

			digit[0] = total%B1 ;
			total /= B1 ;
			digit[1] = total%B1 ;
			total /= B1 ;
			digit[2] = total%B1 ;
			total /= B1 ;
			digit[3] = total%B1 ;

			total = digit[3]*B2*B2*B2 ;
			total+= digit[2]*B2*B2 ;
			total+= digit[1]*B2 ;
			total+= digit[0] ;

			if( total%i==0 )
			{
				cout << i << endl ;
				solved = true ;
				break ;
			}
		}

		if( !solved )
		{
			cout << "Non-existent." << endl ;
		}
	}

	return 0 ;
}