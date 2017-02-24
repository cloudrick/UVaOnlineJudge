

#include<iostream>
#include<cstring>

using namespace std ;

int main()
{
	
	while(true)
	{
		char s[500] ;
		
		cin.getline(s,500) ;

		if( cin.eof() )
			break ;

		bool flag = false ;
		
		int n=0 ;
		
		for(int i=0 ; s[i] ; i++)
		{
			if((s[i] >= 'A' && s[i] <= 'z'))
				flag = true ;
			else if(flag)
			{
				n++ ;
				flag = false ;
			}
			if(i==strlen(s)-1 && flag )
				n++ ;
		}
		cout << n << endl ;
	}
	return 0 ;
}

