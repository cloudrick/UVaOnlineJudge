
#include<cstdio>
#include<cstring>
#include<cstdlib>

int main()
{
	int n,i ;
	char str[130] ;
	int tab[130],len ;
	bool flag ; 

	gets(str) ;

	n = atol(str) ;

	while(n--){

		gets(str) ;

		if( !str )
		{
			printf("Yes\n") ;
			continue ;
		}
		len = 0 ;

		flag = true ;
		
		for( i=0 ; i<int(strlen(str)) ; i++ )
		{
			if(str[i] =='('){
				tab[len++] = 1 ;
				continue ;
			}
			if(str[i] == '['){
				tab[len++] = 2 ;
				continue ;
			}
			if(str[i] == ')'){
				if(len>0){
					if(tab[len-1] == 1)
						len-- ;
					else{
						flag = false ;
						break ;
					}

				}
				else{
					flag = false ;
					break ;
				}
			}
			if(str[i] == ']'){
				if(len>0){
					if(tab[len-1] == 2)
						len-- ;
					else{
						flag = false ;
						break ;
					}

				}
				else{
					flag = false ;
					break ;
				}
			}

		}
		if(flag && len==0)
			printf("Yes\n") ;
		else
			printf("No\n") ;
	}
	return 0 ;
}