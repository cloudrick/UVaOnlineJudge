
#include<stdio.h>

int main()
{
	int num[10000],cnt[10000],size ;
	int tmp,i ;
	bool found ;
	size=0 ;
	while(scanf("%d",&tmp)==1){
		found = false ;
		for(i=0;i<size;i++){
			if(num[i]==tmp){
				cnt[i]++ ;
				found = true ;
			}
		}
		if(!found){
			num[size] = tmp ;
			cnt[size++] = 1 ;
		}
	}
	for(i=0;i<size;i++){
		printf("%d %d\n",num[i],cnt[i]) ;
	}
	return 0 ;
}