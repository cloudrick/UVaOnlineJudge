
/*   @JUDGE_ID: 7008MR  136  C++  */ 

#include<stdio.h>

int partition(__int64 s[],int p,int r){
	int i,j ;
	__int64 t,x ;
	x = s[p] ;
	i = p-1 ;
	j = r+1 ;
	while(1){
		while(s[j]>x)
			j-- ;
		while(s[i]<x) 
			i++ ;
		if(i<j){
			t = s[i] ;
			s[i] = s[j] ;
			s[j] = t ;
		}
		else
			return(j) ;
	}
}

void quicksort(__int64 s[],int p,int r){
	int q ;
	if(p<r){
		q = partition(s,p,r) ;
		quicksort(s,p,q) ;
		quicksort(s,q+1,r) ;
	}
}

__int64 getmax(__int64 s[]){
	__int64 m=1 ;
	for(int i=0 ; i<=1499 ; i++){
		if(s[i]>m)
			m=s[i] ;
	}
	return(m) ;
}

int main(){
	__int64 s[4001],max=10000000000000000 ;
	int t[4001] ;
	int h,l=1 ;
	s[0] = 1 ;
	t[0] = 1 ;

	for(h=0 ; h!=l ; h++){
		if(l==1500)
			max=getmax(s) ;
		if(t[h]!=3 && t[h]!=5 && s[h]*2 < max){
			s[l] =s[h] * 2 ;
			t[l] = 2 ;
			l++ ;
		}
		if(t[h]!=5 && s[h]*3 < max){
			s[l] = s[h] * 3 ;
			t[l] = 3 ;
			l++ ;
		}
		if( s[h]*5 < max){
			s[l] = s[h] * 5 ;
		    t[l] = 5 ;
		    l++ ;
		}
	}
	quicksort(s,1,h-1) ;
	printf("The 1500'th ugly number is %I64d.\n",s[1500]) ;
	return 0 ;
}