
/* @JUDGE_ID: 7008MR 10190 C++ */

#include<stdio.h>
#include<math.h>

int main()
{
	unsigned long a[50000],m ;
	int i,flag ;

	while(scanf("%u %u",&a[0],&m)==2){
		if(a[0]<=1 || m<=1){
			printf("Boring!\n") ;
			continue ;
		}
		flag = 1 ;
		for(i=1; a[i-1]!=1 ;i++){
			if(fmod(a[i-1],m)==0)
				a[i] = a[i-1]/m ;
			else{
				flag = 0 ;
				break ;
			}
		}
		if(flag){
			for(i=0 ; a[i]!=1 ; i++)
				printf("%u ",a[i]) ;
			printf("1\n") ;
		}
		else{
			printf("Boring!\n") ;
		}
	}
	return 0 ;
}