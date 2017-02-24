
#include<stdio.h>

long int N,H,W ;

void make(long i1,long j1,long i2,long j2,long m[500][500] )
{
	long v1=m[i1][j1] , v2=m[i2][j2] ;
	for(int i=0;i<H;i++){
		for(int j=0;j<W;j++){
			if(m[i][j]==v1)
				m[i][j] = v2 ;
		}
	}
}

bool stop(long l[30])
{
	for(int i=0;i<27;i++){
		if(l[i]>0)
			return true ;
	}
	return false ;
}

int main()
{
	long int i,j,map[500][500],log[30] ;
	char tmp[500] ;

	scanf("%d",&N) ;

	for(int k=0;k<N;k++){
		scanf("%d%d",&H,&W) ;
		printf("World #%d\n",k+1) ;
		for(i=0;i<30;i++) log[i] = 0 ;
		for(i=0;i<H;i++){
			scanf("%s",tmp) ;
			for(j=0;j<W;j++)
				map[i][j] = ((tmp[j] - 'a')*1000) + (log[tmp[j] - 'a']++) ;
		}

		for(i=0;i<H;i++){
			for(j=0;j<W;j++){
				if(i>0){
					if((map[i][j]/1000)==(map[i-1][j]/1000)){
						if(map[i][j]!=map[i-1][j]){
							make(i,j,i-1,j,map) ;
							log[map[i][j]/1000]-- ;
						}
					}	
				}
				if(j>0){
					if((map[i][j]/1000)==(map[i][j-1]/1000)){
						if(map[i][j]!=map[i][j-1]){
							make(i,j,i,j-1,map) ;
							log[map[i][j]/1000]-- ;
						}
					}	
				}
			}
		}
		long int max,maxi ;
		while(stop(log)){
			max=0;maxi=-1;
			for(i=0;i<27;i++){
				if(log[i]>max){
					max=log[i] ;
					maxi=i ;
				}
			}
			printf("%c: %ld\n",97+maxi,log[maxi]) ;
			log[maxi]=0 ;
		}
	}

	return 0 ;
}