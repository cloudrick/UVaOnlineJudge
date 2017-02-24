
/* @JUDGE_ID: 7008MR 573 C++ */

#include<stdio.h>

int main(){
	double day,h,u,d,f,m ;
	
	while(1){
		scanf("%lf %lf %lf %lf",&h,&u,&d,&f) ;
        if(h==0)
			break ;
	    day=1;
		m=0;
		while(1){
        	if(u>(day-1)*u*f/100)
	    	    m = m + u - (day-1) * u * f / 100 ;
			if(m>h){
    	        printf("success on day %.0lf\n",day) ;
        		break;
			}
    	    m = m-d ;
			if(m<0){
    	    	printf("failure on day %.0lf\n",day);
        	    break;
			}
    	    day++ ;
		}
	}

	return 0 ;
}
