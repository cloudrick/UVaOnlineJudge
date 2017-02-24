
#include<iostream>
#include<cmath>

using namespace std ;

int main()
{
	while(true)
	{
		int N ;
		double mapX[1001],mapY[1001] ;
		int reached[1001] ;

		cin >> N ;
		if(N==0)
			break ;

		for( int n=0 ; n<N ; n++)
		{
			cin >> mapX[n] >> mapY[n] ;
			reached[n] = false ;
		}

		for( int i=0 ; i<N ; i++)
		{
			double closeest1 = 100 , closeest2 = 90 ;

			for( int j=0 ; j<N ; j++)
			{
				if( i==j )
					continue ;
				if(  sqrt(pow(mapX[i]-mapX[j],2) + pow(mapY[i]-mapY[j],2))
					 < closeest1
					)
				{
					closeest2 = closeest1 ;
					closeest1 = sqrt(pow(mapX[i]-mapX[j],2) + pow(mapY[i]-mapY[j],2)) ;
				}
				if(  sqrt(pow(mapX[i]-mapX[j],2) + pow(mapY[i]-mapY[j],2))
					 == closeest1
					)
				{

				}
			}
		}
		
	}

	return 0 ;
}