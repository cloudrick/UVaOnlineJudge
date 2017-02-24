
#include<cstdio>
#include<cstring>

int calc(int s)
{
	while(s>=10)
	{
		int tmp1 = s , tmp2 = 0 ;
		while(tmp1>0)
		{
			tmp2 += tmp1%10 ;
			tmp1 /= 10 ;
		}
		s = tmp2 ;
	}
	return(s) ;
}

int main()
{
	char str1[27],str2[27] ;
	int sum1,sum2 ;
	int i ;

	while(gets(str1))
	{
		gets(str2) ;
		sum1 = sum2 = 0 ;

		for(i=0 ; i<int(strlen(str1)) ; i++){
			if(str1[i]>='A' && str1[i]<='Z')
				sum1 += str1[i] - 'A' + 1 ;
			if(str1[i]>='a' && str1[i]<='z')
				sum1 += str1[i] - 'a' + 1 ;
		}

		for(i=0 ; i<int(strlen(str2)) ; i++){
			if(str2[i]>='A' && str2[i]<='Z')
				sum2 += str2[i] - 'A' + 1 ;
			if(str2[i]>='a' && str2[i]<='z')
				sum2 += str2[i] - 'a' + 1 ;
		}

		sum1 = calc(sum1) ;
		sum2 = calc(sum2) ;

		if(sum1>sum2)
			sum1 ^= sum2 ^= sum1 ^= sum2 ;

		if(sum1==sum2)
			printf("100.00 %%\n") ;
		else
			printf("%.2f %%\n",(float)sum1*100/sum2) ;
	}

	return 0 ;
}