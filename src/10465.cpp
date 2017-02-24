
#include<iostream>

using namespace std ;

int main()
{
	long int m,n,t ;
	long int s,ans,left ;
	long int i ;

	while( cin >> m >> n >> t )
	{
		ans = s = left = 0 ;
		
		if(t<m && t<n){ cout << 0 << " " << t << endl ; continue ; }

		for( i=0 ; i<=t/m ; i++)
		{
			s = i ;
			if((t-(i*m))%n==0)
				s += (t-(i*m))/n ;
			else
				continue ;
			if(s>ans)
				ans = s ;
		}
		if(ans==0)
		{
		
			for( i=0 ; i<=t/m ; i++)
			{
				s = i ;
				s   += (t-(i*m))/n ;
				if(((t-(i*m))%n < left && (t-(i*m))%n!=0) || left == 0)
				{
					ans = s ;
					left = (t-(i*m))%n ;
				}
				else if( (t-(i*m))%n == left && left !=0)
				{
					if(s>ans)
						ans = s ;
				}
			}
		}
		cout << ans ;
		if(left)
			cout << " " << left ;
		cout << endl ;
	}

	return 0 ;
}