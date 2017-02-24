
#include<cstdio>
#include<cstring>

int main()
{
	char str[25],c ;
	int f ;

	while(scanf("%s",str)==1)
	{
		f = 0 ;
		for(int i=0 ; i<int(strlen(str)) ; i++){
			c = str[i] ;
			if(c=='B' || c=='F' || c== 'P'|| c=='V'){
				if(f!=1){
					printf("1") ;
					f = 1 ;
				}
			}
			else if(c=='C' || c=='G'|| c=='J'|| c=='K' 
				|| c=='Q' || c=='S' || c=='X'|| c=='Z' ){
				if(f!=2){
					printf("2") ;
					f = 2 ;
				}
			}
			else if(c=='D' ||c=='T' ){
				if(f!=3){
					printf("3") ;
					f = 3 ;
				}
			}
			else if(c=='L'){
				if(f!=4){
					printf("4") ;
					f = 4 ;
				}
			}
			else if(c=='M' ||c=='N' ){
				if(f!=5){
					printf("5") ;
					f = 5 ;
				}
			}
			else if(c=='R'){
				if(f!=6){
					printf("6") ;
					f = 6 ;
				}
			}
			else
				f = 0 ;
		}

		printf("\n") ;
	}

	return 0 ;
}