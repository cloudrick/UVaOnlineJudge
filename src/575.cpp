
#include<stdio.h>
#include<math.h>
#include<string.h>

int main()
{
	unsigned long int sum,table[40] ;
	char input[40] ;
	int i;

	for(i=0;i<31;i++)
		table[i] = pow(2,i+1) - 1 ;

	while(scanf("%s",input)==1){
		if(strcmp(input,"0")==0)
			break ;
		sum = 0 ;
		for(i=int(strlen(input))-1 ;i>=0;i--)
			sum += table[int(strlen(input))-1-i] * (input[i]-'0') ;
		printf("%ld\n",sum) ;

	}
	return 0 ;
}