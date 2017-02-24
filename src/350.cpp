
 /* @JUDGE_ID: 7008MR 350 C++ */ 

#include<stdio.h>

int main(){
	long int z,i,m,l,j,k,n ;
	int pos[10000] ;
	bool table[10000] ;

	k=1;
    while(1){
       	scanf("%ld %ld %ld %ld",&z,&i,&m,&l) ;
        if(m==0)
			break ;
        for(j=0 ; j<=m-1 ; j++)
        	table[j] = false ;
        table[l] = true ;
        pos[l] = 1 ;
        n=1 ;
        while(1){
            n++ ;
        	j = l ;
        	l = (l*z+i) % m ;
            if(table[l])
				break;
            table[l] = true ;
            pos[l] = n ;
		}
        printf("Case %ld: %ld\n",k,pos[j]-pos[l]+1) ;
        k++ ;
	}
	return 0 ;
}
