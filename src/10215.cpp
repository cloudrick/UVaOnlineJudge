
#include<cstdio>
#include<cmath>

int main()
{
	double L,W,x1,x2,V1,V2 ;

	while(scanf("%lf%lf",&L,&W)==2)
	{
		x1 = ((4*(W+L))+sqrt(pow(4*(W+L),2.0)-(48*W*L)))/24 ;
		x2 = ((4*(W+L))-sqrt(pow(4*(W+L),2.0)-(48*W*L)))/24 ;
		V1 = x1*(L-x1-x1)*(W-x1-x1) ;
		V2 = x2*(L-x2-x2)*(W-x2-x2) ;

		if(V1>V2) printf("%.3lf ",x1) ;
		else printf("%.3lf ",x2) ;
		
		printf("0.000 ") ;

		if(L>W) printf("%.3lf\n",W/2) ;
		else printf("%.3lf\n",L/2) ;
	}

	return 0 ;
}