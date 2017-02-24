
#include<cstdio>
#include<cstring>

void multiplay(int sum[200],const int r[10])
{
	int tmp[200],i,j ;
	for(i=0;i<200;i++) tmp[i] = 0 ;

	for(i=0;i<10;i++){
		for(j=0;j<190;j++)
			tmp[i+j] += sum[j]*r[i] ;
		for(j=0;j<189;j++){
			if(tmp[j]>9){
				tmp[j+1] += tmp[j]/10 ;
				tmp[j] %= 10 ;
			}
		}
	}
	for(i=0;i<200;i++)
		sum[i] = tmp[i] ;
}

int main()
{
	int r[10],n,d,i,j,sum[200] ;
	char R[10] ;

	while(scanf("%s %d",R,&n)==2)
	{
		d=-1 ;
		for(i=0;i<200;i++) sum[i]=0 ;
		for(i=0;i<10;i++) r[i]=0 ;
		for(i=0,j=0;i<strlen(R);i++){
			if(R[i]=='.'){
				d = strlen(R) - i - 1 ;
				continue ;
			}
			r[j++] = R[i]-'0' ;
		}
		d*=n ;
		j-- ;
		for(i=0;i<=(j/2);i++){
			if(i!=j-i) r[i] ^= r[j-i] ^= r[i] ^= r[j-i] ;
		}
		sum[0]=1 ;
		
		while(n--)
			multiplay(sum,r) ;
		
		bool flag = false ;

		for(j=0;j<200;j++){
			if(sum[j]!=0)
				break ;
		}

		for(i=199;i>=j;i--){
			if(d-1==i){ 
				printf(".") ;
				flag = true ;
			}
			if(sum[i]!=0 || flag){
				printf("%d",sum[i]) ;
				flag = true ;
			}
		}
		printf("\n") ;
	}

	return 0 ;
}