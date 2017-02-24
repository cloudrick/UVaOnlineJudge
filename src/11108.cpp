
#include <iostream>
#include <string>

using namespace std ;

enum OP
{
	OP_NONE,OP_K,OP_A,OP_N,OP_C,OP_E,
} ;

int p,q,r,s,t ;
int np,nq,nr,ns,nt ;
string str ;
int index ;

bool check ( OP op )
{
	index++ ;
	
	if( op == OP_NONE )
	{
		if( str[index] == 'K' )
			return check( OP_K ) ;
		else if( str[index] == 'A' )
			return check( OP_A ) ;
		else if( str[index] == 'N' )
			return check( OP_N ) ;
		else if( str[index] == 'C' )
			return check( OP_C ) ;
		else if( str[index] == 'E' )
			return check( OP_E ) ;
		else if( str[index] == 'p' )
			return np ;
		else if( str[index] == 'q' )
			return nq ;
		else if( str[index] == 'r' )
			return nr ;
		else if( str[index] == 's' )
			return ns ;
		else if( str[index] == 't' )
			return nt ;
	}
	else
	{
		index-- ;	
	}
	
	if( op == OP_K )
	{
		bool var1 = check(OP_NONE) ;
		bool var2 = check(OP_NONE) ;
		return ( var1 && var2 ) ;
	}
	else if( op == OP_A )
	{
		bool var1 = check(OP_NONE) ;
		bool var2 = check(OP_NONE) ;
		return ( var1 || var2 ) ;
	}
	else if( op == OP_N )
	{
		bool var1 = check(OP_NONE) ;
		return ( !var1 ) ;
	}
	else if( op == OP_C )
	{
		bool var1 = check(OP_NONE) ;
		bool var2 = check(OP_NONE) ;
		return ( !(var1 && !var2) ) ;
	}
	else if( op == OP_E )
	{
		bool var1 = check(OP_NONE) ;
		bool var2 = check(OP_NONE) ;
		return ( (var1 && var2) || (!var1 && !var2) ) ;
	}
	return true ;	
}

int count_variable()
{

	p=q=r=s=t=0 ;
	
	for( int i=0 ; i<str.length() ; ++i)
	{
		if( str[i] == 'p' )	
			p=1 ;
		else if( str[i] == 'q' )
			q=1 ;
		else if( str[i] == 'r' )	
			r=1 ;
		else if( str[i] == 's' )	
			s=1 ;
		else if( str[i] == 't' )	
			t=1 ;
	}
	
	return p+q+r+s+t ;
}



int main()
{
	for(;;)
	{
		int  num_of_variable ;
		
		cin >> str ;
		
		if( str == "0" )
			break ;
			
		num_of_variable = count_variable() ;
		
		int tmp_i = 1 ;
			
		if( p==1 )
			p = tmp_i++ ;
		if( q==1 )
			q = tmp_i++ ;
		if( r==1 )
			r = tmp_i++ ;
		if( s==1 )
			s = tmp_i++ ;
		if( t==1 )
			t = tmp_i++ ;	
			
		bool result = true ;
		
		for( int i=0 ; i< ( 1 << (num_of_variable) ) ; ++i)
		{	
			if( p>0 )
				np = (i>>(p-1))&1 ;
			if( q>0 )
				nq = (i>>(q-1))&1 ;
			if( r>0 )
				nr = (i>>(r-1))&1 ;
			if( s>0 )
				ns = (i>>(s-1))&1 ;
			if( t>0 )
				nt = (i>>(t-1))&1 ;
			
			index = -1 ;
			
			if( !check( OP_NONE ) )
			{
				result = false ;
				break ;	
			}
		}
		
		if( result )
			cout << "tautology" << endl ;
		else
			cout << "not" << endl ;
	}

//	system("pause") ;
	return 0 ;	
}
