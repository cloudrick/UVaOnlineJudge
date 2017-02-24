
#include <vector>
#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int C[13][13] = {0};
	C[0][0] = 1;
	for(int i=0; i<13; ++i)
	{
		C[i][0] = 1;
	}
	for(int i=1; i<13; ++i)
	{
		C[0][i] = 0;
	}
	for(int i=1; i<13; ++i)
	{
		for(int j=1; j<13; ++j)
		{
			C[i][j] = C[i-1][j-1] + C[i-1][j];
		}
	}

	for(;;)
	{
		int n = 0;
		int k = 0;

		cin >> n >> k;

		if(cin.eof()) break;

		vector<int> coeff_target;

		for(int i=0; i<k ; ++i)
		{
			int t = 0;
			cin >> t;
			coeff_target.push_back(t);
		}

		int nn = n;
		int coeff = 1;

		for(int i=0; i<k ; ++i)
		{
			int v = coeff_target[i];
			coeff *= C[nn][v];
			nn -= v;
		}

		cout << coeff << endl;
	}

	return 0;
}


