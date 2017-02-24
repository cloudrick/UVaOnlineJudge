
#include<stdio.h>
#include<string.h>
#include<math.h>

const double sqrt_2 = 1.4142135623730950488016887242097 ;

int main()
{
	int n,dir ;
	char str[250] ;
	double x,y,d,tmp ;
	n=1 ;
	while(scanf("%s",str)==1){
		if(strcmp(str,"END")==0)
			break ;
		x=10e-12 ; y=10e-12 ; tmp =0.0 ; dir = -1 ;
		for(int i=0;i<int(strlen(str));i++){
			if(str[i]>='0' && str[i]<='9')
				tmp = tmp*10 + str[i] - '0' ;
			if(str[i]>='A' && str[i] <= 'Z'){
				if(str[i]=='N')
					dir = 1 ;
				if(str[i]=='S')
					dir = 4 ;
				if(str[i]=='E'){
					if(dir>0)
						dir++ ;
					else
						dir=7 ;
				}
				if(str[i]=='W'){
					if(dir>0)
						dir+=2 ;
					else
						dir=8 ;
				}
			}
			if(str[i]=='.'||str[i]==','){
				switch(dir){
				case 1: y+=tmp ; break ;
				case 2: x+=tmp/sqrt_2 ; y+=tmp/sqrt_2 ; break ;
				case 3: x-=tmp/sqrt_2 ; y+=tmp/sqrt_2 ; break ;
				case 4: y-=tmp ; break ;
				case 5: x+=tmp/sqrt_2 ; y-=tmp/sqrt_2 ; break ;
				case 6: x-=tmp/sqrt_2 ; y-=tmp/sqrt_2 ; break ;
 				case 7: x+=tmp ; break ;
				case 8: x-=tmp ; break ;
				}
				tmp=0.0 ; dir =-1 ;
			}
		}
		d = sqrt((x*x)+(y*y)) ;
		printf("Map #%d\n",n++) ;
		printf("The treasure is located at (%.3lf,%.3lf).\n",x,y) ;
		printf("The distance to the treasure is %.3lf.\n\n",d) ;
	}
	return 0 ;
}
