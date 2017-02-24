
#include<iostream>
#include<cstring>

using namespace std ;

int main()
{

	int N ;

	cin >> N ;

	while(N--)
	{
		char line[81] ;
		char output[81] ;
		int i,j ;

		memset(output,'\0',81) ;

		cin >> line ;

		int len = strlen(line) ;

		int exp = 1 ;

		for(i=0 ; i<8 ; ++i)
		{
			cin >> line ;
			for(j=1 ; j<len-1;j++)
			{			
				if(line[j]=='\\')
					output[j-1] |= exp ;
			}
			exp *= 2 ;
		}

		cin >> line ;
		cout << output << endl ;
	}

	return 0 ;
}