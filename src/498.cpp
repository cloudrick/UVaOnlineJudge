
/* @JUDGE_ID: 7008MR 498 C++ */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int main()
{
	char tmp[256],*t ;
	long int num[64],x ;
	double sum ;
	int i,j ;

	while(gets(tmp)){
		t = strtok(tmp," ") ;
		for(i=0 ; t ; i++){
			num[i] = atol(t) ;
			t = strtok(NULL," ") ;
		}
		gets(tmp) ;
		t = strtok(tmp," ") ;
		i-- ;
		while(t){
			x = atol(t) ;
			for(j=0,sum=0; j<=i ; j++)
				sum += double(num[j]) * pow(double(x),double(i-j)) ;
			printf("%.0lf ",sum) ;
			t = strtok(NULL," ") ;
		}
		printf("\n") ;
	}

	return 0 ;
}

