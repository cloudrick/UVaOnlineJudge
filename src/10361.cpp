
#include<stdio.h>

int main()
{
	int n,i,j,t[110],t1,t2,t3,t4;
	char str1[110],str2[110] ;
	scanf("%d\n",&n) ;
	while(n--){
		gets(str1) ;
		gets(str2) ;
		t1=0 ;
		for(i=0;str1[i]!='<';i++)
			printf("%c",str1[i]) ;
		for(i++;str1[i]!='>';i++)
			t[t1++] = int(str1[i]) ;
		for(t2=t1,i++;str1[i]!='<';i++)
			t[t2++] = int(str1[i]) ;
		for(t3=t2,i++;str1[i]!='>';i++)
			t[t3++] = int(str1[i]) ;
		for(t4=t3,i++;str1[i];i++)
			t[t4++] = int(str1[i]) ;
		for(i=0;i<t4;i++)
			printf("%c",char(t[i])) ;
		printf("\n") ;
		for(i=0;;i++){
			if(str2[i]=='.'){
				if(str2[i+1]=='.'){
					if(str2[i+2]=='.'){
						for(j=t2;j<t3;j++)
							printf("%c",char(t[j])) ;
						for(j=t1;j<t2;j++)
							printf("%c",char(t[j])) ;
						for(j=0;j<t1;j++)
							printf("%c",char(t[j])) ;
						for(j=t3;j<t4;j++)
							printf("%c",char(t[j])) ;
						printf("\n") ;
						break ;
					}
					printf(".") ;
				}
				printf(".") ;
			}
			printf("%c",str2[i]) ;
		}
	}
	return 0 ;
}