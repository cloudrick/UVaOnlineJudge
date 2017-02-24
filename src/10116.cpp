
#include<stdio.h>
#include<string.h>

int main()
{
	int a,b,c,map[15][15] ;
	int i,j,x,y,step ; ;
	char tmp[20] ;

	while(scanf("%d%d%d",&a,&b,&c)==3){
		if(a==0||b==0||c==0)
			break ;
		for(i=0;i<a;i++){
			scanf("%s",tmp) ;
			for(j=0;tmp[j];j++){
				switch(tmp[j]){
				case 'E': map[j][i] = -1 ; break ;
				case 'W': map[j][i] = -2 ; break ;
				case 'N': map[j][i] = -3 ; break ;
				case 'S': map[j][i] = -4 ; break ;
				}
			}
		}
		x=c-1 ; y=0 ; step=0 ;
		while(1){
			switch(map[x][y]){
			case -1 : x++ ; map[x-1][y] = step ; break ;
			case -2 : x-- ; map[x+1][y] = step ; break ;
			case -3 : y-- ; map[x][y+1] = step ; break ;
			case -4 : y++ ; map[x][y-1] = step ; break ;
			default : break ;
			}
			step++ ;
			if(x>=b || x<0 || y<0 || y>=a){
				printf("%d step(s) to exit\n",step) ;
				break ;
			}
			if(map[x][y]>=0 ){
				printf("%d step(s) before a loop of %d step(s)\n",map[x][y],step-map[x][y]) ;
				break ;
			}
		}
	}
	return 0 ;
}