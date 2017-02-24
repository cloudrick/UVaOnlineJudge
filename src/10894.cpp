
#include<cstdio>
#include<iostream>

using namespace std ;

char str[10][5][6] =

{

	// 0 S
	{
		"*****" , "*...." , "*****" , "....*" , "*****"
	} ,

	// 1 A
	{
		".***." , "*...*" , "*****" , "*...*" , "*...*"
	} ,

	// 2 V
	{
		"*...*" , "*...*" , "*...*" , ".*.*." , "..*.."
	} ,

	// 3 E
	{
		"*****" , "*...." , "***.." , "*...." , "*****"
	} ,

	// 4 H
	{
		"*...*" , "*...*" , "*****" , "*...*" , "*...*"
	} ,

	// 5 R
	{
		"*****" , "*...*" , "*****" , "*.*.." , "*..**"
	} ,

	// 6 I
	{
		"*****" , "..*.." , "..*.." , "..*.." , "*****"
	} ,

	// 7 D
	{
		"***.." , "*..*." , "*...*" , "*..*." , "***.."
	} ,

	// 8 O
	{
		"*****" , "*...*" , "*...*" , "*...*" , "*****"
	} ,

	// 9 Y
	{
		"*...*" , ".*.*." , "..*.." , "..*.." , "..*.."
	} 
} ;


int main()
{

	int n ;

	for( scanf("%d",&n) ; n!=0 ; scanf("%d",&n) )
	{
		if( n>0 )
		{
			for(int i=0 ; i<5 ; ++i)
			{
				for( int j=0 ; j<n ; ++j)
				{
					int k ;

					for( k=0 ; k<4 ; ++k)
					{
						for( int a=0 ; a<5 ; ++a)
						{
							for( int b=0 ; b<n ; ++b)
							{
								cout << str[k][i][a] ;
							}
						}

						if(k==3) 
							break ;

						for( int b=0 ; b<n ; ++b)
						{
							cout << "." ;
						}
					}

					for( k=0 ; k<3*n ; ++k)
					{
						cout << '.' ;
					}

					for( k=4 ; k<10 ; ++k)
					{

						for( int a=0 ; a<5 ; ++a)
						{
							for( int b=0 ; b<n ; ++b)
							{
								cout << str[k][i][a] ;
							}
						}

						if( k==9 )
							break ;

						for( int b=0 ; b<n ; ++b)
						{
							cout << "." ;
						}
					}
					cout << endl ;
				}
			}
			cout << endl << endl ;
		}
		else
		{
			n = -n ;

			int i ;

			for( i=0 ; i<4 ; ++i)
			{
				int l ;
				for( l=0 ; l<5 ; ++l)
				{
					for( int j=0 ; j<n ; ++j)
					{
						for( int k=0 ; k<5 ; ++k)
						{
							for( int a=0 ; a<n ; ++a)
							{
								cout << str[i][l][k] ;
							}
						}
						cout << endl ;
					}

				}
				
				if( i==3 )
					break ;

				for( l=0 ; l<n ; ++l)
				{
					for( int j=0 ; j<5*n ; ++j)
						cout << '.' ;
					cout << endl ;
				}

			}

			for( i=0 ; i<3*n ; ++i)
			{
				for( int j=0 ; j<5*n ; ++j)
					cout << '.' ;
				cout << endl ;
			}

			for( i=4 ; i<10 ; ++i)
			{
				int l ;
				for( l=0 ; l<5 ; ++l)
				{
					for( int j=0 ; j<n ; ++j)
					{
						for( int k=0 ; k<5 ; ++k)
						{
							for( int a=0 ; a<n ; ++a)
							{
								cout << str[i][l][k] ;
							}
						}
						cout << endl ;
					}

				}
				
				if( i==9 )
					break ;

				for( l=0 ; l<n ; ++l)
				{
					for( int j=0 ; j<5*n ; ++j)
						cout << '.' ;
					cout << endl ;
				}

			}

			cout << endl << endl ;
		}
	}

	return 0 ;
}