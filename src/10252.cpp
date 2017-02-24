
#include<stdio.h>
#include<string.h>

int main()
{
	int a[27],b[27],c[27],i,j ;
	char str[1010] ;

	while(gets(str)){
		for(i=0;i<27;i++) a[i]=b[i]=c[i]=0 ;
		for(i=0;i<int(strlen(str));i++)
			a[str[i]-'a']++ ;
		gets(str) ;
		for(i=0;i<int(strlen(str));i++)
			b[str[i]-'a']++ ;
		for(i=0;i<27;i++){
			int m= (a[i]<b[i])?a[i]:b[i] ;
			for(j=0;j<m;j++)
				printf("%c",97+i) ;
		}
		printf("\n") ;
	}
	return 0 ;
}