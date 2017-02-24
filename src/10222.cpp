
#include<stdio.h>

const char str1[30] = "dmbgthjkpl;'.,[]eyfuonrvic" ;
const char str2[30] = "DMBGTHJKPL;'.,[]EYFUONRVIC" ;

int main()
{
	char c ;
	while(scanf("%c",&c)==1)
	{
		if(c==' ')
			printf(" ") ;
		else if(c=='\n')
			printf("\n") ;
		else{
			for(int i=0;i<26;i++)
			{
				if(str1[i]==c || str2[i]==c)
				{
					printf("%c",char(97+i)) ;
				}
			}
		}
		
	}
	return 0 ;
}