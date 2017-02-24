
/* @JUDGE_ID: 7008MR 10070 C++ */

#include<stdio.h>

int d(const int year[],int y){
	int t_year[20000],i,c ;
	for(i=0 ; i<20000 ; i++)
		t_year[i] = year[i] ;
	for(i=0,c=0 ; t_year[i]>=0 ; i++){
		c = (c*10) + t_year[i] ;
		c = c%y ;
	}
	if(c)
		return(1) ;
	else 
		return(0) ;
}

int main()
{
	char tmp[20000] ;
	int year[20000],i,f ;
	while(scanf("%s",tmp)==1){
		for(i=0 ; i<20000 ; i++){
			if(tmp[i]<='9' && tmp[i] >='0')
				year[i] = int(tmp[i])-48 ;
			else
				year[i] = -1 ;
		}
		f=0 ;
		if((d(year,4)==0 && d(year,100)==1) || d(year,400)==0){
			printf("This is leap year.\n") ; f=1 ; }
		if(d(year,15)==0){
			printf("This is huluculu festival year.\n") ; f=1 ; }
		if(((d(year,4)==0 && d(year,100)==1) || d(year,400)==0) && d(year,55)==0){
			printf("This is Bulukulu festival year.\n") ; f=1 ; }
		if(f==0)
			printf("This is an ordinary year.\n") ;
	}
	return 0 ;
}