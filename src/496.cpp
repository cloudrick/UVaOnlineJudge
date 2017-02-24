
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>

using namespace std ;

const int MAX = 100 ;

class INTSet
{
protected :
	int num[MAX] ;
	int len ;
public :
	bool Equal( const INTSet) ;
	bool AllDiff( const INTSet) ;
	bool IsSubset( const INTSet) ;
	void Reset() ;
	void Sort() ;
	void Add( int n) ;
} ;

void INTSet::Add(int n)
{
	num[len++] = n ;
}

bool INTSet::AllDiff(const INTSet p) 
{
	for( int i=0 ; i<len ; i++)
	{
		for( int j=0 ; j<p.len ; j++)
		{
			if( num[i] == p.num[j])
				return false ;
		}
	}
	return true ;
}

bool INTSet::Equal(const INTSet p)
{

	if( len != p.len) return false ;
	bool flag ;
	for( int i=0 ; i<len ; i++)
	{
		flag = false ;
		for( int j=0 ; j<p.len ; j++)
		{
			if( num[i] == p.num[j])
			{
				flag = true ;
			}
		}
		if( flag == false)
			return false ;
	}
	return true ;
}

void INTSet::Reset()
{
	len = 0 ;
	for( int i=0 ; i<MAX ; i++) 
		num[i] = 0 ;
}


bool INTSet::IsSubset(const INTSet p) 
{
	bool flag ;

	for( int i=0 ; i<p.len ; i++)
	{
		flag = false ;
		for( int j=0 ; j<len ; j++)
		{
			if( num[j] == p.num[i])
			{
				flag = true ;
				break ;
			}
		}
		if(!flag)
			return false ;
	}
	return true ;
}

int main()
{
	char tmp[200] ;
	char *nn ;

	INTSet set1,set2 ;

	while(gets(tmp))
	{
		set1.Reset() ;
		set2.Reset() ;
		nn = strtok(tmp," \n") ;
		set1.Add( atoi(nn) ) ;
		while( nn = strtok(NULL , " \n") ) 
			set1.Add( atoi(nn) ) ;

		gets(tmp) ;
		nn = strtok(tmp," \n") ;
		set2.Add( atoi(nn) ) ;
		while( nn = strtok(NULL , " \n") ) 
			set2.Add( atoi(nn) ) ;

		if( set1.Equal(set2) )
			printf("A equals B\n") ;
		else if( set1.AllDiff(set2) )
			printf("A and B are disjoint\n") ;
		else if( set1.IsSubset(set2) )
			printf("B is a proper subset of A\n") ;
		else if( set2.IsSubset(set1) ) 
			printf("A is a proper subset of B\n") ;
		else
			printf("I'm confused!\n") ;

	}

	return 0 ;
}