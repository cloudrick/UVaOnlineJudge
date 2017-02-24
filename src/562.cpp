
#include<iostream>
#include<algorithm>
#include<stdio.h>

using namespace std ;

int main()
{
	unsigned long int n,m,num[101],s1,s2 ;
	int i ;

	scanf("%u",&n) ;
	while(n--){
		scanf("%u",&m) ;
		for(i=0;i<m;i++)
			scanf("%u",&num[i]) ;
		sort(num,num+m) ;
		s1=s2=0 ;
		for(i=m-1;i>=0;i--){
			if(s1>s2)
				s2+=num[i] ;
			else
				s1+=num[i] ;
		}
		printf("%u\n",(s1-s2)>0 ? s1-s2 : s2-s1) ;
	}
	return 0 ;
}