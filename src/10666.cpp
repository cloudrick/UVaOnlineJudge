
#include<iostream>
#include<cmath>

using namespace std ;

int main()
{
	unsigned int m ;

	cin >> m ;

	while(m--)
	{
		unsigned int n,x ;
		unsigned int max=0,min=0 ;
		cin >> n >> x ;

		int time = 1 ;
		while(true)
		{
			if( x==0 )
			{
				min = 1 ;
				max = 1 ;
				break ;
			}
			if( x % (unsigned int)(pow(2,time))!= 0 )
			{
				unsigned int left = 0 , right = (unsigned int)(pow(2,n)) ;
				while( left!=x && right!=x )
				{
					unsigned int mid = (left+right)/2 ;
					if(x>=mid)
					{
						min++ ;
						left = mid ;
					}
					else
					{
						right = mid ;
					}
				}
				min += 1 ;
				max = (unsigned int)(pow(2,n)) - (unsigned int)(pow(2,time-1)) + 1 ;
				break ;
			}
			time++ ;
		}

		cout << min << " " << max << endl ;
	}

	return 0 ;
}