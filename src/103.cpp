
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<set>

using namespace std ;

class box
{
public :
	vector<int> b;
	int num ;
	int pre ;

	box() : num(-1),pre(-1)
	{

	}

	bool operator<(const box &r) const
	{
		for( int i=0 ; i<r.b.size() ; ++i)
		{
			if( b[i] >= r.b[i] )
				return false ;
		}
		return true ;
	}
} ;

int main()
{
	bool flag = false ;
	for(;;)
	{
		int k,n ;
		cin >> k >> n ;
		if( cin.eof() )
			break ;

		vector<box> box_list ;

		for( int kk=0 ; kk<k ; ++kk)
		{
			box tmp_box ;
			tmp_box.num = kk+1 ;

			for( int nn=0 ; nn<n ; ++nn)
			{
				int tmp ;
				cin >> tmp ;
				tmp_box.b.push_back(tmp) ;
			}

			sort(tmp_box.b.begin() , tmp_box.b.end() ) ;
			box_list.push_back(tmp_box) ;
		}

		sort( box_list.begin() , box_list.end() ) ;

		int dp[31] ;

		for(int ii=0 ;ii<31;++ii)
			dp[ii] = 1 ;

		int max_v = 0 ;
		int max_i = 0 ;

		for( int i=0 ; i<box_list.size() ; ++i)
		{

			for( int j=0 ; j<box_list.size() ; ++j)
			{
				if( i==j )
					continue ;

				if( box_list[j] < box_list[i] )
				{
					if( dp[j]+1 > dp[i] )
					{
						box_list[i].pre = j ;
						dp[i] = dp[j]+1 ;
					}
				}
				if( box_list[i] < box_list[j] )
				{
					if( dp[i]+1 > dp[j] )
					{
						box_list[j].pre = i ;
						dp[j] = dp[i]+1 ;
					}
				}
			}

			if( dp[i] > max_v )
			{
				max_v = dp[i] ;
				max_i = i ;
			}
		}

		stack<int> lay_out ;

		while( max_i != -1 )
		{
			lay_out.push( max_i ) ;
			max_i = box_list[max_i].pre ;
		}
		
		if(flag)
			cout << endl ;

		flag = true ;

		cout << lay_out.size() << endl ;

		while( !lay_out.empty() )
		{
			cout << box_list[lay_out.top()].num  ;
			if( lay_out.size()!=1)
				cout << ' ' ;
			lay_out.pop() ;
		}

	}
	return 0 ;
}
