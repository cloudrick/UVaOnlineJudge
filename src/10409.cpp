
#include<stdio.h>

int main()
{
	int e,w,s,n,b,t,tmp ;
	int nn ;
	char m[10] ;

	while(scanf("%d",&nn)==1){
		if(nn==0) break ;
		n=2;w=3;s=5;e=4;b=6;t=1;
		while(nn--){
			scanf("%s",m) ;
			if(m[0]=='e'){
				tmp=t;t=w;w=b;b=e;e=tmp;
			}
			if(m[0]=='w'){
				tmp=t;t=e;e=b;b=w;w=tmp;
			}
			if(m[0]=='n'){
				tmp=t;t=s;s=b;b=n;n=tmp;
			}
			if(m[0]=='s'){
				tmp=t;t=n;n=b;b=s;s=tmp;
			}
		}
		printf("%d\n",t) ;
	}

	return 0 ;
}