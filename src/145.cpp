

#include<cstdio>

int main()
{
	int bHour,bMinute,eHour,eMinute ;
	char level[5] ;
	char number[20] ;
	bool flag ;
	double t1,t2,t3,total ;
	int T1,T2,T3 ;

	while(scanf("%s",level)==1)
	{
		if(level[0]=='#')
			break ;

		switch(level[0]){
		case 'A' : t1=0.1 ; t2=0.06 ; t3=0.02 ; break ;
		case 'B' : t1=0.25 ; t2=0.15 ; t3=0.05 ; break ;
		case 'C' : t1=0.53 ; t2=0.33 ; t3=0.13 ; break ;
		case 'D' : t1=0.87 ; t2=0.47 ; t3=0.17 ; break ;
		case 'E' : t1=1.44 ; t2=0.80 ; t3=0.30 ; break ;
		}

		scanf("%s %d%d%d%d",number,&bHour,&bMinute,&eHour,&eMinute) ;
		flag = true ;

		if( (eHour<bHour) || (eHour==bHour && eMinute<bMinute))
		{
			eHour ^= bHour ^= eHour ^= bHour ;
			eMinute ^= bMinute ^= eMinute ^= bMinute ;
			flag = false ;
		}	

		if(eHour == 0 && eMinute==0)
			eHour = 24 ;
			
		total = 0.0 ;
		T1 = T2 = T3 = 0 ;

		for(int i=bHour*60+bMinute+1 ; i<=eHour*60+eMinute ; i++)
		{
			if(i>480 && i<=1080){
				total += t1 ;
				T1++ ;
			}
			if(i>1080 && i<=1320){
				total += t2 ;
				T2++ ;
			}
			if(i>1320 || i<=480){
				total += t3 ;
				T3++ ;
			}
		}

		if(!flag)
		{
			T1 = 600-T1 ;
			T2 = 240-T2 ;
			T3 = 600-T3 ;
			total = (T1*t1) + (T2*t2) + (T3*t3) ;
		}

		printf("%10s%6d%6d%6d  %c%8.2lf\n",number,T1,T2,T3,level[0],total) ;
	}

	return 0 ;

}

