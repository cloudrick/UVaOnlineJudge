
/* @JUDGE_ID: 7008MR 414 C++ */

#include<stdio.h>

int main(){
	int i,j,n,max,row[13] ;
	char c ;
	while(1){
		scanf("%d",&n) ;
        if(n==0)
			break ;
        max = 0 ;
        for(i=0 ; i<n ; i++){
        	row[i] = 0 ;
			while(scanf("%c",&c)){
				if(c=='X')
					break ;
			}
            if( c=='X' )
				row[i]++ ;
            for(j=1 ; j<=24 ; j++){
            	scanf("%c",&c) ;
                if(c=='X')
					row[i]++ ;
			}
            if(row[i]>max) 
				max = row[i] ;
		}
        j = 0 ;
        for(i=0 ;i <n ; i++)
        	j += max-row[i] ;
        printf("%d\n",j) ;
	}
	return 0 ;
}
