
#include<stdio.h>
#include<string.h>

int main()
{
	long int n,slen,flag,ff ;
	char str[100] ;

	scanf("%d",&n) ;
	while(n--){
		scanf("%s",str) ;
		if(int(strlen(str))==1){
			printf("1\n") ;
			continue ;
		}
		ff=0 ;
		for(slen=1 ; slen<=int(strlen(str))/2 ;slen++){
			if(int(strlen(str))%slen) continue ;
			flag = true ;
			for(int i=0;i<int(strlen(str))-slen;i++){
				if(str[i] != str[i+slen])
					flag = false ;
			}
			if(flag){ 
				ff=1 ;
				break ;
			}
		}
		if(ff)
			printf("%ld\n",slen) ;
		else
			printf("%d\n",int(strlen(str))) ;
	}
	return 0 ;
}