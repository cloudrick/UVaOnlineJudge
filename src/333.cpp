
#include<stdio.h>
#include<string.h>

int main()
{
	int i,k;
	char str[80] ;
	int sum[15] ;
	bool result ;

	while(gets(str))
	{
		k=0 ;

		for(i=0 ; i<(int)strlen(str) ; i++)
		{
			if(k==9){
				if(str[i]=='X' || str[i]=='x')
					sum[k++] = 10 ;
				else if(str[i]>='0' && str[i]<='9')
					sum[k++] = str[i]-'0' ;
			}
			else{
				if(str[i]>='0' && str[i]<='9'){
					if(k<10)
						sum[k] = str[i]-'0' ;
					k++ ;
				}
			}
		}

		if(k!=10)
			result = false ;
		else
		{
			for(i=1 ; i<=9 ; i++)
				sum[i] += sum[i-1] ;
			for(i=1 ; i<=9 ; i++)
				sum[i] += sum[i-1] ;
			if(sum[9]%11==0)
				result = true ;
			else
				result = false ;
		}

		printf("%s is ",str) ;
		if(result)
			printf("correct.\n") ;
		else
			printf("incorrect.\n") ;
	}
	return 0 ;
}