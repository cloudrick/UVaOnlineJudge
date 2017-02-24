
#include<stdio.h>
#include<string.h>

int main()
{
	char str[110][110] ;
	int i,j,n,maxlen ;

	n=0 ;
	maxlen=0 ;
	while(gets(str[n])){
		if(int(strlen(str[n]))>maxlen)
			maxlen = strlen(str[n]) ;
		n++ ;
	}

	for(i=0;i<maxlen;i++){
		for(j=n-1;j>=0;j--){
			if(str[j][i]) printf("%c",str[j][i]) ;
			else printf(" ") ;
		}
		printf("\n") ;
	}
	return 0 ;
}