
/*   @JUDGE_ID: 7008MR  591   C++ */ 

#include <stdio.h>

int main()
{
	int n , k , j=1 ;
	int box[101] , t ;

	for( scanf("%d", &n) ; n!=0 ; scanf("%d",&n))
	{
		t = 0 ;
		k = 0 ;

		for(int i=0 ; i<n ; i++)
		{
			scanf("%d" , &box[i]) ;
			t += box[i] ;
		} 

		t /= n ;

        for(i=0 ; i<n ; i++)
		{
			if( box[i] >= t )
				k = k + box[i] - t ;
			else
				k = k + t - box[i] ;
		}
		k /= 2 ;
		if(j != 1)
			printf("\n") ;
        printf("Set #%d\n",j) ;
		printf("The minimum number of moves is %d.",k) ;
		j++ ;
	}
    return 0 ;
}
