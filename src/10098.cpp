
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std ;

int main()
{
	char tmp[15] ;
	int str[15],n,i,len ;
	cin >> n ;
	while(n--){
		cin >> tmp ;
		len = strlen(tmp) ;
		for(i=0;i<len;i++){
			if(tmp[i]>='A' && tmp[i]<='Z')
				str[i] = (tmp[i] - 'A')*2 ;
			else
				str[i] = (tmp[i] - 'a')*2 + 1 ;
		}
		sort(str,str+len) ;
		do{			
			for(i=0;i<len;i++){
				if(str[i]%2)
					cout << char(97+((str[i]-1)/2)) ;
				else
					cout << char(65+(str[i]/2)) ;
			}
			cout << endl ;
		}while(next_permutation(str,str+len)) ;
		cout << endl ;
	}
	return 0 ;
}
