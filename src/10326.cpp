
#include<cstdio>
#include<cmath>

void Print(double p,int n,int nn)
{
	if(p==0){
		if(n==0)
			printf(" + 0") ;
	}
	else{
		if(p>0){
			if(n!=nn)
				printf(" + ") ;
		}
		else
			printf(" - ") ;
		if(fabs(p)!=1)
			printf("%.0lf",fabs(p)) ;
		if(n==0 && fabs(p)==1)
			printf("%.0lf",fabs(p)) ;
		if(n>1)
			printf("x^%d",n) ;
		else if(n==1)
			printf("x") ;
	}
}

int main()
{
	double r,s1[55],s2[55] ;
	int n,i,j,ss ;

	while(scanf("%d",&n)==1)
	{
		ss = 0 ;
		if(n==0){ printf("0 = 0\n") ; continue ; }
		for(i=0 ; i<n ; i++){
			scanf("%lf",&r) ;
			if(ss==0){
				s1[0] = -r ;
				s1[1] = 1 ;
				ss = 2 ;
				continue ;
			}
			for(j=0 ; j<55 ; j++) s2[j] = 0 ;
			for(j=0 ; j<ss ; j++){
				s2[j] += s1[j]*(-r) ;
				s2[j+1] += s1[j] ;
			}
			for(j=0 ; j<55 ; j++)
				s1[j] = s2[j] ;
			ss++ ;
		}

		for(i=ss-1 ; i>=0 ; i--){
			Print(s1[i],i,ss-1) ;
		}
		printf(" = 0\n") ;
	}

	return 0 ;
}