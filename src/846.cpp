
#include<cstdio>

double table[70000] ;

int main()
{
	long int i ;
	double x,y,d ;

	int nn ;

	for( i=0 ; i<70000 ; i++)
	{
		if(i%2)
			table[i] = table[i-1] + ((i+1)/2) ;
		else
			table[i] = (i/2)*((i/2)+1) ;
	}


	
	scanf("%d",&nn) ; 

	while(nn--)
	{
		scanf("%lf %lf",&x,&y) ;

		d = y-x ;

		if(d==0) { printf("0\n") ; continue ; }

		for(i=0 ; i<69999 ; i++)
		{
			if( d>table[i] && d<=table[i+1]){
				printf("%ld\n",i+1) ;
				break ;
			}
		}

	}

	return 0 ; 
}