
/* @JUDGE_ID: 7008MR 119  C++ */

#include <stdio.h>
#include <string.h>

char people_name[10][13] ;

int com(char a[] , int n)
{
    int l,i,p;
    for(i=0 ; i<n ; i++ ){
	  l = strlen(people_name[i]) ;
	  for(p=0 ; p<=l ; p++){
		  if(people_name[i][p] == NULL && a[p]==NULL)
			    return(i) ;
		  if(people_name[i][p] != a[p] )
			    break ;
	  }
    }
    return(-1) ;
}

int main()
{
	int people_num , money[20] ;
	int pre , pre_num ;
	int i , j , k ;
	char s[20] ;
	int m , n ;
	for( k=0 ; scanf("%d\n",&people_num)==1 ; k++){
		for(i=0 ; i < people_num ; i++){
			scanf("%s",people_name[i]) ;
				money[i] = 0 ;
		}
		for(i=0 ; i< people_num ; i++){
			scanf("%s %d %d",s,&pre,&pre_num) ;
			if(pre_num == 0)
				continue ;
			m = pre - ( pre % pre_num ) ;
			n = m / pre_num ;
			if(com(s,people_num) >=0 )
				money[com(s,people_num)] -= m ;
			for(j=0 ; j<pre_num ; j++ ){
				scanf("%s",s) ;
				money[com(s,people_num)] += n ;
			}
		}
		for(i=0 ; i<people_num ; i++)
			printf("%s %d\n",people_name[i],money[i]) ;
		printf("\n") ;
	}
	return 0 ;
}