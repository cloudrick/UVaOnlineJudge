
#include<cstdio>

int main()
{
	long int num[10010],n,key ;

	for(n=0 ; scanf( "%ld" , &key )==1 ; n++)
	{
		if(n==0) num[0] = key ;
		else{
			int j=n-1 ;
			while(j>=0 && num[j]>key){
				num[j+1] = num[j] ;
				j-- ;
			}
			num[j+1] = key ;
		}

		if(n%2==0){
			printf("%ld\n",num[(n/2)]) ;
		}
		else{
			printf("%ld\n",(num[(n/2)+1]+num[n/2])/2) ;
		}
	}

	return 0 ;
}