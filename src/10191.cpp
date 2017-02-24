
#include<cstdio>

int main()
{
	int n,nn,begin,end,i,lmax,max,maxi ;
	char str[500] ;
	bool time[481] ;

	nn=1 ;
	while( scanf( "%d \n" ,&n)==1 )
	{
		printf("Day #%d: ",nn++) ;
		for(i=0;i<481;i++) time[i] = false ;
		while(n--){
			gets(str) ;
			begin = ((str[0]-'0')*600) + ((str[1]-'0')*60) +
					((str[3]-'0')*10)  + (str[4]-'0') - 600 ;
			end =   ((str[6]-'0')*600) + ((str[7]-'0')*60) +
					((str[9]-'0')*10)  + (str[10]-'0') - 600 ;

			if(begin>end)
				begin ^= end ^= begin ^= end ;

			for(i=begin ; i<end ; i++){
				if(i>=0 && i<=480)
					time[i] = true ;
			}
		}	

		max = lmax = 0 ; maxi = -1 ;

		for(i=0 ; i<480 ; i++){
			if(time[i]==false)
				lmax++ ;
			else{
				if(lmax>max){
					max=lmax ;
					maxi = i - max ;
				}
				lmax = 0 ;
			}
		}
		if(lmax>max){
			max=lmax ;
			maxi = i - max ;
		}

		printf("the longest nap starts at ") ;
		printf("%d:",(maxi/60)+10) ;
		if(maxi%60<10)
			printf("0") ;
		printf("%d ",maxi%60) ;
		printf("and will last for ") ;
		if(max>=60)
			printf("%d hours and ",max/60) ;
		printf("%d minutes.\n",max%60) ;
	}
	return 0 ;
}