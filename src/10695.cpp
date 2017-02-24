
#include<iostream>

using namespace std ;

int main()
{

	int n=0 ;

	while(n++)
	{
		int x1,x2,x3,y1,y2,y3 ;

		cin >> x1 >> y1 ;
		cin >> x2 >> y2 ;
		cin >> x3 >> y3 ;

		int AOB,BOC,COA ;

		cin >> AOB >> BOC >> COA ;

		if( AOB >= 180 || BOC >= 180 || COA >=180 || AOB+BOC+COA!=360 )
		{
			cout << "Case " << n <<  ":" << endl ;
			cout << "IMPOSSIBLE" << endl ;
			continue ;
		}


	}

}