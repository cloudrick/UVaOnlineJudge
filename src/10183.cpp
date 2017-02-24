
#include<cstdio>
#include<cstring>

int cmp(int a[],int b[])
{
	for(int i=199;i>=0;i--){
		if(a[i]==b[i]) continue ;
		if(a[i]>b[i]) return(1) ;
		if(a[i]<b[i]) return(-1) ;
	}
	return(0) ;
}

int main()
{
	char num1[200],num2[200] ;
	int n1[200],n2[200],total,i ;
	int f1[200],f2[200],tmp[200] ;

	while(  scanf( "%s%s",num1,num2) == 2 )
	{
		if(strcmp(num1,"0")==0 && strcmp(num2,"0")==0 )
			break ;
		
		for(i=0 ; i<200 ; i++) n1[i] = n2[i] = f1[i] = f2[i] = tmp[i] = 0 ;

		for(i=0;i<int(strlen(num1));i++)
			n1[i] = num1[strlen(num1)-i-1] - '0' ;
		for(i=0;i<int(strlen(num2));i++)
			n2[i] = num2[strlen(num2)-i-1] - '0' ;

		total = 0 ;
		f2[0] = 1 ;

		while(true){
			for(i=0;i<200;i++)
				tmp[i]=f1[i]+f2[i] ;
			for(i=0;i<199;i++){
				if(tmp[i]>9){
					tmp[i+1] += tmp[i]/10 ;
					tmp[i] %= 10 ;
				}
			}
			if(cmp(n2,tmp)<0) break ;
			if(cmp(tmp,n1)>=0 && cmp(tmp,n2)<=0) total++ ;

			for(i=0;i<200;i++){
				f1[i] = f2[i] ;
				f2[i] = tmp[i] ;
			}

		}

		printf("%d\n",total) ;
	}
	return 0 ;
}