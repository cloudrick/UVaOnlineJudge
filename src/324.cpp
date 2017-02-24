
/*   @JUDGE_ID: 7008MR   324  C++ */ 

#include<stdio.h>

void produce(long int s[],int n){
	s[0] = 1 ;
	int i,j ;
	for(i=2 ; i<=n ; i++){
		for(j=0 ; s[j]>=0 ; j++)
			s[j] *= i ;
		for(j=0 ; s[j]>=0 ; j++){
			if(s[j]>=10 && s[j+1]<0){
				s[j+1] = s[j]/10 ;
				s[j] %= 10 ;
			}
			else if(s[j]>=10 && s[j+1]>=0){
				s[j+1] += s[j]/10 ;
				s[j] %= 10 ;
			}
		}
	}
}

void count(long int s[],int r[]){
	for(int i=0 ; s[i]>=0 ; i++)
		r[s[i]]++ ;
}

int main()
{
	long int s[800] ;
	int i , n , r[10] ;
	while(scanf("%d",&n)){
		if(n==0)
			break ;
		for(i=0 ; i<800 ; i++)
			s[i] = -1 ;
		for(i=0 ; i<10 ; i++)
			r[i] = 0 ;
		produce(s,n) ;
		count(s,r) ;
		printf("%d! --\n",n) ;
		printf("(0)%5d\t(1)%5d\t(2)%5d\t(3)%5d\t(4)%5d\n",r[0],r[1],r[2],r[3],r[4]) ;
		printf("(5)%5d\t(6)%5d\t(7)%5d\t(8)%5d\t(9)%5d\n",r[5],r[6],r[7],r[8],r[9]) ;
	}
	return 0 ;
}
