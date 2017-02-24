
#include<stdio.h>
#include<string.h>

int ch(char c)
{
	if(c>='0' && c<='9')
		return(c-48) ;
	else
		return(c-55) ;
}

int main()
{
	char str1[15],str2[15],op[3] ;
	long int n1,n2,sum ;
	int n,i,nn[13] ;
	scanf("%d",&n) ;
	while(n--){
		scanf("%s %s %s",str1,op,str2) ;
		n1 = n2 = 0 ;
		for(i=0 ; i<int(strlen(str1));i++)
			n1 = n1*16 + ch(str1[i]) ;
		for(i=0 ; i<int(strlen(str2));i++)
			n2 = n2*16 + ch(str2[i]) ;
		if(op[0]=='+') sum = n1+n2 ;
		else sum = n1-n2 ;
		for(i=12;i>=0;i--){
			nn[i]=n1%2 ;
			n1/=2 ;
		}
		for(i=0;i<=12;i++)
			printf("%d",nn[i]) ;
		printf(" %c ",op[0]) ;
		for(i=12;i>=0;i--){
			nn[i]=n2%2 ;
			n2/=2 ;
		}
		for(i=0;i<=12;i++)
			printf("%d",nn[i]) ;
		printf(" = %d\n",sum) ;
	}
	return 0 ;
}