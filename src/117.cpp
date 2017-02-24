
#include<cstdio>
#include<cstring>

int main()
{
	int map[26][26],len,i,j ;
	char str[100] ;

	for(i=0i<26;i++){
		for(j=0;j<26;j++)
			map[i][j] = 0 ;
	}

	while(gets(str))
	{
		if(strcmp(str,"deadend")==0){
			// 
		}
		else{
			len = strlen(str) ;
			map[str[0]-'a'][str[len-1]-'a'] = map[str[len-1]-'a'][str[0]-'a'] = len ;
		}
	}

	return 0 ;
}