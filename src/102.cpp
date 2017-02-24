
#include<string.h>
#include<stdio.h>

int main(){
	long int b1=0,b2=0,b3=0,c1=0,c2=0,c3=0,g1=0,g2=0,g3=0 ;
	long int s;
	char t[5] ;
	while(scanf("%ld %ld %ld %ld %ld %ld %ld %ld %ld",&b1,&g1,&c1,&b2,&g2,&c2,&b3,&g3,&c3)==9){
		s = b2+b3+c1+c3+g1+g2 ;
		strcpy(t,"BCG") ;
		if(s>b2+b3+g1+g3+c1+c2){
			s=b2+b3+g1+g3+c1+c2 ;
			strcpy(t,"BGC")  ;
		}
		if(s>c2+c3+b1+b3+g1+g2){
			s=c2+c3+b1+b3+g1+g2 ;
			strcpy(t,"CBG") ;
		}
		if(s>c2+c3+g1+g3+b1+b2){
			s=c2+c3+g1+g3+b1+b2 ;
            strcpy(t,"CGB") ;
		}
		if(s>g2+g3+b1+b3+c1+c2){
			s=g2+g3+b1+b3+c1+c2 ;
			strcpy(t,"GBC") ;
		}
		if(s>g2+g3+c1+c3+b1+b2){
			s=g2+g3+c1+c3+b1+b2 ;
            strcpy(t,"GCB") ;
		}
		printf("%s %ld\n",t,s) ;
	}
	return 0 ;
}