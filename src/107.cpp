
#include<stdio.h>
#include<math.h>

int main()
{
	double in1,in2,out1,out2,t,n ; 
	while(scanf("%lf%lf",&in1,&in2)==2){
		if(in1==0 && in2==0) break ;
		if(in1==1 && in2==1){ 
			printf("0 1\n") ;
			continue ;
		}
		for(n=2;;n++){
			t = log10(in2)/log10(n) ;
			if(in1==ceil(pow(1/(n+1),-t)) || in1==long(pow(1/(n+1),-t)) ||
				in1==floor(pow(1/(n+1),-t)))
				break ;		
		}
		if(t==1)
			out1 = n ;
		else
			out1 = (pow(n,t)-1) / (n-1)  ;
		out2 = in1*(1.0-pow(n/(n+1.0),t+1))*(n+1) ;
		printf("%.0lf %.0lf\n",out1,out2) ;
	}
	return 0 ;
}