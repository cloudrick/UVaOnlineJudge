
/*   @JUDGE_ID: 7008MR   272   C++  */ 

#include<stdio.h>
#include<iostream.h>

int main()
{
	char in ;
	int i=1 ;

    while(scanf("%c",&in)!= EOF){
			if(in == '\"' && i==1){
				cout << "``" ;
				i = 2 ;
			}
			else if(in == '\"' && i==2){
				cout << "\'\'" ;
				i = 1 ;
			}
			else
				cout << in ;
	}
	return 0 ;
}