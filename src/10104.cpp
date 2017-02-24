
#include<cstdio>

void Extended_Euclid(long int a,long int b,long int &d,long int &x,long int &y)
{
	long int xx=x,yy=y,dd=d ;
	if(b==0){
		d=a ;
		x=1 ;
		y=0 ;
	}
	else{
		Extended_Euclid(b,a%b,dd,xx,yy) ;
		d = dd ;
		x = yy ;
		y = xx - ((a/b)*yy) ;
	}
}

int main()
{
	long int A,B,X,Y,D ;

	while(scanf("%ld%ld",&A,&B)==2)
	{
		X=Y=D=0 ;

		if(A<B)
			Extended_Euclid(B,A,D,Y,X) ;
		else
			Extended_Euclid(A,B,D,X,Y) ;
		
		printf("%ld %ld %ld\n",X,Y,D) ;
	}

	return 0 ;
}