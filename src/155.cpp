
/* @JUDGE_ID: 7008MR 155 C++ */

#include<stdio.h>

int main(){
	int xx,yy,n,x,y,k ;
    while(1){
        scanf("%d %d %d",&k,&x,&y) ;
        if(k==0)
			break ;
        n = 0 ;
        xx = 1024 ;
        yy = 1024 ;
        while(k>0){
            if((xx-k<=x)&&(x<=xx+k)&&(yy-k<=y)&&(y<=yy+k))
				n++ ;
            if(x==xx||y==yy)
				break;
            if(x<xx)
            	xx = xx - k ;
            else
            	xx = xx + k ;
            if(y<yy)
            	yy = yy - k ;
            else
            	yy = yy + k ;
            k = k / 2;
		}
        printf("%3d\n",n) ;
	}
	return 0 ;
}
