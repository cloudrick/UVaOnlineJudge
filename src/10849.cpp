
#include<iostream>

using namespace std ;

int main()
{

	int C ;

	cin >> C ;

	while(C--)
	{
		int T,N ;
		cin >> T >> N ;

		while(T--)
		{
			int x1,y1,x2,y2 ;
			cin >> x1 >> y1 >> x2 >> y2 ;
			
			int dx = x1>x2 ? x1-x2 : x2-x1 ;
			int dy = y1>y2 ? y1-y2 : y2-y1 ;

			if( dx==0 && dy == 0)
			{
				cout << 0 << endl ;
				continue ;
			}


			if( (dx+dy)%2 != 0 )
			{
				cout << "no move" << endl ;
			}
			else
			{
				if(  dx != dy  )
					cout << 2 << endl ;
				else
					cout << 1 << endl ;
			}
		}
	}

	return 0 ;
}