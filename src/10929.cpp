
#include<iostream>
#include<string>

using namespace std;

int main()
{

	for(;;)
	{
		int t;
		string str; 

		cin >> str;

		if( str == "0" ) 
			break;

		t=0;

		for(int i=0 ; i<str.length() ; i++)
		{
			if(i%2)
			{
				  t -= (str[i]-'0');
			}	
			else
			{
				  t += (str[i]-'0');
			}
		}
		if( t%11 == 0 )  
			cout << str << " is a multiple of 11.\n" ;
		else 
			cout << str << " is not a multiple of 11.\n" ;

	}
	return 0;
}