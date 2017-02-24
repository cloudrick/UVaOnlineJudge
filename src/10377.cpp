
#include<stdio.h>

int main()
{
	int maze[70][70],d ;
	int n,w,h,x,y,i,j ;
	char tmp[70],ch ;
	scanf("%d",&n) ;
	while(n--){
		scanf("%d%d\n",&h,&w) ;
		for(i=0;i<h;i++){
			gets(tmp) ;
			for(j=0;j<w;j++){
				if(tmp[j]=='*')
					maze[i][j] = 1 ;
				else
					maze[i][j] = 0 ;
			}
		}
		scanf("%d%d\n",&x,&y) ;
		d=0 ;
		while(scanf("%c",&ch)==1){
			if(ch=='Q') break ;
			if(ch=='R'){ d+=1 ; d%=4 ; }
			if(ch=='L'){ d+=3 ; d%=4 ; }
			if(ch=='F'){
				switch(d){
				case 0 :
					if(x>1 && maze[x-2][y-1]==0)
						x-- ;
					break ;
				case 1 :
					if(y<w && maze[x-1][y]==0)
						y++ ;
					break ;
				case 2 :
					if(x<h && maze[x][y-1]==0)
						x++ ;
					break ;
				case 3 :
					if(y>1 && maze[x-1][y-2]==0)
						y-- ;
					break ;
				}
			}
		}
		printf("%d %d ",x,y) ;
		switch(d){
		case 0 : printf("N\n") ; break ;
		case 1 : printf("E\n") ; break ;
		case 2 : printf("S\n") ; break ;
	    case 3 : printf("W\n") ; break ;
		}
	}

	return 0 ;
}

