
#include<cstdio>

int main()
{
	double x1,x2,x3,x4,y1,y2,y3,y4 ;
	double ansx,ansy ;

	while(scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4)==8)
	{
		if(x1==x2&&y1==y2){
			ansx = x3-(x1-x4) ;
			ansy = y3-(y1-y4) ;
		}
		else if(x1==x3&&y1==y3){
			ansx = x2-(x1-x4) ;
			ansy = y2-(y1-y4) ;
		}
		else if(x1==x4&&y1==y4){
			ansx = x2-(x1-x3) ;
			ansy = y2-(y1-y3) ;
		}
		else if(x2==x3&&y2==y3){
			ansx = x1-(x2-x4) ;
			ansy = y1-(y2-y4) ;
		}
		else if(x2==x4&&y2==y4){
			ansx = x1-(x2-x3) ;
			ansy = y1-(y2-y3) ;
		}
		else if(x4==x3&&y4==y3){
			ansx = x2-(x3-x1) ;
			ansy = y2-(y3-y1) ;
		}
		printf("%.3lf %.3lf\n",ansx,ansy) ;
	}
	return 0 ;
}