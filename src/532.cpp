
/*   @JUDGE_ID: 7008MR 532   C++   */ 

#include<stdio.h>

unsigned int maze[32][32][32] ;
unsigned long q[38000] ;
unsigned int log[38000] ;
unsigned int L,W,H ;
unsigned long START,END ;

unsigned int grep(unsigned int h,int s){
	switch(s){
	case 0: return(q[h]/10000) ;
	case 1: return((q[h]%10000)/100) ;
	case 2: return(q[h]%100) ;
	}
	return 0 ;
}

unsigned long save(unsigned int i,unsigned int j,unsigned int k){
	return((i*10000)+(j*100)+k) ;
}

void BFS(){
	unsigned int l,w,h,s,t=0 ;
	q[0] = START ;
	log[0] = 0 ;
	for( s=0 ; s<=t ; s++){
		l=grep(s,0) ;
		w=grep(s,1) ;
		h=grep(s,2) ;
	    maze[l][w][h] = 1 ;
		if(save(l,w,h)==END){
			if( l<L && l>1 && w<W && w>1 && h<H && h>1)
				s=t+1 ;
		    else
				printf("Escaped in %u minute(s).\n",log[s]) ;
			break ;
		}
		if(maze[l+1][w][h]==0){
			q[++t] = save(l+1,w,h) ; log[t] = log[s] + 1 ; maze[l+1][w][h] = 1 ;}
		if(maze[l-1][w][h]==0){
			q[++t] = save(l-1,w,h) ; log[t] = log[s] + 1 ; maze[l-1][w][h] = 1 ;}
		if(maze[l][w+1][h]==0){
			q[++t] = save(l,w+1,h) ; log[t] = log[s] + 1 ; maze[l][w+1][h] = 1 ;}
		if(maze[l][w-1][h]==0){
			q[++t] = save(l,w-1,h) ; log[t] = log[s] + 1 ; maze[l][w-1][h] = 1 ;}
		if(maze[l][w][h+1]==0){
			q[++t] = save(l,w,h+1) ; log[t] = log[s] + 1 ; maze[l][w][h+1] = 1 ;}
		if(maze[l][w][h-1]==0){
			q[++t] = save(l,w,h-1) ; log[t] = log[s] + 1 ; maze[l][w][h-1] = 1 ;}
	}
	if(s>t)
		printf("Trapped!\n") ;
}

int main()
{
	char a ;
	unsigned int i,j,k ;
	while(scanf("%d %d %d",&L,&W,&H)==3){
		if(L==0 && W==0 && H==0)
			break ;
		for( i=0 ; i<=L+1 ; i++){
			for( j=0 ; j<=W+1 ; j++){
				for( k=0 ; k<=H+1 ; k++){
					if(i==0 || j==0 || k==0 || i>L || j>W || k>H)
						maze[i][j][k] = 1 ;
					else{
						scanf("%c\n",&a) ;
						switch(a){
						case '#' : maze[i][j][k] = 1 ; break ;
						case '.' : maze[i][j][k] = 0 ; break ;
					    case 'S' : maze[i][j][k] = 0 ; START = save(i,j,k) ;
							       break ;
						case 'E' : maze[i][j][k] = 0 ; END = save(i,j,k) ;
							       break ;
						}
					}
				}
			}
		}

		BFS() ;
	}
	return 0 ;
}