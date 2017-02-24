
#include<iostream>
#include<string>
#include<stack>
#include<cstdio>

using namespace std ;

int main()
{

	int N ;

	cin >> N ;

	while(N--)
	{
		string str ;
		cin >> str ;

		int num[21] ;
		int length_num = 0 ;
		int op[21] ;
		int length_op = 0 ;
		int tmp = 0 ;

		for( int i=0 ; i<str.length() ; i++)
		{
			if( str[i]== '+')
			{
				num[length_num++] = tmp ;
				tmp = 0 ;
				op[length_op++] = 1 ;
			}
			else if( str[i]== '*')
			{
				num[length_num++] = tmp ;
				tmp = 0 ;
				op[length_op++] = 2 ;
			}
			else if( str[i]>='0' && str[i] <='9')
			{
				tmp = tmp*10 + str[i] - '0' ;
			}
		}
		num[length_num++] = tmp ;
		tmp = 0 ;

		stack<long long int> s ;
		long long int maxV,minV ;
		int j,k ;

		j=k=0 ;
		s.push(num[j++]) ;
		for( ; j<length_num;j++)
		{
			if(op[k]==1)
			{
				s.push(num[j]) ;
				k++ ;
			}
			else if(op[k]==2)
			{
				long long int t=s.top() ;
				t*=num[j] ;
				s.pop() ;
				s.push(t) ;
				k++ ;
			}
		}
		minV = 0 ;
		while(!s.empty())
		{
			minV += s.top() ;
			s.pop() ;
		}

		j=k=0 ;
		s.push(num[j++]) ;
		for( ; j<length_num;j++)
		{
			if(op[k]==1)
			{
				int t=s.top() ;
				t+=num[j] ;
				s.pop() ;
				s.push(t) ;
				k++ ;
			}
			else if(op[k]==2)
			{
				s.push(num[j]) ;
				k++ ;
			}
		}
		maxV = 1 ;
		while(!s.empty())
		{
			maxV *= s.top() ;
			s.pop() ;
		}
	
		printf("The maximum and minimum are %lld and %lld.\n",maxV,minV) ;
	}

	return 0 ;
}