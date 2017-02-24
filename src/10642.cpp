
#include <iostream>

using namespace std;

int dis(int x,int y)
{
	int ans;
	int t=x+y;
	ans=t*(t-1)/2+t+t-y;
	return ans;
}

int main()
{
	int n,x1,y1,x2,y2,i=1;

	cin >> n;

	while (n--)
	{

		cin >> x1 >> y1 >> x2 >> y2 ;
		cout << "Case " << i << ": " << dis(x2,y2)-dis(x1,y1) << endl ;
		i++;
	}
	return 0;
}