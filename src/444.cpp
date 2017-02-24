
#include<stdio.h>
#include<string.h>

int main()
{
	char str[2000] ;
	int i,j,k,t[2000] ;

	while(gets(str)){
		if(str[0]>='0' && str[0]<='9'){
			k=0 ;
			for(i=int(strlen(str))-1 ; i>=0 ; i--){
				k = (k*10) + (str[i]-'0') ;
				if(k>=32){
					printf("%c",k) ;
					k=0 ;
				}
			}
			printf("\n") ;
		}
		else{
			for(i=0 ; i<int(strlen(str)) ; i++)
				t[i] = str[i] ;
			for(j=i-1 ; j>=0 ; j--){
				printf("%d",t[j]%10) ;
				printf("%d",(t[j]/10)%10) ;
				if(t[j]>=100)
					printf("%d",t[j]/100) ;
			}
			printf("\n") ;
		}
	}
	return 0 ;
}