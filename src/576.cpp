
#include<cstdio>
#include<cstring>

int main()
{
	char str[1000] ;
	int syllables , line , i ;
	bool flag,v ;

	while(gets(str))
	{
		if( strcmp(str, "e/o/i" ) == 0) 
			break ;

		syllables = 0 ;
		line = 1 ;
		flag = true ;
		v = false ;
		
		for( i=0 ; i<int(strlen(str)) ; i++ )
		{
			if( str[i] == 'a' || str[i]== 'i' || str[i] == 'o' || 
				str[i] == 'u' || str[i]== 'e' || str[i] == 'y' )
			{
				if( v == false )
				{
					syllables++ ;
					v = true ;
				}
				continue ;
			}

			if(str[i] == '/'){

				if(line == 1)
				{
					if( syllables != 5){
						printf("1\n") ;
						flag = false ;
						break ;
					}
					else{
						line = 2 ;
						syllables = 0 ;
						v = false ;
						continue ;
					}
				}

				if(line == 2)
				{
					if( syllables != 7){
						printf("2\n") ;
						flag = false ;
						break ; ;
					}
					else{
						line = 3 ;
						syllables = 0 ;
						v = false ;
						continue ;
					}
				}
			}

			v = false ;
		}

		if( flag && syllables != 5 ){
			printf("3\n") ;
			flag = false ;
		}
		
		if(flag)
			printf("Y\n") ;
	}

	return 0 ;
}