
#include<stdio.h>
	
int main()
{
	int n;
	double x_start,y_start,x_end,y_end,i1,i2,i3,i4 ;
	double x_left,y_top,x_right,y_bottom ;
	double ix,iy ;
	bool flag ;
	scanf("%d",&n) ;
	while(n--){
		scanf("%lf%lf%lf%lf",&x_start,&y_start,&x_end,&y_end) ;
		scanf("%lf%lf%lf%lf",&i1,&i2,&i3,&i4) ;
		x_left = (i1>=i3) ? i3 : i1 ;
		x_right = (i1>=i3) ? i1 : i3 ;
		y_top = (i2>=i4) ? i2 : i4 ;
		y_bottom = (i2>=i4) ? i4 : i2 ;
		ix = (x_end-x_start)/1000 ; iy=(y_end-y_start)/1000 ;
		flag=false ;
		for(double x=x_start,y=y_start,k=0;k<=1000;x+=ix,y+=iy,k++){
			if(x>=x_left&&x<=x_right&&y>=y_bottom&&y<=y_top){
				printf("T\n") ;
				flag = true ;
				break ;
			}
		}
		if(!flag)
			printf("F\n") ;
	}
	return 0 ;
}