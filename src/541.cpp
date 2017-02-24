
#include<stdio.h>

bool parity(const int m[][101],const int n)
{
        int sum ;
        for(int i=0;i<n;i++){
                sum=0 ;
                for(int j=0;j<n;j++){
                        if(m[i][j]==1)
                                sum++ ;
                }
                if(sum%2) return false ;
        }
        for(int j=0;j<n;j++){
                sum=0 ;
                for(int i=0;i<n;i++){
                        if(m[i][j]==1)
                                sum++ ;
                }
                if(sum%2) return false ;
        }
        return true ;
}

bool Change(int m[][101],int n)
{
        for(int i=0;i<n;i++){
                for(int j=0;j<=n;j++){
                        m[i][j] = (m[i][j]==1) ? 0 : 1 ;
                        if(parity(m,n)){
                                printf("Change bit (%d,%d)\n",i+1,j+1) ;
                                return true ;
                        }
                        else{
                                m[i][j] = (m[i][j]==1) ? 0 : 1 ;
                        }
                }
        }
        return false ;
}

int main()
{
        int n,i,j,m[101][101] ;

        while(scanf("%d",&n)==1){
                if(n==0) break ;
                for(i=0;i<n;i++){
                        for(j=0;j<n;j++)
                                scanf("%d",&m[i][j]) ;
                }

                if(parity(m,n)){
                        printf("OK\n") ;
                }
                else if(!Change(m,n)){
                        printf("Corrupt\n") ;
                }
        }

        return 0 ;
}
