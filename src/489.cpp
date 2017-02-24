
#include<stdio.h>
#include<string.h>

bool AllOne(int a[],int l)
{
	for(int i=0;i<l;i++){
		if(a[i]!=1)
			return false ;
	}
	return true ;
}

int NotOne(int a[],int l)
{
	int n=0 ;
	for(int i=0;i<l;i++){
		if(a[i]!=1)
			n++ ;
	}
	return(n) ;
}

int main()
{
	char s[100],g[100] ;
	int n,ss[100],gg[100],m[27] ;
	int i,j ;

	while(scanf("%d",&n)==1){
		if(n==-1) break ;
		for(i=0;i<100;i++) ss[i]=gg[i]=0 ;
		for(i=0;i<27;i++) m[i] = 0 ;
		printf("Round %d\n",n) ;
		scanf("%s%s",s,g) ;
		for(i=0;i<int(strlen(g));i++){
			if(m[g[i]-'a']) continue ;
			for(j=0;j<int(strlen(s));j++){
				if(g[i]==s[j])
					gg[i]=ss[j]=1 ;
			}
			m[g[i]-'a'] = 1 ;
		}
		if(NotOne(gg,int(strlen(g)))<7){
			if(AllOne(ss,int(strlen(g))))
				printf("You win.\n") ;
			else
				printf("You chickened out.\n") ;
		}
		else
			printf("You lose.\n") ;
	}

	return 0 ;
}