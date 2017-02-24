
#include<cstdio>
#include<cstring>

int main()
{
	char *str1,*str2,*tok ;
	int n ;

	n=1 ;
	while(gets(str1))
	{
		gets(str2) ;
		printf("%2d. ",n++) ;
		if(strlen(str1)==0 || strlen(str2)==0){
			printf("Blank!\n",) ;
			continue ;
		}

	}

	return 0 ;
}