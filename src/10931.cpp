#include<iostream>

using namespace std;

int main()
{
	while(1)
	{
		int in,t,c,i,A[64];
		
		cin>>in;
		
		if(in == 0) break;
		
		c = 0;
		
		for(i = 0 ; i<64 ; i++) A[i]=0;
		i = 0;
		t = in;
		while(t)
		{
			if(t%2)
			{
				A[i] = 1;
				i++;
				c++;
				
			}
			else
			{
				A[i] = 0;
				i++;
			}
			t/=2;
		}
		cout<<"The parity of ";
		for(i--;i>=0;i--)
			
			cout<<A[i];
		cout<<" is "<<c<<" (mod 2).\n";
	}
	return 0;
}