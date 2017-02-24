
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>

using namespace std ;

class mmm
{
public :
	string name ;
	int n ;
	bool operator>(const mmm &p) const
	{ return (name > p.name ) ; } 
} ;

int len ;

int main()
{
	
    char tmp1[75],tmp2[75] ;
	string name ;
	int n,i,j ;
	bool flag ;

	mmm table[1001] ;

	scanf("%d\n",&n) ;

	len = 0 ;

	while(n--)
	{
		gets(tmp1) ;
		sscanf(tmp1,"%s",tmp2) ;

		name = string(tmp2) ;
		
		flag = false ;

		for( i=0 ; i<len ; i++)
		{
			if( table[i].name == name )
			{
				table[i].n++ ;
				flag = true ;
				break ;
			}
		}

		if(!flag)
		{
			table[len].name = name ;
			table[len].n = 1 ;
			len++ ;
		}
	}

	for( j=1 ; j<len ; j++)
	{
		mmm tmpmmm = table[j] ;
		i = j-1 ;
		while( i>=0 && table[i]>tmpmmm )
		{
			table[i+1] = table[i] ;
			i-- ;
		}
		table[i+1] = tmpmmm ;
	}
	

	for( i=0 ; i<len ; i++)
		cout << table[i].name << " " << table[i].n << endl ;

	return 0 ;
}