
#include<iostream>
#include<cstdio>
#include<string>

using namespace std;

int main()
{

	bool f = false ;

	for(;;)
	{
		int p ;
		cin >> p ;

		if( p==0 ) 
			break;

		int win [101];
		int lose[101];

		for(int i=1 ; i <= p ; i++)
		{	
			win[i] = 0;
			lose[i] = 0;
		}
		
		int c ;
		cin >> c;

		c = c*p*(p-1)/2;

		while(c--)
		{
			string x,y;
			int a,b;

			cin >> a >> x >> b >> y ;

			if(x[0] == 'r' ) 
			{
				if( y[0]=='p' )
				{
					win[b]++ ; 
					lose[a]++;
				}
				else if( y[0]=='s')
				{
					win[a]++; 
					lose[b]++;
				}
			} 
			else if(x[0] == 'p'   ) 
			{
				if( y[0]=='r' )
				{
					win[a]++; 
					lose[b]++;
				}
				else if( y[0]=='s' )
				{
					win[b]++; 
					lose[a]++;
				}
			}
			else if(x[0] == 's' ) 
			{
				if( y[0]=='r')
				{
					win[b]++; 
					lose[a]++;
				}
				else if( y[0]=='p' )
				{
					win[a]++; 
					lose[b]++;
				}
			}				
		}

		if(f) 
			printf("\n");

		for(int j=1 ; j<=p ; j++)
		{
			lose[j] = win[j] + lose[j] ;
			if(lose[j] == 0) 
				cout << "-\n" ;
			else
				printf("%.3f\n",(float)win[j]/lose[j]) ;
		}

		f = true;

	}

	return 0;
}

