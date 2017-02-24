
#include<iostream>
#include<string>

using namespace std ;

int div2(int num[20])
{
	int r = num[0]%2 ;

	for( int i=19 ; i>=0 ; i--)
	{
		if( i>0)
		{
			num[i-1] += (num[i]%2)*10 ;
		}
		num[i] /= 2 ;
	}
	return r ;
}

void calc2( int map[70] , string str )
{
	int num[20] ;
	for( int i=0 ; i<20 ; i++)
	{
		int ii = str.length()-1-i ;
		
		if( ii<0 )
		{
			num[i] = 0 ;
		}
		else
		{
			num[i] = str[ii] - '0' ;
		}
	}
	num[0] -= 1 ;
	for( int k=0 ; k<19 ; k++)
	{
		if( num[k]<0 )
		{
			num[k] += 10 ;
			num[k+1] -= 1 ;
		}
	}
	for(int j=0 ; j<70 ; j++)
	{
		map[j] = div2(num) ;
	}
}

void calc1(  int cur[50], const int ori[50])
{
	for( int i=0 ; i<50 ; i++)
	{
		cur[i] = ori[i]*3 ;
	}
	for( int j=0 ; j<49 ; j++)
	{
		if( cur[j] >= 10 )
		{
			cur[j+1] += cur[j]/10 ;
			cur[j] %= 10 ;
		}
	}
}

int main()
{
	int PowerOfThree[70][50] ;

	for( int mi=0 ; mi<70 ; mi++)
	{
		for( int mj=0 ; mj<50 ; mj++)
		{
			PowerOfThree[mi][mj] = 0 ;
		}
	}

	PowerOfThree[0][0] = 1 ;

	for( int mk=1 ; mk<70 ; mk++)
	{
		calc1( PowerOfThree[mk],PowerOfThree[mk-1]) ;
	}

	while( true )
	{
		string input ;
		cin >> input ;

		if( input == "0" )
			break ;
		if( input == "1")
		{
			cout << "{ }" << endl ;
			continue ;
		}

		int MappingSet[70] ;
		calc2(MappingSet,input) ;

		cout << "{ " ;

		bool flag1 = false ;

		for( int i=0 ; i<70 ; i++)
		{
			if( MappingSet[i] != 0 )
			{
				if(flag1)
					cout << ", " ;
				bool flag2 = false ;
				for(int j=49 ; j>=0 ; j--)
				{
					if( flag2 || PowerOfThree[i][j]!=0)
					{
						cout << PowerOfThree[i][j] ;
						flag2 = true ;
					}
				}
				flag1 = true ;
			}
		}

		cout << " }" << endl ;

	}


	return 0 ;
}