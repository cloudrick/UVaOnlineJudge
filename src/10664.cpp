
#include<iostream>
#include<queue>
#include<cstdlib>
#include<cstring>

using namespace std;

int main()
{
	priority_queue<int> que;
	char line[300];

	char delims[] = " ";

	int n;
	cin >> n;

	while (n--)
	{
		while(1)
		{
			cin.getline(line,255);
			if (line[0]!='\0')
				break;
		}

		char *result = NULL;
		result = strtok( line, delims );
		while( result != NULL )
		{
			que.push ( atoi(result));
			result = strtok( NULL, delims );
		}

		int sum1=0,sum2=0;

		while(que.size())
		{
			if (sum1<=sum2)
				sum1+=que.top();
			else
				sum2+=que.top();
			que.pop();
		}
		if (sum1==sum2)
			cout << "YES" << endl ;
		else
			cout << "NO" << endl;
	}

	return 0;
}