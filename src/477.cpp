
#include<stdio.h>
#include<math.h>

struct m
{
	double x1 ;
	double x2 ;
	double y1 ;
	double y2 ;
	double r ;
	char type ;
}f[10] ;

bool check(int index,double x,double y)
{
	switch(f[index].type){
	case 'r' :
		if(x<f[index].x2 && x>f[index].x1 && y>f[index].y2 && y<f[index].y1)
			return true ;
		else
			return false ;
		break ;
	case 'c' :
		if( sqrt(pow(x-f[index].x1,2.0)+pow(y-f[index].y1,2.0)) < f[index].r)
			return true ;
		else
			return false ;
		break ;
	}
	return false ;
}

int main()
{
	char type[5] ;
	int nf,np,i ;
	double x,y ;
	bool flag ;
	nf=0 ;
	while(scanf("%s",type)==1){
		if(type[0]=='*') 
			break ;
		else if(type[0]=='r'){
			scanf("%lf%lf%lf%lf",&f[nf].x1,&f[nf].y1,&f[nf].x2,&f[nf].y2) ;
			if(f[nf].x1>f[nf].x2){
				double tmp ;
				tmp = f[nf].x1 ;
				f[nf].x1 = f[nf].x2 ;
				f[nf].x2 = tmp ;
			}
			if(f[nf].y1<f[nf].y2){
				double tmp ;
				tmp = f[nf].y1 ;
				f[nf].y1 = f[nf].y2 ;
				f[nf].y2 = tmp ;
			}
			f[nf].type = 'r' ;
		}
		else if(type[0]=='c'){
			scanf("%lf%lf%lf",&f[nf].x1,&f[nf].y1,&f[nf].r) ;
			f[nf].type = 'c' ;
		}
		nf++ ;
	}
	np=1 ;
	while(scanf("%lf%lf",&x,&y)==2){
		if(x==9999.9 && y==9999.9) break ;
		flag=false ;
		for(i=0;i<nf;i++){
			if(check(i,x,y)){
				printf("Point %d is contained in figure %d\n",np,i+1) ;
				flag=true ;
			}
		}
		if(!flag)
			printf("Point %d is not contained in any figure\n",np) ;
		np++ ;
	}
	return 0 ;
}