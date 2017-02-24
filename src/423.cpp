
#include<stdio.h>
#include<string.h>

int main()
{

        long int n,m[101][101],i,j,k ;
        char tmp[10] ;
        long int tmp_num,max ;

        while(scanf("%ld",&n)==1){

        for(i=2;i<=n;i++){
                for(j=1;j<i;j++){
                        tmp_num = 0 ;
                        scanf("%s",tmp) ;
                        if(tmp[0] == 'x'){ m[j][i] = m[i][j] = -1 ; continue ; }
						 for(k=0;k<int(strlen(tmp));k++)
                                tmp_num = tmp_num * 10 + tmp[k] - '0' ;
                        m[j][i] = m[i][j] = tmp_num ;
                        m[i][i] = m[j][j] = 0 ;
                }
        }

        for(i=1;i<=n;i++){
                for(j=1;j<=n;j++){
                        if(i==j) continue ;
                        for(k=1;k<=n;k++){
                                if(k==i || k==j) continue ;
                                if(m[i][k]<0 || m[k][j]<0) continue ;
                                if(m[i][k]+m[k][j] < m[i][j] || m[i][j]<0 )
                                        m[i][j] = m[i][k]+m[k][j] ;
                        }
                }
        }

        for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
                        if(i==j) continue ;
						   for(k=1;k<=n;k++){
                                if(k==i || k==j) continue ;
                                if(m[i][k]<0 || m[k][j]<0) continue ;
                                if(m[i][k]+m[k][j] < m[i][j] || m[i][j]<0 )
                                        m[i][j] = m[i][k]+m[k][j] ;
                        }
                }
        }

        max = 0 ;

        for(i=2;i<=n;i++){
                if(m[1][i]>max)
                        max = m[1][i] ;
        }

        printf("%ld\n",max) ;
        }
        return 0 ;
}

