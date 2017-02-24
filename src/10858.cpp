
#include<iostream>
#include<string>

using namespace std ;

int olen ;
int onum ;

int output[21] ;

string output_str ;

char GetHexChar(int c)
{
	c %= 16 ;
	if( c<10 )
		return c + '0' ;
	else
		return c - 10 + 'A' ;
}

string IntToDecString(unsigned long int v)
{
	string r ;
	do
	{
		r = GetHexChar(v%10)+r ;
		v/=10 ;
	}while( v!=0 ) ;
	return r ;
}

void process(int n)
{
	if(n==1)
	{
		if( olen<2 )
			return ;
		onum++ ;
		for( int i=0 ; i<olen ; ++i)
		{
			if(i!=0)
				output_str += " " ;
			output_str += IntToDecString(output[i])  ;
		}
		output_str += "\n" ;
		return ;
	}
	for( int i=2 ; i<=n ; ++i)
	{
		if( n%i == 0 )
		{
			if(olen>0 && output[olen-1]>i )
			{
				continue ;
			}
			output[olen++] = i ;
			process(n/i) ;
			olen-- ;
		}
	}
}

int main()
{
	while(true)
	{
		int n ;
		cin >> n ;

		if( n==0 )
			break ;

		output_str = "" ;
		olen = onum = 0 ;
		process(n) ;
		cout << onum << endl ;
		cout << output_str ;
	}
	return 0 ;
}