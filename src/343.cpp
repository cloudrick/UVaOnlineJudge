
#include<cstdio>
#include<cstring>

inline int count(char *s,int base)
{
	int sum=0 ;

	for(int i=0 ; i<int(strlen(s)) ; i++ )
	{
		if(s[i]>='0' && s[i]<='9')
			sum=(sum*base)+s[i]-'0' ;
		else
			sum=(sum*base)+s[i]-'A'+10 ;
	}
	return sum ;
}

int main()
{
	char str1[10],str2[10] ;
	int base1,base2 ;
	bool found ;

	while( scanf( " %s %s " )==2 )
	{
		found=false ;
		for(base1=2;!found;base1++){
			for(base2=2;;base2++){
				if(  count(str1,base1) ==
					count(str2,base2)  ){
					found = true ;
					break ;
				}
				if(  count(str1,base1) <
					 count(str2,base2)  ){
					 break ;
				}
			}
		}
	}

	return 0 ;
}