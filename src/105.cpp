
#include <stdio.h>

int main(){
	int l , h , r ;
	int i ;
	int b[20000] ;
	for(i=0 ; i<20000 ; i++)
			b[i] = 0 ;
	while(scanf("%d%d%d",&l,&h,&r)==3){
		if(!h)
			break ;
		l+=10000 ; r+=10000 ;
		for( ;l<r; l++){
			if(b[l]<h)
				b[l] = h ;
		}
	}
	h = -1 ;
	r = 0 ;

	bool flag = false ;

	for(i=0 ; i<20000 ; i++){
			if(b[i] != h && b[i]){
				r = 1 ;
			    h = b[i] ;
				if( flag )
					printf(" ") ;

				printf("%d %d",i-10000,h) ;
				flag = true ;
			}
			else if(h==-1)
				continue ;
			else if(r && !(b[i]))
			{
				if( flag )
					printf(" ") ;

				printf("%d 0",i-10000) ;
				flag = true ;
				r=0 ; 
			}
	}

	printf("\n") ;

	return 0 ;	
}