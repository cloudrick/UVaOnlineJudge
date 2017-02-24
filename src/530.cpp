
#include<stdio.h>
#include<math.h>

double gcd(double a,double b)
{
	return(fmod(a,b)?gcd(b,fmod(a,b)) : b) ;
}

int main()
{
	double n,k,result,nn[100],g,t ;
	int i,j ;
	while(scanf("%lf%lf",&n,&k)==2)
	{
		if(!n && !k) 
			break ;
		if(k<(n/2)) 
			k=n-k ;
		for(i=0;n-i>k;i++)
			nn[i] = n-i ;

		for(i=2;n-i>=k;i++)
		{
			t=double(i) ;
			for(j=0;n-j>k && t!=1;j++)
			{
				g = gcd(nn[j],t) ;
				nn[j]/=g ;
				t/=g ;			
			}
		}

		result = 1 ;
		for(i=0;n-i>k;i++)
			result *= nn[i] ;
		printf("%.0lf\n",result) ;
	}

	return 0 ;
}
