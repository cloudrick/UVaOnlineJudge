
#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
	char str[90],winer[90];

	for(int c=1 ; ; ++c )
	{
		cin.getline(str,90);

		int p,n ;
		sscanf(str,"%d %d",&p,&n) ;
	
		if(p==0 && n==0) break;

		int max = 0 ;
		double min = 100000000 ;

		while(p--)
		{	
			cin.getline(str,90);		
		}

		while(n--)
		{		
			cin.getline(str,90);
	
			char tmp[90] ;
			cin.getline(tmp,90);

			double d ;
			int r ;

			sscanf(tmp,"%lf %d",&d,&r) ;

			if(r > max)
			{
				max = r;
				min = d ;
				strcpy(winer,str);
			}
			else if(r == max)
			{
				if( d < min )
				{
					strcpy(winer,str);
					min = d ;
				}
			}

			while(r--) 
			{
				cin.getline(str,90);	
			}
		}

		cout << "RFP #" << c << endl << winer << endl << endl ;		
	}
	return 0;
}