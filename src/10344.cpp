
#include<stdio.h>

long int sum ;

void calc(int s,int n){
	switch(s){
	case 0 : sum+=n ; break ;
	case 1 : sum-=n ; break ;
	case 2 : sum*=n ; break ;
	};
}

int main()
{
	int i1,i2,i3,i4,i5 ;
	int o1,o2,o3,o4 ;
	int num[10] ;
	bool f ;

	while(scanf("%d%d%d%d%d",&num[0],&num[1],&num[2],&num[3],&num[4])==5){
		if(!num[0]&&!num[1]&&!num[2]&&!num[3]&&!num[4])
			break ;
		f = false ;
		for(i1=0;i1<5;i1++){
			for(i2=0;i2<5;i2++){
				if(i1==i2) continue ;
				for(i3=0;i3<5;i3++){
					if(i3==i1||i3==i2) continue ;
					for(i4=0;i4<5;i4++){
						if(i4==i3||i4==i2||i4==i1) continue ;
						for(i5=0;i5<5;i5++){
							if(i5==i4||i5==i3||i5==i2||i5==i1) continue ;
							for(o1=0;o1<3;o1++){
								for(o2=0;o2<3;o2++){
									for(o3=0;o3<3;o3++){
										for(o4=0;o4<3;o4++){
											sum=num[i1] ; 
											calc(o1,num[i2]) ;
											calc(o2,num[i3]) ;
											calc(o3,num[i4]) ;
											calc(o4,num[i5]) ;
											if(sum==23){
												printf("Possible\n") ;
												o1=o2=o3=o4=100 ;
												i1=i2=i3=i4=i5=100 ;
												f = true ;
											}
										}
									}
								}
							}

						}
					}
				}
			}
		}
		if(!f)
			printf("Impossible\n") ;
	}
	return 0 ;
}