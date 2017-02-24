
#include<iostream>

using namespace std ;

int prime[4000] ;

/* Returns zero-based position of the survivor among n people, with elimination
   starting from person 0, and step prime[p] 

int survivor(int n, int p)
{
        int m, k;

        if (n <= 1)
                return 0;               // one person left, he's the only survivor 

        m = (prime[p] - 1) % n;         // who's leaving now 
        k = survivor(n - 1, p + 1);     // the final survivor's position, relative to m 

        
         //  Now we need to map the final survivor's position back into the old
         //  indexing system. Here's an example for case n=9, m=3:
         //
         //          0 1 2 3 4 5 6 7 8  -- initial indexing
         //                x            -- person m=3 gets eliminated
         //  k=      5 6 7 . 0 1 2 3 4  -- what will be returned by the recursive call
         //  result: 0 1 2 . 4 5 6 7 8  -- back to the old indexing
         //

        if (k < (n - m - 1))
                return (k + m + 1);
        else
                return (k - (n - m - 1));
}
*/

int survivor(int n)
{
   int i, s;

   for (s = 0, i = 1; i <= n; i++)
      s = (s + prime[n - i]) % i ;

   return (s + 1);
}

int main()
{
	bool prime_map[37814] ;
	int i,j ;

	for( i=0 ; i<37814 ; ++i)
	{
		prime_map[i] = true ;
	}

	int l=0 ;
	for( i=2 ; i<37814 ; ++i)
	{
		if( prime_map[i] )
		{
			prime[l++] = i ;
			for( j=2 ; i*j<37814 ; ++j)
				prime_map[i*j] = false ;
		}
	}

	while(true)
	{
		int n ; 
		cin >> n ;
		if( n==0 )
			break ;
		else
			cout << survivor(n) << endl ;
	}

	return 0 ;
}