// Written by Rick-Yang.
// ACM
// Problem(10079) Pizza Cutting .

/*   @JUDGE_ID: 7008MR   10079   C++  */ 

#include <stdio.h>

int main(){
        long long int n;
        while(scanf("%lld",&n) && n>=0)
                printf("%lld\n",n*(n+1)/2+1);
        return 0;
}

