
/*   @JUDGE_ID:7008MR   275   C++ */

#include <stdio.h>

int main()
{ 
     int a , b[5000] , s[5000] ;
     int t , c , k , l;
     
	 while( scanf("%d %d",&b[0],&a)==2 ){
		 if(b[0] ==0 && a==0 )
			 break ;
         k = b[0] % a ;
		 for( t=0 ; t<5000; t++){
			 b[t] = k * 10 ;
             for(l=0 ; l<t ; l++){
				 if(b[t] == b[l]){
					 printf(".") ;
					 if(b[t] == 0){
						 for(c=0 ; c<t-1 ; c++){
							 printf("%d",s[c]) ;
							 if(c==48 ||(c>49 && (c-48)%50==0))
								 printf("\n") ;
						 }
						 c-- ;
						 if(!(c==48 ||(c>49 && (c-48)%50==0)))
							 printf("\n") ;
						 printf("This expansion terminates.\n\n") ;
						 t = -10 ;
						 l = -1 ;
					 }
					 else{
					     for(c=0 ; c<t ; c++){
							 printf("%d",s[c]) ;
							 if(c==48 ||(c>49 && (c-48)%50==0))
								 printf("\n") ;
						 }
						 c-- ;
						 if(!(c==48 ||(c>49 && (c-48)%50==0)))
							 printf("\n") ;
						 printf("The last %d digits repeat forever.\n\n",t-l) ;
						 t = -10 ;
						 l = -1 ;
					 }
					 break ;
				 }
			 }
             if(t<0)
				 break ;
			 s[t] = b[t] / a ;
             k = b[t] % a ;
		 } 
     }
     return 0 ;
}
