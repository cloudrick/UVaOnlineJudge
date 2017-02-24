
#include<stdio.h>
#include<string.h>

char str[5000][30] ;
int t[30] ;
bool m[30] ;

void insert(int a,int b)
{
	bool start = false ;
	for(int i=25;i>=0;i--){
		if(t[i]==a && start==false)
			break ;
		if(t[i]==b){
			start=true ;
			continue ;
		}
		if(start){
			if(t[i]==a){
				t[i]=b ;
				t[i+1]=a ;
				m[i]=m[i+1]=true ;
				break ;
			}
			else{
				t[i+1] = t[i] ;
				m[i+1] = m[i] ;
			}
		}
	}
}

int main()
{
	int i,j,n ;
	for(i=0;i<26;i++){
		t[i]=i ;
		m[i]=false ;
	}
	scanf("%s",str[0]) ;
	n=1 ;
	while(scanf("%s",str[n++])==1){
		if(str[n-1][0] == '#')  break ;
		for(i=0;i<int(strlen(str[n-2]));i++){
			for(j=0;j<26;j++){
				if(t[j]==str[n-2][i]-'A')
					m[j] = true ;
			}
		}
		for(i=0;i<int(strlen(str[n-1]));i++){
			for(j=0;j<26;j++){
				if(t[j]==str[n-1][i]-'A')
					m[j] = true ;
			}
		}
		for(i=0;i<int(strlen(str[n-1])) && i<int(strlen(str[n-2]));i++){
			if(str[n-1][i] != str[n-2][i]){
				insert(str[n-1][i]-'A',str[n-2][i]-'A') ;
				break ;
			}
		}
	}
	for(j=n-3;j>=0;j--){
		for(i=0;i<int(strlen(str[j])) && i<int(strlen(str[j+1]));i++){
			if(str[j][i] != str[j+1][i]){
				insert(str[j+1][i]-'A',str[j][i]-'A') ;
				break ;
			}
		}
	}
	for(i=0;i<26;i++){
		if(m[i])
			printf("%c",t[i]+65) ;
	}
	return 0 ;
}