
#include<cstdio>

int main()
{
	char str[10] ;
	int i ;
	double H,S,D ;

	while(scanf("%s",str)==1)
	{
		H=S=0.0 ;

		for(i=0 ; str[i]!= ':' ; i++)
			H = H*10 + str[i] -'0' ;
		for(i++ ; str[i] ; i++)
			S = S*10 + str[i] - '0' ;
		H = (H*5) + (5.0/60.0)*S ;

		if(H==0.0 && S==0.0) break ;

		D = H-S ;

		if(D<0) D+=60 ;
		if(D>=30) D = 60-D ;

		printf("%.3lf\n",D*6) ;

	}

	return 0 ;
}